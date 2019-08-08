#include "lexiq.h"
#include "ft_str.h"
#include "ft_mem.h"

void subtract_tret(t_lq_eng *it_eng, int tret)
{
	int *last_len;
	t_lq_eng *eng_loop;
	t_lq_eng *eng_next;

	eng_loop = NULL;
	eng_next = NULL;
	if ((last_len = it_eng->len_ptr))
		*last_len -= tret;
	it_eng = it_eng->parent_eng;
	while (it_eng && (!eng_next || !eng_loop))
	{
		if (it_eng->len_ptr != last_len)
		{
			if ((last_len = it_eng->len_ptr))
				*it_eng->len_ptr -= tret;
		}
		if (!eng_next && !eng_loop
				&& get_min(it_eng) != get_max(it_eng)
				&& (get_max(it_eng) == -1
					|| (it_eng->i + 1 < get_max(it_eng)
						&& get_max(it_eng) != -1)))
			eng_loop = it_eng;
		if (!eng_next && it_eng->current->next)
			eng_next = it_eng;
		it_eng = it_eng->parent_eng;
	}
}

int get_proper_eng(t_lq_eng *it_eng, t_lq_eng **eng_loop, t_lq_eng **eng_next, int tret)
{
	int *last_len;
	int eng_tret;

	*eng_loop = NULL;
	*eng_next = NULL;
	eng_tret = tret;
	if ((last_len = it_eng->len_ptr))
	{
		*last_len += tret;
		eng_tret = *last_len;
	}
	it_eng = it_eng->parent_eng;
	while (it_eng && (!*eng_next || !*eng_loop))
	{
		if (it_eng->len_ptr != last_len)
		{
			if ((last_len = it_eng->len_ptr))
				*it_eng->len_ptr += eng_tret;
		}
		if (!*eng_next && !*eng_loop
				&& get_min(it_eng) != get_max(it_eng)
				&& (get_max(it_eng) == -1
					|| (it_eng->i + 1 < get_max(it_eng)
						&& get_max(it_eng) != -1)))
			*eng_loop = it_eng;
		if (!*eng_next && it_eng->current->next)
			*eng_next = it_eng;
		it_eng = it_eng->parent_eng;
	}
	return (it_eng ? 1 : 0);
}

void proper_copy(t_lq_eng *a, t_lq_eng *b, int increment_i)
{
	a->len_ptr = NULL;
	a->current_group = NULL;
	if ((a->parent_eng = b->parent_eng))
	{
		a->len_ptr = b->parent_eng->len_ptr;
		a->current_group = b->parent_eng->current_group;
	}
	a->groups = b->groups;
	a->groups_head = b->groups_head;
	if (increment_i)
		a->i = b->i + 1;
}

int exec_lookahead1(t_lq_eng *eng, t_lq_eng *eng2, t_lq_eng **eng_next, int tret)
{
	t_lq_eng *eng_loop;
	int ret;

	eng_loop = NULL;
	lq_eng_copy(eng2, eng);
	get_proper_eng(eng, &eng_loop, eng_next, tret);
	if ((eng_loop && eng_loop->i + 1 < get_min(eng_loop))
			|| (!*eng_next && eng_loop && eng_loop->i + 1 >= get_min(eng_loop)))
	{
		proper_copy(eng2, eng_loop, 1);
		if ((ret = lq_run(eng_loop->current, eng2)) >= 0)
		{
			eng_loop->lookahead_ret = ret;
			return tret;
		}
	}
	else if (*eng_next)
	{
		proper_copy(eng2, *eng_next, 0);
		if ((ret = lq_run((*eng_next)->current->next, eng2)) >= 0)
		{
			(*eng_next)->lookahead_ret = ret;
			return tret;
		}
		else if (eng_loop && eng_loop->i + 1 >= get_min(eng_loop))
		{
			proper_copy(eng2, eng_loop, 1);
			if ((ret = lq_run(eng_loop->current, eng2)) >= 0)
			{
				eng_loop->lookahead_ret = ret;
				return tret;
			}
		}
	}
	subtract_tret(eng, tret);
	return -1;
}

