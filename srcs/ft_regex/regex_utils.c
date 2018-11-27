/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:57:21 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/27 18:23:56 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"
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

void	free_rule(void *p, size_t s)
{
	if (!s)
	{
		free((void *)((t_regex_func *)p)->name);
		free((void *)((t_regex_func *)p)->regex);
	}
	free(p);
}

void	free_match(void *p, size_t s)
{
	if (!p)
		return ;
	(void)s;
	ft_lstdel(&((struct s_regex_match *)p)->groups, free_match);
	free(p);
}