/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_function4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 19:20:49 by mmerabet          #+#    #+#             */
/*   Updated: 2018/10/29 19:29:48 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"
#include "ft_str.h"
#include <stdlib.h>

static int	get_group(t_regex_info *rgxi, t_regex_info *tmp, t_regex_group *group)
{
	int		ret;
	int		id;
	t_list	*lst;
	t_list	*grps;

	if (!(lst = ft_lstcreate(group, sizeof(t_regex_group))))
		return (-1);
	ft_lstpush_p(rgxi->groups, lst);
	id = 0;
	tmp->id = &id;
	grps = NULL;
	tmp->groups = &grps;
	if ((ret = regex_exec(tmp)) == -1)
		return (-1);
	ft_lstpush_p(rgxi->groups, *tmp->groups);
	group->id = id;
	group->len = ret;
	group->str_begin = rgxi->str_begin;
	group->str = rgxi->str;
	group->pos = (int)(rgxi->str - rgxi->str_begin);
	if ((rgxi->flags & RGX_ID) && rgxi->id)
		*rgxi->id = group->id;
	return (group->len);
}

int	groups_rgx(t_regex_info *rgxi, t_regex_rule *rule)
{
	t_regex_info	tmp;
	t_regex_group	*group;
	char			*rgx;

	if (!(rgxi->flags & RGX_GROUP) || !rgxi->groups)
		return (regex_rgx(rgxi, rule));
	if (!(rgx = ft_strndup(rule->arg, rule->len_arg)))
		return (-1);
	if (!(group = (t_regex_group *)malloc(sizeof(t_regex_group))))
		return (-1);
	tmp = *rgxi;
	tmp.len = 0;
	tmp.flags &= ~(RGX_POS | RGX_GLOBAL | RGX_UGLOBAL);
	tmp.flags |= RGX_END | RGX_ID | RGX_GROUP;
	tmp.regex = rgx;
	tmp.rgx_begin = rgx;
	if ((tmp.len = get_group(rgxi, &tmp, group)) == -1)
		ft_lstdel(rgxi->groups, content_delfunc);
	free(rgx);
	return (tmp.len);
}