int exec_lookahead2(t_lq_eng *eng, t_lq_eng *eng2, int tret)
{
	int ret;
	t_lq_eng *eng_next;
	t_lq_eng *eng_loop;

	lq_eng_copy(eng2, eng);
	get_proper_eng(eng, &eng_loop, &eng_next, tret);
	if (!eng_next && !eng_loop)
		return ((eng->flags & LQ_END) || eng->str >= eng->str_end ? tret : -1);
	if ((eng_loop && eng_loop->i + 1 < get_min(eng_loop))
			|| (!eng_next && eng_loop && eng_loop->i + 1 >= get_min(eng_loop)))
	{
		proper_copy(eng2, eng_loop, 1);
		eng_loop->lookahead_ret = lq_run(eng_loop->current, eng2);
	}
	else if (eng_next)
	{
		proper_copy(eng2, eng_next, 0);
		if ((ret = lq_run(eng_next->current->next, eng2)) >= 0)
			eng_next->lookahead_ret = ret;
		else if (eng_loop && eng_loop->i + 1 >= get_min(eng_loop))
		{
			proper_copy(eng2, eng_loop, 1);
			if ((ret = lq_run(eng_loop->current, eng2)) <= -1)
			{
				subtract_tret(eng, tret);
				return ret;
			}
			eng_loop->lookahead_ret = ret;
		}
		else
		{
			subtract_tret(eng, tret);
			return ret;
		}
	}
	return tret;
}

int exec_next(t_lq_eng *eng, t_lq_eng *eng2, int tret)
{
	int ret;

	if (eng->len_ptr)
		*eng->len_ptr += tret;
	lq_eng_copy(eng2, eng);
	if (eng->parent_eng)
		eng2->current_group = eng->parent_eng->current_group;
	if ((ret = lq_run(eng->current->next, eng2)) >= 0)
		return tret + ret;
	if (eng->len_ptr)
		*eng->len_ptr -= tret;
	return -1;
}

int exec_or(t_lq_eng *eng, t_lq_eng *eng2, int ret)
{
	if (!eng->current->next_or)
		return ret;
	eng->str = eng->str_p;
	lq_eng_copy(eng2, eng);
	return lq_run(eng->current->next_or, eng2);
}

int exec_optional(t_lq_eng *eng, t_lq_eng *eng2, t_lq_eng **eng_next, int tret)
{
	int ret;

	*eng_next = NULL;
	if (eng->i >= get_min(eng) && eng->current->next)
	{
		if ((ret = exec_next(eng, eng2, tret)) >= 0)
			return ret;
	}
	else if (eng->i >= get_min(eng))
	{
		if ((ret = exec_lookahead1(eng, eng2, eng_next, tret)) >= 0)
			return ret;
	}
	return -1;
}

