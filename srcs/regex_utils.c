/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 20:05:27 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/05 17:11:38 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"
#include "ft_str.h"
#include "ft_mem.h"
#include "ft_types.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

void		regex_init(t_regex_info *regex_info, const char *regex,
					const char *str)
{
	ft_bzero(regex_info, sizeof(t_regex_info));
	regex_info->str_begin = str;
	regex_info->rgx_begin = regex;
	regex_info->str = str;
	regex_info->regex = regex;
	regex_info->rgxn = -1;
	regex_info->strn = -1;
}

int			regex_variable(t_regex_info *rgxi, const char *s)
{
	if (ft_isdigit(*s))
		return (ft_atoi(s));
	else if (ft_islower(*s))
		return (rgxi->vars[*s - 97]);
	else if (ft_isupper(*s))
		return (rgxi->vars[26 + *s - 65]);
	else if (*s == '%' && rgxi->param)
		return (ft_atoi(rgxi->param));
	return (0);
}

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
