/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matches.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 17:43:10 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/27 17:39:59 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"
#include "ft_mem.h"

static int	add_matches(t_regex_info *rgxi, t_regex_match *matchs, int zero)
{
	int	i;

	i = 0;
	if ((rgxi->flags & RGX_UGLOBAL) && matchs[0].pos)
	{
		matchs[1].len = matchs[0].pos + (zero ? 1 : 0);
		matchs[1].str = matchs[1].str_begin + matchs[1].pos;
		matchs[1].id = -1;
		matchs[1].id_str = NULL;
		matchs[1].groups = NULL;
		if (rgxi->matches)
			ft_lstpush_p(rgxi->matches,
					ft_lstnew(&matchs[1], sizeof(t_regex_match)));
		++i;
	}
	matchs[0].pos += matchs[1].pos;
	if (rgxi->flags & RGX_GLOBAL)
	{
		matchs[0].str = matchs[0].str_begin + matchs[0].pos;
		if (rgxi->matches)
			ft_lstpush_p(rgxi->matches,
					ft_lstnew(&matchs[0], sizeof(t_regex_match)));
		matchs[0].id = 0;
		matchs[0].id_str = NULL;
		++i;
	}
	return (i);
}

static int	loop_matches(t_regex_info *rgxi, t_regex_match *matchs)
{
	int		i;
	int		zero;
	t_list	*groups;

	i = 0;
	zero = 0;
	groups = NULL;
	rgxi->groups = &groups;
	rgxi->free_groups = rgxi->groups;
	rgxi->groups_head = rgxi->groups;
	while ((matchs[0].len = regex_pos(rgxi)) != -1)
	{
		matchs[0].groups = groups;
		groups = NULL;
		i += add_matches(rgxi, matchs, zero);
		zero = (!matchs[0].len ? 1 : 0);
		matchs[1].pos = matchs[0].pos + (!matchs[0].len ? 1 : matchs[0].len);
		if (!*(matchs[0].str_begin + matchs[0].pos)
				|| !*(rgxi->str = matchs[0].str_begin + matchs[1].pos))
			break ;
		rgxi->regex = rgxi->rgx_begin;
		rgxi->len = 0;
	}
	return (i);
}

int			get_matches(t_regex_info *rgxi)
{
	t_regex_match	matchs[2];
	int				i;

	rgxi->flags |= (RGX_POS | RGX_END | RGX_IDSTR | RGX_GROUP);
	rgxi->pos = &(matchs[0].pos);
	rgxi->id = &(matchs[0].id);
	rgxi->id_str = &(matchs[0].id_str);
	matchs[1].groups = NULL;
	matchs[0].str_begin = rgxi->str;
	matchs[1].str_begin = rgxi->str;
	if (rgxi->matches)
		*rgxi->matches = NULL;
	i = 0;
	matchs[1].pos = 0;
	i = loop_matches(rgxi, matchs);
	if ((rgxi->flags & RGX_UGLOBAL) && matchs[0].len == -1)
	{
		matchs[1].len = matchs[0].pos;
		matchs[1].str = matchs[0].str_begin + matchs[1].pos;
		matchs[1].id = -1;
		matchs[1].id_str = NULL;
		if (rgxi->matches)
			ft_lstpush_p(rgxi->matches,
					ft_lstnew(&matchs[1], sizeof(t_regex_match)));
		++i;
	}
	return (i);
}
