/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:27:06 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/27 18:25:07 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexiq.h"
#include "ft_str.h"
#include "ft_types.h"

static int	special_char(char c, t_lq_eng *lqeng)
{
	int	pos;

	if ((lqeng->flags & LQ_READABLE) && ft_isspace(*lqeng->expr))
	{
		while (ft_isspace(*lqeng->expr))
			++lqeng->expr;
		return (0);
	}
	else if (c == '*' || c == '?')
	{
		pos = lq_wildcard(lqeng);
		if (pos == -1)
			return (-1);
		else if (pos > 0)
			return (pos);
		return (0);
	}
	return (-2);
}

static int	lq_equ(t_lq_eng *lqeng)
{
	int	i;

	i = 0;
	if (!lqeng->str[i])
		return (-1);
	while (lqeng->expr[i] && lqeng->str[i])
	{
		if (lqeng->expr[i] == '*' || lqeng->expr[i] == '?'
				|| ((lqeng->flags & LQ_READABLE) && ft_isspace(lqeng->expr[i])))
			return (i);
		if (lqeng->expr[i] != lqeng->str[i])
			return (-1);
		++i;
	}
	if (!lqeng->expr[i] && lqeng->str[i] && !(lqeng->flags & LQ_END))
		return (-1);
	return (i);
}

int			lq_exec2(t_lq_eng *lqeng)
{
	int	pos;

	if (lqeng->id)
	{
		*lqeng->id = 0;
		*lqeng->id_str = NULL;
	}
	lqeng->cid = 0;
	while (*lqeng->expr)
	{
		if ((pos = special_char(*lqeng->expr, lqeng)) == 0)
			continue;
		else if (pos != -2)
			return (pos);
		if ((pos = lq_equ(lqeng)) == -1)
			return (-1);
		lqeng->len += pos;
		lqeng->str += pos;
		lqeng->expr += pos;
	}
	if ((lqeng->flags & LQ_END) && *lqeng->str)
		return (lqeng->len);
	if (*lqeng->expr && !ft_strequ(lqeng->expr, "*"))
		return (-1);
	return (*lqeng->str ? -1 : lqeng->len);
}

int			lq_exec(t_lq_eng *lqeng)
{
	int		ret;
	t_list	*groups;

	if (!(lqeng->flags & LQ_GROUP) || !lqeng->groups)
	{
		groups = NULL;
		lqeng->flags |= (LQ_INNER_GROUP | LQ_GROUP);
		lqeng->groups = &groups;
		lqeng->free_groups = &groups;
	}
	if ((ret = lq_exec2(lqeng)) == -1)
		if (lqeng->flags & LQ_GROUP)
			ft_lstdel(lqeng->free_groups, lq_free_match);
	if ((lqeng->flags & LQ_INNER_GROUP))
	{
		lqeng->groups = NULL;
		lqeng->free_groups = NULL;
		ft_lstdel(lqeng->groups, lq_free_match);
	}
	return (ret);
}

int			lq_pos(t_lq_eng *lqeng)
{
	const char	*str;
	int			ret;

	if (lqeng->pos)
	{
		*lqeng->pos = 0;
		str = lqeng->str;
		ret = 0;
		while ((ret = lq_exec(lqeng)) == -1)
		{
			if (!*str)
				return (-1);
			lqeng->str = ++str;
			lqeng->expr = lqeng->expr_begin;
			lqeng->len = 0;
			++*lqeng->pos;
		}
		return (ret);
	}
	return (lq_exec(lqeng));
}
