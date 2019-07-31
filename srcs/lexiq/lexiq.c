#include "lexiq.h"
#include <stdarg.h>
#include <string.h>

t_lq_eng *lq_eng_copy(t_lq_eng *a, t_lq_eng *b)
{
	a->flags = b->flags;
	a->i = 0;
	a->eng_flags = 0;
	a->str = b->str;
	a->str_begin = b->str_begin;
	a->str_end = b->str_end;
	a->pos = b->pos;
	a->parser_begin = b->parser_begin;
	a->recur = b->recur + 1;
	a->lookahead = b->lookahead;
	a->lookahead_ret = b->lookahead_ret;
	a->prev_eng = b;
	a->parent_eng = b->parent_eng;
	a->groups_head = b->groups_head;
	a->groups = b->groups;
	a->lookahead_ret = 0;
	a->ret_ptr = NULL;
	return a;
}

void lq_printf(t_lq_eng *eng, const char *format, ...)
{
	ft_printf("% *c", eng->recur, ' ');
	va_list ap;
	va_start(ap, format);
	ft_vprintf(format, ap);
}

int get_proper_eng(t_lq_eng *it_eng, t_lq_eng **eng_loop, t_lq_eng **eng_next)
{
	*eng_loop = NULL;
	*eng_next = NULL;
	while (it_eng && (!*eng_next || !*eng_loop))
	{
		if (!*eng_next && !*eng_loop && it_eng->current->min != it_eng->current->max)
			*eng_loop = it_eng;
		if (!*eng_next && it_eng->current->next)
			*eng_next = it_eng;
		it_eng = it_eng->parent_eng;
	}
	if (it_eng)
		return 1;
	return 0;
}

