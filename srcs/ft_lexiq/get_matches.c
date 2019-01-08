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

#include "ft_lexiq.h"
#include "ft_mem.h"

static int	add_matches(t_lq_eng *lqeng, t_lq_match *matchs, int zero)
{
	int	i;

	i = 0;
	if ((lqeng->flags & LQ_UGLOBAL) && matchs[0].pos)
	{
		matchs[1].len = matchs[0].pos + (zero ? 1 : 0);
		matchs[1].str = matchs[1].str_begin + matchs[1].pos;
		matchs[1].id = -1;
		matchs[1].id_str = NULL;
		matchs[1].groups = NULL;
		matchs[1].name = NULL;
		if (lqeng->matches)
			ft_lstpush_p(lqeng->matches,
					ft_lstnew(&matchs[1], sizeof(t_lq_match)));
		++i;
	}
	matchs[0].pos += matchs[1].pos;
	if (lqeng->flags & LQ_GLOBAL)
	{
		matchs[0].str = matchs[0].str_begin + matchs[0].pos;
		if (lqeng->matches)
			ft_lstpush_p(lqeng->matches,
					ft_lstnew(&matchs[0], sizeof(t_lq_match)));
		matchs[0].id = 0;
		matchs[0].id_str = NULL;
		matchs[0].name = NULL;
		++i;
	}
	return (i);
}

static int	loop_matches(t_lq_eng *lqeng, t_lq_match *matchs)
{
	int				i;
	int				zero;
	t_lq_list	*groups;

	i = 0;
	zero = 0;
	groups = NULL;
	lqeng->groups = (t_list **)&groups;
	lqeng->free_groups = lqeng->groups;
	lqeng->groups_head = lqeng->groups;
	while ((matchs[0].len = lq_pos(lqeng)) != -1)
	{
		matchs[0].groups = groups;
		groups = NULL;
		i += add_matches(lqeng, matchs, zero);
		zero = (!matchs[0].len ? 1 : 0);
		matchs[1].pos = matchs[0].pos + (!matchs[0].len ? 1 : matchs[0].len);
		if (!*(matchs[0].str_begin + matchs[0].pos)
				|| !*(lqeng->str = matchs[0].str_begin + matchs[1].pos))
			break ;
		lqeng->expr = lqeng->expr_begin;
		lqeng->len = 0;
	}
	return (i);
}

int			lq_get_matches(t_lq_eng *lqeng)
{
	t_lq_match	matchs[2];
	int				i;

	lqeng->flags |= (LQ_POS | LQ_END | LQ_IDSTR | LQ_GROUP);
	lqeng->pos = &(matchs[0].pos);
	lqeng->id = &(matchs[0].id);
	lqeng->id_str = &(matchs[0].id_str);
	matchs[1].groups = NULL;
	matchs[1].name = NULL;
	matchs[0].name = NULL;
	matchs[0].str_begin = lqeng->str;
	matchs[1].str_begin = lqeng->str;
	if (lqeng->matches)
		*lqeng->matches = NULL;
	i = 0;
	matchs[1].pos = 0;
	i = loop_matches(lqeng, matchs);
	if ((lqeng->flags & LQ_UGLOBAL) && matchs[0].len == -1)
	{
		matchs[1].len = matchs[0].pos;
		matchs[1].str = matchs[0].str_begin + matchs[1].pos;
		matchs[1].id = -1;
		matchs[1].id_str = NULL;
		matchs[1].name = NULL;
		if (lqeng->matches)
			ft_lstpush_p(lqeng->matches,
					ft_lstnew(&matchs[1], sizeof(t_lq_match)));
		++i;
	}
	return (i);
}
