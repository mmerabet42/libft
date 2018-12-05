/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:33:56 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/08 20:35:52 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexiq.h"
#include "ft_str.h"
#include "ft_mem.h"
#include "ft_types.h"

static void	fill_info(t_lq_eng *lqeng, t_lq_rule *r, int jmp, int ret)
{
	if ((lqeng->flags & LQ_READABLE) && ft_isspace(*lqeng->expr))
		while (ft_isspace(*lqeng->expr))
			++lqeng->expr;
	if (r->len_arg < 0 && (r->rule = "DEFAULT"))
		r->len_arg = jmp - ret - (ret - (r->neg ? 2 : 1)) - r->cond;
	else
	{
		r->len_arg -= r->cond;
		r->rule = r->arg + r->len_arg + 1;
		r->len_rule = ft_strpbrk_pos(r->rule, "?=><}]");
		r->cond = 0;
		if (r->rule[r->len_rule] == '=')
			r->cond = LQ_EQUAL;
		else if (r->rule[r->len_rule] == '>' || r->rule[r->len_rule] == '<')
			r->cond = (r->rule[r->len_rule] == '>' ? LQ_GREAT : LQ_LESS);
		else if (r->rule[r->len_rule] == '?')
			r->cond = LQ_MARK;
		if (r->rule[r->len_rule] != ']' && r->rule[r->len_rule] != '}')
			r->l = lq_variable(lqeng, r->rule + r->len_rule + 1);
	}
	r->func = lq_get_func(r->rule, r->len_rule, lqeng);
	if (lqeng->id)
		lqeng->cid = *lqeng->id;
}

static int	expanded_wildcard(t_lq_eng *lqeng, char type, int neg)
{
	int				jmp;
	int				ret;
	t_lq_rule		rule;

	if ((jmp = lq_bracket(lqeng->expr, &ret)) != -1)
	{
		rule.type = type;
		rule.neg = neg;
		rule.len_arg = ft_strnrchr_pos(lqeng->expr + ret, '@', jmp - ret);
		rule.cond = 0;
		rule.len_rule = 0;
		if (*(rule.arg = lqeng->expr + ret) == '\\'
				&& (rule.arg[1] == '{' || rule.arg[1] == '\\'))
		{
			rule.cond = 1;
			++rule.arg;
		}
		lqeng->expr += jmp;
		fill_info(lqeng, &rule, jmp, ret);
		if ((ret = lq_start(lqeng, &rule)) == -1 && lqeng->id)
			*lqeng->id = 0;
		return (ret);
	}
	return (-1);
}

static int	lq_mark(t_lq_eng *lqeng)
{
	int	neg;

	neg = 0;
	if (*++lqeng->expr == '!' && *(lqeng->expr + 1) == '[')
	{
		++lqeng->expr;
		neg = 1;
	}
	if (*lqeng->expr == '[' && (lqeng->expr -= (neg ? 2 : 1)))
		return (expanded_wildcard(lqeng, '?', neg));
	if (!*lqeng->str)
		return (-1);
	++lqeng->str;
	++lqeng->len;
	return (0);
}

static int	wildcard_while(t_lq_eng *lqeng)
{
	t_lq_eng		tmp;
	t_list			*end;
	int				ret;

	ret = 0;
	tmp = *lqeng;
	tmp.len = 0;
	if (tmp.groups && (end = ft_lstend(*tmp.groups)))
		tmp.free_groups = &end->next;
	while (*lqeng->str && (ret = lq_exec(&tmp)) == -1)
	{
		++lqeng->len;
		tmp.len = 0;
		tmp.str = ++lqeng->str;
		tmp.expr = lqeng->expr;
	}
	return (ret != -1 ? lqeng->len + ret : 0);
}

int			lq_wildcard(t_lq_eng *lqeng)
{
	int				neg;

	if (!(neg = 0) && *lqeng->expr == '*')
	{
		if (*++lqeng->expr == '!' && lqeng->expr[1] == '[' && ++lqeng->expr)
			neg = 1;
		if (*lqeng->expr == '[' && (lqeng->expr -= (neg ? 2 : 1)))
			return (expanded_wildcard(lqeng, '*', neg));
		if (!*lqeng->expr)
			return (lqeng->len + ft_strlen(lqeng->str));
		return (wildcard_while(lqeng));
	}
	return (lq_mark(lqeng));
}
