/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_function4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 19:20:49 by mmerabet          #+#    #+#             */
/*   Updated: 2018/10/31 15:56:44 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"
#include "ft_str.h"
#include "ft_types.h"
#include <stdlib.h>

static t_regex_group	*add_group(t_regex_info *rgxi, t_list *end)
{
	t_list			*lst;
	t_regex_group	group;

	if (!(lst = ft_lstnew(&group, sizeof(t_regex_group))))
		return (NULL);
	if ((end = ft_lstend(*rgxi->groups)))
	{
		if ((lst->next = end->next))
			lst->next->parent = lst->next;
		end->next = lst;
		lst->parent = end;
	}
	else
		*rgxi->groups = lst;
	return ((t_regex_group *)lst->content);
}

static int				get_group(t_regex_info *rgxi, t_regex_info *tmp)
{
	int				ret;
	int				id;
	t_list			*end;
	t_regex_group	*group;

	id = 0;
	tmp->id = &id;
	if (tmp->groups && (end = ft_lstend(*tmp->groups)))
		tmp->free_groups = &end->next;
	if ((ret = regex_exec(tmp)) == -1 || !(group = add_group(rgxi, end)))
		return (-1);
	group->id = id;
	group->len = ret;
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

	if (!(rgxi->flags & RGX_GROUP) || !rgxi->groups)
		return (regex_rgx(rgxi, rule));
	if (!(rgx = ft_strndup(rule->arg, rule->len_arg)))
		return (-1);
	tmp = *rgxi;
	tmp.len = 0;
	tmp.flags &= ~(RGX_POS | RGX_GLOBAL | RGX_UGLOBAL);
	tmp.flags |= (RGX_END | RGX_ID | RGX_GROUP);
	tmp.regex = rgx;
	if ((tmp.len = get_group(rgxi, &tmp)) == -1)
		ft_lstdel(rgxi->free_groups, content_delfunc);
	free(rgx);
	return (tmp.len);
}

int	ugroups_rgx(t_regex_info *rgxi, t_regex_rule *rule)
{
	t_list			*it;
	t_regex_group	*grp;
	int				i;
	int				n;

	if (!(rgxi->flags & RGX_GROUP) || !rgxi->groups)
		return (-1);
	n = ft_atoi(rule->arg);
	it = *rgxi->groups;
	i = 0;
	while (it)
	{
		if ((grp = it->content) && i == n)
			if (ft_strnequ(grp->str, rgxi->str, grp->len))
				return (grp->len);
		++i;
		it = it->next;
	}
	return (-1);
}
