/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:27:06 by mmerabet          #+#    #+#             */
/*   Updated: 2018/10/26 16:27:27 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"
#include "ft_str.h"
#include "ft_types.h"
#include "ft_printf.h"

static int	special_char(char c, t_regex_info *rgxi)
{
	int	pos;

	if ((rgxi->flags & RGX_READABLE) && ft_isspace(*rgxi->regex))
	{
		while (ft_isspace(*rgxi->regex))
			++rgxi->regex;
		return (0);
	}
	else if (c == '*' || c == '?')
	{
		pos = regex_wildcard(rgxi);
		if (pos == -1)
			return (-1);
		else if (pos > 0)
			return (pos);
		return (0);
	}
	return (-2);
}

static int	regex_equ(t_regex_info *rgxi)
{
	int	i;

	i = 0;
	if (!rgxi->str[i])
		return (-1);
	while (rgxi->regex[i] && rgxi->str[i])
	{
		if (rgxi->regex[i] == '*' || rgxi->regex[i] == '?'
				|| ((rgxi->flags & RGX_READABLE) && rgxi->regex[i] == ' '))
			return (i);
		if (rgxi->regex[i] != rgxi->str[i])
			return (-1);
		++i;
	}
	if (!rgxi->regex[i] && rgxi->str[i] && !(rgxi->flags & RGX_END))
		return (-1);
	return (i);
}

int			regex_exec(t_regex_info *regex_info)
{
	int	pos;

	if (regex_info->id)
		*regex_info->id = 0;
	regex_info->cid = 0;
	while (*regex_info->regex)
	{
		if ((pos = special_char(*regex_info->regex, regex_info)) == 0)
			continue;
		else if (pos != -2)
			return (pos);
		if ((pos = regex_equ(regex_info)) == -1)
			return (-1);
		regex_info->len += pos;
		regex_info->str += pos;
		regex_info->regex += pos;
	}
	if ((regex_info->flags & RGX_END) && *regex_info->str)
		return (regex_info->len);
	if (*regex_info->regex && !ft_strequ(regex_info->regex, "*"))
		return (-1);
	return (*regex_info->str ? -1 : regex_info->len);
}
