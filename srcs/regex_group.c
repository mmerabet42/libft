/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_function4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 19:20:49 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/06 20:01:06 by mmerabet         ###   ########.fr       */
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
		ft_lstdel(&lst, free_group);
	free(rgx);
	return (tmp.len);
}

int			ugroups_rgx(t_regex_info *rgxi, t_regex_rule *rule)
{
	t_list			*it;
	t_regex_group	*grp;
	int				i;
	int				n;

	if (!(rgxi->flags & RGX_GROUP) || !rgxi->groups)
		return (-1);
	n = ft_atoi(rule->arg);
	it = *rgxi->groups_head;
	i = 0;
	while (it)
	{
		if ((grp = it->content) && grp->str && i + 1 == n)
			if (ft_strnequ(grp->str, rgxi->str, grp->len))
				return (grp->len);
		++i;
		it = it->next;
	}
	return (-1);
}
