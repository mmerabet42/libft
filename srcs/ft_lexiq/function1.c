/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:28:22 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/16 20:26:12 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexiq.h"
#include "ft_str.h"
#include "ft_types.h"
#include "ft_math.h"
#include "ft_printf.h"

int			delim_lq(t_lq_eng *lqeng, t_lq_rule *rule)
{
	if (*rule->rule == '^' && lqeng->str == lqeng->str_begin)
		return (0);
	else if (*rule->rule == '^' && rule->rule[1] == 'n'
			&& *(lqeng->str - 1) == '\n')
		return (0);
	else if (*rule->rule == '$' && !*lqeng->str)
		return (0);
	else if (*rule->rule == '$' && rule->rule[1] == 'n'
			&& *lqeng->str == '\n')
		return (0);
	else if (*rule->rule == '0' && *lqeng->str == '\0')
		return (1);
	return (-1);
}

int			case_lq(t_lq_eng *lqeng, t_lq_rule *rule)
{
	int	i;

	i = -1;
	while (++i < rule->len_arg && lqeng->str[i])
		if (ft_tolower(rule->arg[i]) != ft_tolower(lqeng->str[i]))
			return (-1);
	if (!lqeng->str[i] && i < rule->len_arg)
		return (-1);
	return (i);
}

static int	next_op(t_lq_rule *rule, int i)
{
	int	j;
	int	pos;

	j = 0;
	while (i < rule->len_arg)
	{
		if (rule->arg[i] == (*rule->rule == 'a' ? '&' : '|'))
			return (j);
		if (rule->arg[i] == '*' || rule->arg[i] == '?')
		{
			if ((pos = lq_bracket(&rule->arg[i], NULL)) == -1)
				return (-1);
			else if (pos != -2)
			{
				j += pos - 1;
				i += pos - 1;
			}
		}
		++j;
		++i;
	}
	return (j);
}

static int	move_i(t_lq_eng *r, t_lq_rule *rule, int *i)
{
	char			*str;
	int				ret;
	int				j;
	t_lq_eng		lqeng2;
	t_list			*grps;

	if (rule->arg[*i] == (*rule->rule == 'a' ? '&' : '|'))
		++*i;
	if ((j = next_op(rule, *i)) == -1)
		return (-2);
	if (!(str = ft_strndup(&rule->arg[*i], j)))
		return (-2);
	lqeng2 = *r;
	lqeng2.expr = str;
	lqeng2.flags &= ~(LQ_POS | LQ_GLOBAL | LQ_UGLOBAL | LQ_INNER_GROUP);
	lqeng2.flags |= LQ_END;
	lqeng2.len = 0;
	lqeng2.free_groups = r->groups;
	if ((r->flags & LQ_GROUP) && r->groups && (grps = ft_lstend(*r->groups)))
		lqeng2.free_groups = &grps->next;
	ret = lq_exec(&lqeng2);
	free(str);
	*i += j;
	return (ret);
}

int			cond_lq(t_lq_eng *lqeng, t_lq_rule *rule)
{
	int		i;
	int		ret;
	int		max;

	i = 0;
	max = -1;
	ret = 0;
	while (i < rule->len_arg)
	{
		ret = move_i(lqeng, rule, &i);
		if (*rule->rule == 'a' && ret == -1)
			return (-1);
		else if (*rule->rule != 'a')
		{
			if (*rule->rule == 'r' && ret != -1)
				max = ft_max(ret, max);
			else if (ret != -1)
				return (ret);
		}
	}
	return (*rule->rule == 'a' ? ret : max);
}
