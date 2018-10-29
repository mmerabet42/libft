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

int	groups_rgx(t_regex_info *rgxi, t_regex_rule *rule)
{
	int				ret;
	t_regex_info	tmp;
	t_regex_group	group;
	char			*rgx;

	if (!(rgxi->flags & RGX_GROUPS))
		return (-1);
	if (!(rgx = ft_strndup(rule->arg, rule->len_arg)))
		return (-1);
	tmp = *rgxi;
	tmp.flags = (RGX_ID | RGX_POS | RGX_END | (rgxi->flags & RGX_READABLE));
	tmp->regex = rgx;
	tmp->rgx_begin = rgx;
	tmp->pos = &group->pos;
	tmp->id = &group->id;
	group.len = regex_pos(&tmp);
	group.pos += (int)(rgxi->str - rgxi->str_begin);
}
