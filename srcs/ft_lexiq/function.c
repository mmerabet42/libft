/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:31:44 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/29 20:26:57 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexiq.h"
#include "ft_str.h"
#include "ft_math.h"

static int			default_lq(t_lq_eng *lqeng, t_lq_rule *rule)
{
	int	i;

	i = 0;
	while (i < rule->len_arg)
	{
		if (i + 2 < rule->len_arg && rule->arg[i + 1] == '-')
		{
			if (*lqeng->str >= rule->arg[i] && *lqeng->str <= rule->arg[i + 2])
				return (1);
			i += 2;
		}
		else if (*lqeng->str == rule->arg[i])
			return (1);
		++i;
	}
	if (!i)
		return (1);
	return (-1);
}

static int			other_lq(t_lq_eng *lqeng, t_lq_rule *rule)
{
	t_lq_eng	lqeng2;

	lqeng2 = *lqeng;
	lqeng2.expr = rule->func->expr;
	lqeng2.expr_begin = rule->func->expr;
	lqeng2.len = 0;
	lqeng2.flags &= ~(LQ_POS | LQ_GLOBAL | LQ_UGLOBAL | LQ_INNER_GROUP);
	lqeng2.flags &= ~(LQ_READABLE);
	lqeng2.flags |= LQ_END | rule->func->flags;
	lqeng2.param = rule->arg;
	lqeng2.len_param = rule->len_arg;
	lqeng2.id = NULL;
	if (lqeng->cid == -2)
	{
		lqeng2.id = lqeng->id;
		lqeng2.id_str = lqeng->id_str;
	}
	return (lq_exec2(&lqeng2));
}

int					lexiq_lq(t_lq_eng *lqeng, t_lq_rule *rule)
{
	char			*str;
	int				ret;
	t_lq_eng		lqeng2;

	if (!(str = ft_strndup(rule->arg, rule->len_arg)))
		return (-1);
	lqeng2 = *lqeng;
	lqeng2.len = 0;
	lqeng2.flags &= ~(LQ_POS | LQ_GLOBAL | LQ_UGLOBAL | LQ_INNER_GROUP);
	lqeng2.flags |= LQ_END;
	lqeng2.expr = str;
	lqeng2.expr_begin = str;
	ret = lq_exec(&lqeng2);
	free(str);
	if (*rule->rule == ',' || *rule->rule == ';')
	{
		if (*rule->rule == ',' && ret != -1)
			lqeng->str += ret;
		return (ret == -1 ? -1 : 0);
	}
	else if (*rule->rule == '!')
		return (ret == -1 ? 1 : -1);
	return (ret);
}

static t_lq_func	g_lq_funcs[] = {
	{"DEFAULT", NULL, default_lq, 0, 0},
	{"OTHER", NULL, other_lq, 0, 0},
	{"^", NULL, delim_lq, 0, 0},
	{"$", NULL, delim_lq, 0, 0},
	{"^n", NULL, delim_lq, 0, 0},
	{"$n", NULL, delim_lq, 0, 0},
	{"^w", NULL, bnd_lq, 0, 0},
	{"$w", NULL, bnd_lq, 0, 0},
	{"or", NULL, cond_lq, 0, 0},
	{"and", NULL, cond_lq, 0, 0},
	{"ror", NULL, cond_lq, 0, 0},
	{"!", NULL, lexiq_lq, 0, 0},
	{",", NULL, lexiq_lq, 0, 0},
	{";", NULL, lexiq_lq, 0, 0},
	{"R", NULL, recursive_lq, 0, 0},
	{"E", NULL, expr_lq, 0, 0},
	{"G", NULL, groups_lq, 0, 0},
	{"X", NULL, lexiq_lq, 0, 0},
	{"B", NULL, ugroups_lq, 0, 0},
	{"BL", NULL, ugroups_lq, 0, 0},
	{"0", NULL, delim_lq, 0, 0},

	{"upper", "?[A-Z]", NULL, 0, 0},
	{"lower", "?[a-z]", NULL, 0, 0},
	{"digit", "?[0-9]", NULL, 0, 0},
	{"xdigit", "?[A-Fa-f0-9]", NULL, 0, 0},
	{"alpha", "?[a-zA-Z]", NULL, 0, 0},
	{"alnum", "?[a-zA-Z0-9]", NULL, 0, 0},
	{"punct", "?[{-!\"#\\$%&'()*+,./:;<=>?[]^_`{|}~@@}]", NULL, 0, 0},
	{"word", "?[a-zA-Z0-9_]", NULL, 0, 0},
	{"space", "?[ \f\n\t\r\v]", NULL, 0, 0},
	{"blank", "?[ \t]", NULL, 0, 0},
	{"graph", "?[\x21-\x7e]", NULL, 0, 0},
	{"print", "?[\x20-\x7e]", NULL, 0, 0},
	{"int", "*[@space?]?[+-@?]*[0-9]", NULL, 0, 0},
	{"nint", "?[+-@?]*[0-9]", NULL, 0, 0},
	{"uint", "*[@space?]*[0-9]", NULL, 0, 0},
	{"nuint", "*[0-9]", NULL, 0, 0},
	{"getint", NULL, getint_lq, 0, 0},
	{"ngetint", NULL, getint_lq, 0, 0},

	{"true", NULL, write_lq, 0, 0},
	{"false", NULL, write_lq, 0, 0},
	{"write", NULL, write_lq, 0, 0},
	{"case", NULL, case_lq, 0, 0},
	{"debug", NULL, write_lq, 0, 0},
	{"%", NULL, modulus_lq, 0, 0},
	{"set%", NULL, modulus_lq, 0, 0},
	{"equ", "?[@%]", NULL, 0, 0},
	{"inf", "?[@inf]", NULL, 0, 0},
};
static size_t		g_lq_len = (sizeof(g_lq_funcs) / sizeof(t_lq_func));

static t_lq_func	*lq_get_rule(const char *name, int len_rule,
						t_lq_eng *lqeng)
{
	t_list			*rules;
	t_lq_func		*func;
	int				len;

	rules = NULL;
	ft_lexiq(LQ_GET, NULL, NULL, &rules);
	while (rules)
	{
		func = (t_lq_func *)rules->content;
		len = ft_strlen(func->name);
		if (ft_strnequ(name, func->name, ft_max(len_rule, len)))
		{
			if (lqeng && lqeng->id)
			{
				*lqeng->id = func->id;
				if (lqeng->id_str)
					*lqeng->id_str = func->name;
			}
			return (func);
		}
		rules = rules->next;
	}
	return (NULL);
}

t_lq_func			*lq_get_func(const char *name, int len_rule,
						t_lq_eng *lqeng)
{
	size_t	i;
	int		len;

	if (!len_rule || !name || !*name)
		return (lq_get_func("DEFAULT", 7, lqeng));
	i = 0;
	while (i < g_lq_len)
	{
		len = ft_strlen(g_lq_funcs[i].name);
		if (ft_strnequ(name, g_lq_funcs[i].name, ft_max(len_rule, len)))
		{
			if (lqeng && lqeng->id)
			{
				*lqeng->id = g_lq_funcs[i].id;
				if (lqeng->id_str)
					*lqeng->id_str = g_lq_funcs[i].name;
			}
			return (&g_lq_funcs[i]);
		}
		++i;
	}
	return (lq_get_rule(name, len_rule, lqeng));
}
