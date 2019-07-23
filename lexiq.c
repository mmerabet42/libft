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
		if (parser->rule->name[0] == 's')
			ft_printf(" '%s'", parser->arg);
		ft_printf("\n");
		if (eng->i >= parser->min && parser->next)
		{
			if ((ret = lq_run(flags, parser->next, lq_eng_copy(&eng2, eng))) >= 0)
				return tret + ret;
		}
		else if (eng->i >= parser->min && eng->lookahead)
		{
			lq_eng_copy(&eng2, eng);
			eng2.lookahead = NULL;
			eng2.lookahead_ret = NULL;
			if (eng->lookahead && eng->prev_eng && eng->lookahead != eng->prev_eng->lookahead)
			{
				eng2.lookahead = eng->prev_eng->lookahead;
				eng2.lookahead_ret = eng->prev_eng->lookahead_ret;
			}
			if ((ret = lq_run(flags, eng->lookahead, &eng2)) >= 0)
			{
				if (eng->lookahead_ret)
					*eng->lookahead_ret = ret;
				return tret;
			}
		}
		ret = parser->rule->func(parser->arg, eng);
		if (ret <= -1 && eng->i < parser->min)
		{
			if (!parser->next_or)
				return ret;
			eng->str = str;
			lq_eng_copy(&eng2, eng);
			eng2.prev_eng = eng->prev_eng;
			return lq_run(flags, parser->next_or, &eng2);
		}
		else if (ret <= -1 && parser->next)
			return ret;
		else if (ret <= -1)
			return tret;
		tret += ret;
		if (eng->eng_flags & LQ_STOP)
			return tret;
		++eng->i;
		if (eng->str >= eng->str_end)
			break;
		eng->str += ret;
		if (eng->i >= parser->max && parser->max != -1)
			break;
	}
	if ((flags & LQ_END) && !parser->next && !eng->lookahead)
		return tret;
	if ((eng->str < eng->str_end && !parser->next && !eng->lookahead) || eng->i < parser->min)
		return -1;
	lq_printf(eng, "'%s'\n", eng->str);
	if (!parser->next)
	{
		if (eng->lookahead)
		{
			lq_eng_copy(&eng2, eng);
			eng2.lookahead = NULL;
			eng2.lookahead_ret = NULL;
			if (eng->lookahead && eng->prev_eng && eng->lookahead != eng->prev_eng->lookahead)
			{
				eng2.lookahead = eng->prev_eng->lookahead;
				eng2.lookahead_ret = eng->prev_eng->lookahead_ret;
			}
			ret = lq_run(flags, eng->lookahead, &eng2);
			if (eng->lookahead_ret)
				*eng->lookahead_ret = ret;
		}
		return tret;
	}
	if ((ret = lq_run(flags, parser->next, lq_eng_copy(&eng2, eng))) <= -1)
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
	eng.flags = flags;
	eng.eng_flags = 0;
	eng.pos = NULL;
	eng.recur = 0;
	eng.lookahead = NULL;
	eng.lookahead_ret = NULL;
	eng.i = 0;
	if (flags & LQ_RUN)
	{
		parser = eng.parser_begin = va_arg(vp, t_lq_node *);
		eng.str = eng.str_begin = va_arg(vp, const char *);
		if (flags & LQ_STREND)
			eng.str_end = va_arg(vp, const char *);
		else
			eng.str_end = eng.str + strlen(eng.str);
		if (eng.flags & LQ_POS)
			eng.pos = va_arg(vp, int *);
		if (eng.flags & LQ_LOOKAHEAD)
		{
			eng.lookahead_ret = va_arg(vp, int *);
			eng.lookahead = va_arg(vp, t_lq_node *);
		}
		eng.flags &= ~LQ_POS;
		ret = lq_pos(eng.flags, parser, &eng);
	}
	return ret;
}
