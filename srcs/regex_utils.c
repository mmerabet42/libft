/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 20:05:27 by mmerabet          #+#    #+#             */
/*   Updated: 2018/10/19 19:31:16 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"
#include "ft_str.h"
#include "ft_mem.h"
#include "ft_types.h"

void	regex_init(t_regex_info *regex_info, const char *regex, const char *str)
{
	ft_bzero(regex_info, sizeof(t_regex_info));
	regex_info->str_begin = str;
	regex_info->rgx_begin = regex;
	regex_info->str = str;
	regex_info->regex = regex;
	regex_info->rgxn = -1;
	regex_info->strn = -1;
}

int		regex_variable(t_regex_info *rgxi, const char *s)
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

int		manage_rules(const char *str, t_list **rules, int flags, va_list vp)
{
	t_regex_func	func;
	t_list			*nw;
	t_list			**lst;
	int				ret;

	ret = 0;
	func.name = str;
	if (flags & RGX_ADD)
	{
		func.func = va_arg(vp, t_regex_funcptr);
		func.id = ((flags & RGX_ID) ? va_arg(vp, int) : (int)ft_lstsize(*rules) + 1);
		func.flags = (flags & ~(RGX_ID | RGX_ADD));
		if (!(nw = ft_lstnew(&func, sizeof(t_regex_func))))
			return (-1);
		ft_lstpushfront(rules, nw);
		ret = func.id;
	}
	else if ((flags & RGX_GET) && (lst = va_arg(vp, t_list **)))
		*lst = *rules;
	else if ((flags & RGX_FREE) && (lst = va_arg(vp, t_list **)))
		ft_lstdel(lst, content_delfunc);
	else if (flags & RGX_CLEAN)
		ft_lstdel(rules, content_delfunc);
	va_end(vp);
	return (ret);
}
