#include "lexiq.h"
#include "ft_str.h"
#include "ft_mem.h"

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
	eng.master_groups_head = &eng.groups_head;
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