int lq_run(t_lq_node *parser, t_lq_eng *eng)
{
	int ret;
	int ret2;
	t_lq_eng eng2;
	t_lq_eng *eng_next;

	ret = 0;	
	eng->current = parser;
	if (eng->i >= get_max(eng) && get_max(eng) != -1)
	{
		if (!parser->next)
			return (exec_lookahead2(eng, &eng2, 0));
		return (exec_next(eng, &eng2, 0));		
	}
	if (eng->current_group && (parser->rule->flags & LQ_SAVE_RULE_NAME))
		eng->current_group->rule_name = parser->rule->name;
	if (parser->rule->func)
		ret = parser->rule->func(parser->arg, eng);
	else if (parser->rule->parser)
	{
		lq_eng_copy(&eng2, eng);
		eng2.parent_eng = eng;
		ret = lq_run(parser->rule->parser, &eng2);
	}
	if (ret <= -1 && eng->i < get_min(eng))
		return (exec_or(eng, &eng2, ret));
	else if (ret <= -1)
	{
		if ((ret2 = exec_optional(eng, &eng2, &eng_next, 0)) >= 0)
			return (ret2);
		if (parser->next || eng_next)
			return (ret);
		if (eng->str < eng->str_end && !(eng->flags & LQ_END))
			return (ret);
		return (0);
	}
	if ((parser->rule->flags & LQ_STOP))
		return (ret);
	eng->i += 1;
	if (eng->str >= eng->str_end)
	{
		if (eng->i < get_min(eng))
			return (-1);
		if (!parser->next)
			return (exec_lookahead2(eng, &eng2, (ret <= -1 ? 0 : ret)));
		return (exec_next(eng, &eng2, (ret <= -1 ? 0 : ret)));
	}
	eng->str += ret;
	if (eng->len_ptr)
		*eng->len_ptr += ret;
	if (eng->i >= get_max(eng) && get_max(eng) != -1)
	{
		if (!parser->next)
			ret2 = exec_lookahead2(eng, &eng2, 0);
		else
			ret2 = exec_next(eng, &eng2, 0);		
		if (ret2 <= -1)
		{
			eng->str -= ret;
			if (eng->len_ptr)
				*eng->len_ptr -= ret;
		}
		return (ret2 <= -1 ? ret2 : ret + ret2);
	}
	if ((ret2 = lq_run(parser, eng)) >= 0)
		return (ret + ret2);
	if ((ret2 = exec_optional(eng, &eng2, &eng_next, 0)) >= 0)
		return (ret + ret2);
	eng->str -= ret;
	if (eng->len_ptr)
		*eng->len_ptr -= ret;
	return (ret2);	
}
/*
int lq_run(t_lq_node *parser, t_lq_eng *eng)
{
	int tret;
	int ret;
	t_lq_eng eng2;
	t_lq_eng *eng_next;

	tret = 0;
	eng->current = parser;
	while (eng->str <= eng->str_end)
	{
		lq_printf(eng, "|node: '%s' '%s'\n", parser->rule->name, eng->str);
		if ((ret = exec_optional(eng, &eng2, &eng_next, tret)) >= 0)
			return (ret);
		ret = parser->rule->func(parser->arg, eng);
		if (ret <= -1 && eng->i < get_min(eng))
			return (exec_or(eng, &eng2, ret));
		else if (ret <= -1 && (parser->next || eng_next))
			return (ret);
		else if (ret <= -1)
		{
			if (eng->str < eng->str_end && !(eng->flags & LQ_END))
				return (ret);
			if (eng->len_ptr)
				*eng->len_ptr += tret;
			return (tret);
		}
		tret += ret;
		if ((parser->rule->flags & LQ_STOP))
			return (tret);
		++eng->i;
		if (eng->str >= eng->str_end)
			break ;
		eng->str += ret;
		if (eng->i >= get_max(eng) && get_max(eng) != -1)
			break ;
	}
	if (eng->i < get_min(eng))
		return (-1);
	if (!parser->next)
		return (exec_lookahead2(eng, &eng2, tret));
	return (exec_next(eng, &eng2, tret));
}
*/
int lq_pos(t_lq_node *parser, t_lq_eng *eng)
{
	int ret;
	const char *str;

	ret = 0;
	if (!eng->pos)
		return lq_run(parser, eng);
	*eng->pos = 0;
	str = eng->str;
	while ((ret = lq_run(parser, eng)) < 0 && str < eng->str_end)
	{
		eng->i = 0;
		eng->str = ++str;
		++(*eng->pos);
	}
	return ret;
}

static int lexiq_run(int flags, va_list vp)
{
	t_lq_eng eng;
	t_lq_node *parser;
	t_lq_list *groups;
	int vars[LQ_VAR_NUM];

	ft_bzero(&eng, sizeof(t_lq_eng));
	ft_bzero(vars, sizeof(vars));
	eng.flags = flags;
	eng.parser_begin = va_arg(vp, t_lq_node *);
	parser = eng.parser_begin;
	eng.str_begin = va_arg(vp, const char *);
	eng.str = eng.str_begin;
	eng.str_p = eng.str;
	if (flags & LQ_STREND)
		eng.str_end = va_arg(vp, const char *);
	else
		eng.str_end = eng.str + ft_strlen(eng.str);
	if (flags & LQ_POS)
		eng.pos = va_arg(vp, int *);
	if (flags & LQ_GROUPS)
		eng.groups = va_arg(vp, t_lq_list **);
	groups = NULL;
	if (!eng.groups)
		eng.groups = &groups;
	return (lq_pos(parser, &eng));
}

static int lexiq_add(int flags, va_list vp)
{
	const char *name;
	t_lq_func func;
	t_lq_node *parser;

	if (!(name = va_arg(vp, const char *)))
		return (-1);
	if (!(flags & LQ_COMPILE))
	{
		func = NULL;
		parser = NULL;
		if ((flags & LQ_FUNC) && !(func = va_arg(vp, t_lq_func)))
			return (-1);
		else if (!(flags & LQ_FUNC) && !(parser = va_arg(vp, t_lq_node *)))
			return (-1);
		return (lq_add(flags, name, parser, func));
	}
	return (0);
}

int lexiq(int flags, ...)
{
	va_list vp;

	va_start(vp, flags);
	if (flags & LQ_RUN)
		return (lexiq_run(flags, vp));
	else if (flags & LQ_ADD)
		return (lexiq_add(flags, vp));
	return (-1);
}