int lq_run(int flags, t_lq_node *parser, t_lq_eng *eng)
{
	int tret;
	int ret;
	const char *str;
	t_lq_eng eng2;
	t_lq_eng *eng_loop;
	t_lq_eng *eng_next;

	tret = 0;
	str = eng->str;
	eng->current = parser;
	while (eng->str <= eng->str_end)
	{
		eng_next = NULL;
		eng_loop = NULL;
		if (eng->i >= parser->min && parser->next)
		{
			if ((ret = lq_run(flags, parser->next, lq_eng_copy(&eng2, eng))) >= 0)
				return tret + ret;
		}
		else if (eng->i >= parser->min)
		{
			lq_eng_copy(&eng2, eng);
			get_proper_eng(eng->parent_eng, &eng_loop, &eng_next);
			if ((eng_loop && eng_loop->i + 1 < eng_loop->current->min)
					|| (!eng_next && eng_loop && eng_loop->i + 1 >= eng_loop->current->min))
			{
				eng2.parent_eng = eng_loop->parent_eng;
				eng2.i = eng_loop->i + 1;
				if ((ret = lq_run(flags, eng_loop->current, &eng2)) >= 0)
				{
					eng_loop->lookahead_ret = ret;
					return tret;
				}
			}
			else if (eng_next)
			{
				eng2.parent_eng = eng_next->parent_eng;
				if ((ret = lq_run(flags, eng_next->current->next, &eng2)) >= 0)
				{
					eng_next->lookahead_ret = ret;
					return tret;
				}
				else if (eng_loop && eng_loop->i + 1 >= eng_loop->current->min)
				{
					eng2.parent_eng = eng_loop->parent_eng;
					eng2.i = eng_loop->i + 1;
					if ((ret = lq_run(flags, eng_loop->current, &eng2)) >= 0)
					{
						eng_loop->lookahead_ret = ret;
						return tret;
					}
				}
			}
		}
		ret = parser->rule->func(parser->arg, eng);
		if (ret <= -1 && eng->i < parser->min)
		{
			if (!parser->next_or)
				return ret;
			eng->str = str;
			lq_eng_copy(&eng2, eng);
			return lq_run(flags, parser->next_or, &eng2);
		}
		else if (ret <= -1 && (parser->next || eng_next))
			return ret;
		else if (ret <= -1)
			return tret;
		tret += ret;
		if ((parser->rule->flags & LQ_STOP))
			return tret;
		++eng->i;
		if (eng->str >= eng->str_end)
			break;
		eng->str += ret;
		if (eng->i >= parser->max && parser->max != -1)
			break;
	}
	if (eng->i < parser->min)
		return -1;
	if ((eng->str < eng->str_end && !parser->next && !eng->lookahead && !(flags & LQ_END)))
		return -1;
	if (!parser->next)
	{
		lq_eng_copy(&eng2, eng);
		ret = get_proper_eng(eng->parent_eng, &eng_loop, &eng_next);
		if (!eng_next && !eng_loop)
		{
			if (flags & LQ_END)
				return tret;
			else
				return -1;
		}
		if ((eng_loop && eng_loop->i + 1 < eng_loop->current->min)
				|| (!eng_next && eng_loop && eng_loop->i + 1 >= eng_loop->current->min))
		{
			eng2.parent_eng = eng_loop->parent_eng;
			eng2.i = eng_loop->i + 1;
			if (eng2.i >= eng_loop->current->max && eng_loop->current->max != -1)
			{
				if (eng->str < eng->str_end && !(flags & LQ_END))
					return -1;
				else if (eng->str < eng->str_end)
					return tret;
			}
			else
				eng_loop->lookahead_ret = lq_run(flags, eng_loop->current, &eng2);
		}
		else if (eng_next)
		{
			eng2.parent_eng = eng_next->parent_eng;
			if ((ret = lq_run(flags, eng_next->current->next, &eng2)) >= 0)
				eng_next->lookahead_ret = ret;
			else if (eng_loop && eng_loop->i + 1 >= eng_loop->current->min)
			{
				eng2.parent_eng = eng_loop->parent_eng;
				eng2.i = eng_loop->i + 1;
				if (eng2.i >= eng_loop->current->max && eng_loop->current->max != -1)
					return -1;	
				if ((ret = lq_run(flags, eng_loop->current, &eng2)) <= -1)
					return ret;
				eng_loop->lookahead_ret = ret;
			}
			else
				return ret;
		}
		return tret;
	}
	else if ((ret = lq_run(flags, parser->next, lq_eng_copy(&eng2, eng))) <= -1)
		return ret;
	return tret + ret;
}

int lq_pos(int flags, t_lq_node *parser, t_lq_eng *eng)
{
	int ret;
	const char *str;

	ret = 0;
	if (!eng->pos)
		return lq_run(flags, parser, eng);
	*eng->pos = 0;
	str = eng->str;
	while ((ret = lq_run(flags, parser, eng)) < 0 && str < eng->str_end)
	{
		eng->i = 0;
		eng->str = ++str;
		++(*eng->pos);
	//	ft_printf("moving %d!\n", *eng->pos);
	}
	return ret;
}

int lexiq(int flags, ...)
{
	va_list vp;
	int ret;
	t_lq_eng eng;
	t_lq_node *parser;

	va_start(vp, flags);
	memset(&eng, 0, sizeof(t_lq_eng));
	eng.flags = flags;
	ret = -1;
	if (flags & LQ_RUN)
	{
		parser = eng.parser_begin = va_arg(vp, t_lq_node *);
		eng.str = eng.str_begin = va_arg(vp, const char *);
		if (flags & LQ_STREND)
			eng.str_end = va_arg(vp, const char *);
		else
			eng.str_end = eng.str + strlen(eng.str);
		if (flags & LQ_POS)
			eng.pos = va_arg(vp, int *);
		if (flags & LQ_GROUPS)
			eng.groups = va_arg(vp, t_lq_list **);
		eng.flags &= ~LQ_POS;
		ret = lq_pos(eng.flags, parser, &eng);
	}
	return ret;
}
