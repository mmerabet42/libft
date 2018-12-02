/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 20:05:27 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/29 20:18:35 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexiq.h"
#include "ft_str.h"

static int	add_multi_rule(va_list vp)
{
	t_lq_func		*funcs;
	size_t			funcs_len;
	size_t			i;

	if (!(funcs = va_arg(vp, t_lq_func *)))
		return (-1);
	funcs_len = va_arg(vp, size_t);
	i = 0;
	while (i < funcs_len)
	{
		if (ft_lexiq(LQ_ADD | funcs[i].flags, funcs[i].name, funcs[i].expr,
				funcs[i].func, funcs[i].id) == -1)
			return (-1);
		++i;
	}
	return ((int)i);
}

static int	add_rule(t_lq_eng *lqeng, t_list **rules, int flags, va_list vp)
{
	t_lq_func		func;
	t_list			*nw;

	func.name = lqeng->expr;
	func.expr = lqeng->str;
	func.func = va_arg(vp, t_lq_funcptr);
	if (flags & LQ_ID)
		func.id = va_arg(vp, int);
	else
		func.id = (int)ft_lstsize(*rules) + 1;
	func.flags = (flags & ~(LQ_ID | LQ_ADD | LQ_TO));
	if (!(nw = ft_lstnew(&func, sizeof(t_lq_func))))
	{
		va_end(vp);
		return (-1);
	}
	ft_lstpushfront(rules, nw);
	va_end(vp);
	return (func.id);
}

static int	get_rule(t_lq_eng *lqeng, t_list *rules, va_list vp)
{
	int				id;
	t_lq_func		**mem;
	t_lq_func		*rule;

	id = -1;
	mem = NULL;
	if (!lqeng->expr)
		id = va_arg(vp, int);
	if ((mem = va_arg(vp, t_lq_func **)))
		*mem = NULL;
	while (rules)
	{
		rule = (t_lq_func *)rules->content;
		if ((!lqeng->expr && id == rule->id)
				|| (lqeng->expr && ft_strequ(lqeng->expr, rule->name)))
		{
			if (mem)
				*mem = rule;
			return (0);
		}
		rules = rules->next;
	}
	return (-1);
}

int			lq_manage_rules(t_lq_eng *lqeng, t_list **rules, int flags,
					va_list vp)
{
	t_list	**lst;

	if ((flags & LQ_TO) && (lst = va_arg(vp, t_list **)))
		rules = lst;
	if (flags & LQ_IMPORT)
		return (lq_import(lqeng, rules));
	else if (flags & LQ_ADD)
		return (add_rule(lqeng, rules, flags, vp));
	else if (flags & LQ_ADD_MULTI)
		return (add_multi_rule(vp));
	else if (flags & LQ_SET && (lst = va_arg(vp, t_list **)))
		*rules = *lst;
	else if (flags & LQ_GETRULE)
		return (get_rule(lqeng, *rules, vp));
	else if ((flags & LQ_GET) && (lst = va_arg(vp, t_list **)))
		*lst = *rules;
	else if ((flags & LQ_FREE) && (lst = va_arg(vp, t_list **)))
		ft_lstdel(lst, lq_free_match);
	else if ((flags & LQ_FREEGRP) && (lst = va_arg(vp, t_list **)))
		ft_lstdel(lst, lq_free_match);
	else if (flags & LQ_CLEAN)
		ft_lstdel(rules, lq_free_rule);
	va_end(vp);
	return (0);
}
