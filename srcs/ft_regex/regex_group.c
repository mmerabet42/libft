/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_function4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 19:20:49 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/14 18:25:46 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"
#include "ft_str.h"
#include "ft_types.h"

static int	get_group(t_regex_info *rgxi, t_regex_info *tmp, t_list *lst)
{
	int				id;
	t_regex_group	*group;

	id = 0;
	tmp->id = &id;
	group = (t_regex_group *)lst->content;
	tmp->groups = &group->groups;
	tmp->free_groups = NULL;
	if ((group->len = regex_exec2(tmp)) == -1)
	{
		if (lst->parent)
			lst->parent->next = NULL;
		else
			*rgxi->groups = NULL;
		return (-1);
	}
	group->id = id;
	group->str_begin = rgxi->str_begin;
	group->str = rgxi->str;
	group->pos = (int)(rgxi->str - rgxi->str_begin);
	if ((rgxi->flags & RGX_ID) && rgxi->id)
		*rgxi->id = group->id;
	return (group->len);
}

int			groups_rgx(t_regex_info *rgxi, t_regex_rule *rule)
{
	t_regex_info	tmp;
	char			*rgx;
	t_list			*lst;

	if (!(rgxi->flags & RGX_GROUP) || !rgxi->groups)
		return (regex_rgx(rgxi, rule));
	if (!(rgx = ft_strndup(rule->arg, rule->len_arg)))
		return (-1);
	if (!(lst = ft_lstalloc(sizeof(t_regex_group), 1)))
		return (-1);
	ft_lstpush_p(rgxi->groups, lst);
	tmp = *rgxi;
	tmp.len = 0;
	tmp.flags &= ~(RGX_POS | RGX_GLOBAL | RGX_UGLOBAL | RGX_INNER_GROUP);
	tmp.flags |= (RGX_END | RGX_ID | RGX_GROUP);
	tmp.regex = rgx;
	if ((tmp.len = get_group(rgxi, &tmp, lst)) == -1)
		ft_lstdel(&lst, free_match);
	free(rgx);
	return (tmp.len);
}

static int	backreference(const char *str, t_list *groups, int n)
{
	static int		lvl;
	t_regex_group	*grp;
	int				ret;

	if (!groups && !(lvl = 0))
		return (0);
	while (groups && ++lvl)
	{
		grp = (t_regex_group *)groups->content;
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

int			ugroups_rgx(t_regex_info *rgxi, t_regex_rule *rule)
{
	int		n;
	t_list	*head;

	if (!(rgxi->flags & RGX_GROUP) || !rgxi->groups)
		return (-1);
	if (rule->rule[1] == 'L')
		head = *rgxi->groups;
	else
		head = *rgxi->groups_head;
	n = backreference(rgxi->str, head, ft_atoi(rule->arg));
	backreference(NULL, NULL, 0);
	return (n < 0 ? -1 : n);
}
