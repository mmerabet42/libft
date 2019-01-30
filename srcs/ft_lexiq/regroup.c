/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regroup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:27:06 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/27 18:25:07 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexiq.h"
#include "ft_types.h"
#include "ft_str.h"

int lq_addregroup(const char *expr, const char *str)
{
	// ADD REGROUP RULE
	(void)expr;
	(void)str;
	return (0);
}

int lqr_capture(const char *expr, t_lq_list **groups, t_lq_list **result)
{
	(void)expr;
	(void)groups;
	(void)result;
	return (0);
}

int lqr_check_rule(const char *expr, t_lq_list **groups, t_lq_list **result)
{
	int			i;
	int			len;
	t_lq_list	*newlist;

	i = 0;
	len = ft_strlen((*groups)->match->id_str);
	while (i < len)
	{
		if (!expr[i] || expr[i] == ' ' || expr[i] == '<')
			return (-1);
		else if (expr[i] != (*groups)->match->id_str[i])
			return (-1);
		++i;
	}
	newlist = (t_lq_list *)ft_lstnew((*groups)->match, sizeof(t_lq_match));
	*groups = (*groups)->next;
	if (!*result)
		*result = newlist;
	else
		ft_lstpush((t_list *)*result, (t_list *)newlist);
	return (i);
}

int	lq_regroup(int flags, const char *expr, const char *str, va_list vp)
{
	t_lq_list	*groups;
	t_lq_list	*result;
	int			jump;

	if (flags & LQ_ADDR)
		return (lq_addregroup(expr, str));
	groups = *(t_lq_list **)va_arg(vp, t_lq_list **);
	result = NULL;
	while (*expr)
	{
		jump = 0;
		if (*expr == ' ')
			while (*expr == ' ')
				++expr;
		else
			jump = lqr_check_rule(expr, &groups, &result);
		if (jump == -1)
			return (-1);
		expr += jump;
	}
	*(t_lq_list **)va_arg(vp, t_lq_list **) = result;
	return (0);
}
