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
	return a;
}

void lq_printf(t_lq_eng *eng, const char *format, ...)
{
	ft_printf("% *c", eng->recur, ' ');
	va_list ap;
	va_start(ap, format);
	ft_vprintf(format, ap);
}

int lq_run(int flags, t_lq_node *parser, t_lq_eng *eng)
{
	int tret;
	int ret;
	t_lq_eng eng2;
	const char *str;

	tret = 0;
	eng->i = 0;
	str = eng->str;
	eng->current = parser;
	while (eng->str <= eng->str_end)
	{
		lq_printf(eng, "|node: '%s' '%s' %d %d", eng->str, parser->rule->name, parser->min, parser->max);
		if (parser->rule->name[0] == 's' || parser->rule->name[0] == '?' || parser->rule->name[1] == '!')
			ft_printf(" '%s'", parser->arg);
		ft_printf("\n");
		if (eng->i >= parser->min && parser->next)
		{
			if ((ret = lq_run(flags, parser->next, lq_eng_copy(&eng2, eng))) >= 0)
				return tret + ret;
		}
		else if (eng->i >= parser->min)
		{
			lq_eng_copy(&eng2, eng);
			t_lq_eng *eng_next = NULL;
			t_lq_eng *eng_loop = NULL;
			t_lq_eng *it_eng = eng->parent_eng;
			if (eng->parent_eng)
				lq_printf(eng, "|parent_eng: '%s'\n", eng->parent_eng->current->rule->name);
			else
				lq_printf(eng, "|no parent_eng\n");
			while (it_eng && (!eng_next || !eng_loop))
			{
				if (!eng_next && it_eng->current->next)
					eng_next = it_eng;
				if (!eng_next && !eng_loop && it_eng->current->min != it_eng->current->max)
					eng_loop = it_eng;
				it_eng = it_eng->parent_eng;
			}
			if (eng_next)
				lq_printf(eng, "|eng_next: '%s'\n", eng_next->current->next->rule->name);
			if (eng_loop)
				lq_printf(eng, "|eng_loop: '%s'\n", eng_loop->current->rule->name);
			if ((eng_loop && eng_loop->i + 1 < eng_loop->current->min)
					|| (!eng_next && eng_loop && eng_loop->i + 1 >= eng_loop->current->min))
			{
				lq_printf(eng, "|'loop': '%s'", eng_loop->current->rule->name);
				if (eng_next->current->rule->name[0] == 's')
					ft_printf(" '%s'", eng_next->current->arg);
				ft_printf("\n");
				eng2.parent_eng = eng_loop->parent_eng;
				int tmp_i = eng_loop->i++;
				if ((ret = lq_run(flags, eng_loop->current, &eng2)) >= 0)
				{
					eng_loop->lookahead_ret = ret;
					return tret;
				}
				eng_loop->i = tmp_i;
			}
			else if (eng_next)
			{
				lq_printf(eng, "|'next': '%s'", eng_next->current->next->rule->name);
				if (eng_next->current->next->rule->name[0] == 's')
					ft_printf(" '%s'", eng_next->current->next->arg);
				ft_printf("\n");
				eng2.parent_eng = eng_next->parent_eng;
				if ((ret = lq_run(flags, eng_next->current->next, &eng2)) >= 0)
				{
					eng_next->lookahead_ret = ret;
					return tret;
				}
				else if (eng_loop && eng_loop->i + 1 >= eng_loop->current->min)
				{
					eng2.parent_eng = eng_loop->parent_eng;
					int tmp_i = eng_loop->i++;
					if ((ret = lq_run(flags, eng_loop->current, &eng2)) >= 0)
					{
						eng_loop->lookahead_ret = ret;
						return tret;
					}
					eng_loop->i = tmp_i;
				}
			}
		}
		ret = parser->rule->func(parser->arg, eng);
		lq_printf(eng, "|node ret: %d\n", ret);
		if (ret <= -1 && eng->i < parser->min)
		{
			if (!parser->next_or)
				return ret;
			eng->str = str;
			lq_eng_copy(&eng2, eng);
			return lq_run(flags, parser->next_or, &eng2);
		}
		else if (ret <= -1 && parser->next)
			return ret;
		else if (ret <= -1)
		{
			lq_printf(eng, "oook\n");
			return tret;
		}
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
		t_lq_eng *eng_next = NULL;
		t_lq_eng *eng_loop = NULL;
		t_lq_eng *it_eng = eng->parent_eng;
		if (eng->parent_eng)
			lq_printf(eng, "|parent_eng: '%s'\n", eng->parent_eng->current->rule->name);
		else
			lq_printf(eng, "|no parent_eng\n");
		while (it_eng && (!eng_next || !eng_loop))
		{
			if (!eng_next && !eng_loop && it_eng->current->min != it_eng->current->max)
				eng_loop = it_eng;
			if (!eng_next && it_eng->current->next)
				eng_next = it_eng;
			it_eng = it_eng->parent_eng;
		}
		if (!it_eng && !eng_next && !eng_loop)
		{
			if (flags & LQ_END)
				return tret;
			else
				return -1;
		}
		if (eng_next)
			lq_printf(eng, "|eng_next: '%s'\n", eng_next->current->next->rule->name);
		if (eng_loop)
			lq_printf(eng, "|eng_loop: '%s'\n", eng_loop->current->rule->name);
		if ((eng_loop && eng_loop->i + 1 < eng_loop->current->min)
				|| (!eng_next && eng_loop && eng_loop->i + 1 >= eng_loop->current->min))
		{
			lq_printf(eng, "|'loop': '%s'", eng_loop->current->rule->name);
			if (eng_next->current->rule->name[0] == 's')
				ft_printf(" '%s'", eng_next->current->arg);
			ft_printf("\n");
			eng2.parent_eng = eng_loop->parent_eng;
			++eng_loop->i;
			eng_loop->lookahead_ret = lq_run(flags, eng_loop->current, &eng2);
		}
		else if (eng_next)
		{
			lq_printf(eng, "|'next': '%s'", eng_next->current->next->rule->name);
			if (eng_next->current->next->rule->name[0] == 's')
				ft_printf(" '%s'", eng_next->current->next->arg);
			ft_printf("\n");
			eng2.parent_eng = eng_next->parent_eng;
			if ((ret = lq_run(flags, eng_next->current->next, &eng2)) >= 0)
				eng_next->lookahead_ret = ret;
			else if (eng_loop && eng_loop->i + 1 >= eng_loop->current->min)
			{
				lq_printf(eng, "|trying loop\n");
				eng2.parent_eng = eng_loop->parent_eng;
				++eng_loop->i;
				if ((ret = lq_run(flags, eng_loop->current, &eng2)) <= -1)
					return ret;
				eng_loop->lookahead_ret = ret;
			}
			else
				return ret;
			lq_printf(eng, "|ret: %d\n", eng_next->lookahead_ret);
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
		eng->str = ++str;
		++(*eng->pos);
		ft_printf("moving %d!\n", *eng->pos);
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
	eng.eng_flags = 0;
	eng.pos = NULL;
	eng.recur = 0;
	eng.lookahead = NULL;
	eng.lookahead_ret = 0;
	eng.groups = NULL;
	eng.groups_head = NULL;
	eng.prev_eng = NULL;
	eng.parent_eng = NULL;
	eng.i = 0;
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
	//	if (flags & LQ_LOOKAHEAD)
	//	{
	//		eng.lookahead_ret = va_arg(vp, int *);
	//		eng.lookahead = va_arg(vp, t_lq_node *);
	//	}
		if (flags & LQ_GROUPS)
			eng.groups = va_arg(vp, t_lq_list **);
		eng.flags &= ~LQ_POS;
		ret = lq_pos(eng.flags, parser, &eng);
	}
	return ret;
}
