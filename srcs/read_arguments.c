/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 20:05:27 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/12 16:21:10 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"

static int	add_multi_rule(va_list vp)
{
	t_regex_func	*funcs;
	size_t			funcs_len;
	size_t			i;

	if (!(funcs = va_arg(vp, t_regex_func *)))
		return (-1);
	funcs_len = va_arg(vp, size_t);
	i = 0;
	while (i < funcs_len)
	{
		if (ft_regex(RGX_ADD | funcs[i].flags, funcs[i].name, funcs[i].regex,
				funcs[i].func, funcs[i].id) == -1)
			return (-1);
		++i;
	}
	return ((int)i);
}

static int	add_rule(t_regex_info *rgxi, t_list **rules, int flags, va_list vp)
{
	t_regex_func	func;
	t_list			*nw;

	if (flags & RGX_TO)
	func.name = rgxi->regex;
	func.regex = rgxi->str;
	func.func = va_arg(vp, t_regex_funcptr);
	if (flags & RGX_ID)
		func.id = va_arg(vp, int);
	else
		func.id = (int)ft_lstsize(*rules) + 1;
	func.flags = (flags & ~(RGX_ID | RGX_ADD | RGX_TO));
	if (!(nw = ft_lstnew(&func, sizeof(t_regex_func))))
	{
		va_end(vp);
		return (-1);
	}
	ft_lstpushfront(rules, nw);
	va_end(vp);
	return (func.id);
}

int			manage_rules(t_regex_info *rgxi, t_list **rules, int flags,
					va_list vp)
{
	t_list	**lst;

	if ((flags & RGX_TO) && (lst = va_arg(vp, t_list **)))
		rules = lst;
	if (flags & RGX_LOAD)
		return (regex_load(rgxi, rules));
	else if (flags & RGX_ADD)
		return (add_rule(rgxi, rules, flags, vp));
	else if (flags & RGX_ADD_MULTI)
		return (add_multi_rule(vp));
	else if (flags & RGX_SET && (lst = va_arg(vp, t_list **)))
		*rules = *lst;
	else if ((flags & RGX_GET) && (lst = va_arg(vp, t_list **)))
		*lst = *rules;
	else if ((flags & RGX_FREE) && (lst = va_arg(vp, t_list **)))
		ft_lstdel(lst, free_match);
	else if ((flags & RGX_FREEGRP) && (lst = va_arg(vp, t_list **)))
		ft_lstdel(lst, free_group);
	else if (flags & RGX_CLEAN)
		ft_lstdel(rules, free_rule);
	va_end(vp);
	return (0);
}
