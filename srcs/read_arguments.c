/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 20:05:27 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/06 20:09:57 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"

static int	add_rule(t_regex_info *rgxi, t_list **rules, int flags, va_list vp)
{
	t_regex_func	func;
	t_list			*nw;

	func.name = rgxi->regex;
	func.regex = rgxi->str;
	func.func = va_arg(vp, t_regex_funcptr);
	if (flags & RGX_ID)
		func.id = va_arg(vp, int);
	else
		func.id = (int)ft_lstsize(*rules) + 1;
	func.flags = (flags & ~(RGX_ID | RGX_ADD));
	if (!(nw = ft_lstnew(&func, sizeof(t_regex_func))))
	{
		va_end(vp);
		return (-1);
	}
	ft_lstpushfront(rules, nw);
	va_end(vp);
	return (func.id);
}

static void	free_rule(void *p, size_t s)
{
	if (!s)
	{
		free((void *)((t_regex_func *)p)->name);
		free((void *)((t_regex_func *)p)->regex);
	}
	free(p);
}

static void	free_match(void *p, size_t s)
{
	if (!p)
		return ;
	(void)s;
	ft_lstdel(&((t_regex_match *)p)->groups, content_delfunc);
	free(p);
}

int			manage_rules(t_regex_info *rgxi, t_list **rules, int flags,
					va_list vp)
{
	t_list	**lst;

	if (flags & RGX_LOAD)
		return (regex_load(rgxi, rules));
	else if (flags & RGX_ADD)
		return (add_rule(rgxi, rules, flags, vp));
	else if ((flags & RGX_GET) && (lst = va_arg(vp, t_list **)))
		*lst = *rules;
	else if ((flags & RGX_FREE) && (lst = va_arg(vp, t_list **)))
		ft_lstdel(lst, free_match);
	else if ((flags & RGX_FREEGRP) && (lst = va_arg(vp, t_list **)))
		ft_lstdel(lst, content_delfunc);
	else if (flags & RGX_CLEAN)
		ft_lstdel(rules, free_rule);
	va_end(vp);
	return (0);
}

void		get_args(t_regex_info *rgxi, va_list vp)
{
	if (rgxi->flags & RGX_RGXN)
		rgxi->rgxn = (int)va_arg(vp, int);
	if (rgxi->flags & RGX_STRN)
		rgxi->strn = (int)va_arg(vp, int);
	if (rgxi->flags & (RGX_GLOBAL | RGX_UGLOBAL))
		rgxi->matches = (t_list **)va_arg(vp, t_list **);
	else
	{
		if (rgxi->flags & RGX_POS)
			rgxi->pos = (int *)va_arg(vp, int *);
		if (rgxi->flags & RGX_ID)
			rgxi->id = (int *)va_arg(vp, int *);
		if (rgxi->flags & RGX_GROUP)
			rgxi->groups = (t_list **)va_arg(vp, t_list **);
		rgxi->free_groups = rgxi->groups;
	}
	if (rgxi->flags & RGX_DATA)
		rgxi->data = (int *)va_arg(vp, void *);
	if (rgxi->flags & RGX_VAR)
		rgxi->vars = (int *)va_arg(vp, int *);
	va_end(vp);
}
