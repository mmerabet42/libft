/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 19:20:49 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/27 18:42:15 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexiq.h"
#include "ft_str.h"
#include "ft_types.h"

static int	get_group(t_lq_eng *lqeng, t_lq_eng *tmp, t_list *lst)
{
	int				id;
	const char		*id_str;
	t_lq_group		*group;

	id = 0;
	tmp->id = &id;
	tmp->id_str = &id_str;
	group = (t_lq_group *)lst->content;
	tmp->groups = &group->groups;
	tmp->free_groups = NULL;
	if ((group->len = lq_exec2(tmp)) == -1)
	{
		if (lst->parent)
			lst->parent->next = NULL;
		else
			*lqeng->groups = NULL;
		return (-1);
	}
	group->id = id;
	group->id_str = id_str;
	group->str_begin = lqeng->str_begin;
	group->str = lqeng->str;
	group->pos = (int)(lqeng->str - lqeng->str_begin);
	if ((lqeng->flags & LQ_ID) && lqeng->id)
		*lqeng->id = group->id;
	return (group->len);
}

int			groups_lq(t_lq_eng *lqeng, t_lq_rule *rule)
{
	t_lq_eng		tmp;
	char			*expr;
	t_list			*lst;

	if (!(lqeng->flags & LQ_GROUP) || !lqeng->groups)
		return (lexiq_lq(lqeng, rule));
	if (!(expr = ft_strndup(rule->arg, rule->len_arg)))
		return (-1);
	if (!(lst = ft_lstalloc(sizeof(t_lq_group), 1)))
		return (-1);
	ft_lstpush_p(lqeng->groups, lst);
	tmp = *lqeng;
	tmp.len = 0;
	tmp.flags &= ~(LQ_POS | LQ_GLOBAL | LQ_UGLOBAL | LQ_INNER_GROUP);
	tmp.flags |= (LQ_END | LQ_ID | LQ_GROUP);
	tmp.expr = expr;
	if ((tmp.len = get_group(lqeng, &tmp, lst)) == -1)
		ft_lstdel(&lst, lq_free_match);
	free(expr);
	return (tmp.len);
}

static int	backreference(const char *str, t_list *groups, int n)
{
	static int		lvl;
	t_lq_group		*grp;
	int				ret;

	if (!groups && !(lvl = 0))
		return (0);
	while (groups && ++lvl)
	{
		grp = (t_lq_group *)groups->content;
		if (lvl == n)
		{
			if (!grp->str || !ft_strnequ(grp->str, str, grp->len))
				return (-2);
			return (grp->len);
		}
		if (grp->groups && (ret = backreference(str, grp->groups, n)) != -1)
			return (ret);
		groups = groups->next;
	}
	return (-1);
}

int			ugroups_lq(t_lq_eng *lqeng, t_lq_rule *rule)
{
	int		n;
	t_list	*head;

	if (!(lqeng->flags & LQ_GROUP) || !lqeng->groups)
		return (-1);
	if (rule->rule[1] == 'L')
		head = *lqeng->groups;
	else
		head = *lqeng->groups_head;
	n = backreference(lqeng->str, head, ft_atoi(rule->arg));
	backreference(NULL, NULL, 0);
	return (n < 0 ? -1 : n);
}
