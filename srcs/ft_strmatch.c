/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:02:15 by mmerabet          #+#    #+#             */
/*   Updated: 2018/04/05 21:31:39 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_printf.h"

static int	check_char(const char **str, const char **match)
{
	if (**str != **match)
		return (0);
	++(*str);
	++(*match);
	return (1);
}

int			ft_strmatch(const char *str, const char *match)
{
	while (*match)
	{
		if (*match == '*')
		{
			if (*(match + 1) == '\\')
			{
				if (!check_char(&str, &match))
					return (0);
				++match;
				continue ;
			}
			if (!*++match)
				return (1);
			while (*str && *str != *match)
				++str;
			if (!*str)
				return (0);
		}
		else if (!check_char(&str, &match))
			return (0);
	}
	return (*str ? 0 : 1);
}

static int	check_fulli(char c, const char *match)
{
	char	*til;
	int		pos;

	pos = ft_strchr_pos(match, '*');
	if (!(til = ft_strnchr(match, '-', (size_t)pos))
			&& ft_strnchr(match, c, pos))
		return (1);
	else
	{
		
	}
	return (0);
	
}

static int	check_full(const char **str, const char **match)
{
	int	pos;

	pos = ft_strchr_pos(*match, '*');
	if (!check_fulli(**str, *match))
	{
		*match += pos + 1;
		return (0);
	}
	while (check_fulli(**str, *match))
		++(*str);
	*match += pos + 1;
	return (1);
/*	char	*til;
	int		pos;

	pos = ft_strchr_pos(*match, '*');
	if (!(til = ft_strnchr(*match, '-', (size_t)pos)))
	{
		ft_printf("Test: %c '%.*s'\n", **str, pos, *match);
		if (!ft_strnchr(*match, **str, pos))
		{
			*match += pos + 1;
			return (0);
		}
		while (ft_strnchr(*match, **str, pos))
			++(*str);
	}
	*match += pos + 1;
	return (1);*/
}

int			ft_strmatchg(const char *str, const char *match)
{
	int	nextlookup;

	while (*match)
	{
		nextlookup = 0;
		if (*match == '*')
		{
			if (*(match + 1) == '\\')
			{
				if (!check_char(&str, &match))
					return (0);
				++match;
				continue ;
			}
			else if (*(match + 1) == '*')
			{
				if (*(match + 2) == '*')
					nextlookup = 1;
				else
				{
					match += 2;
					if (!check_full(&str, &match))
						return (0);
					continue ;
				}
			}
			if (!*++match)
				return (1);
			while (*str && *str != *match)
			{
				if (nextlookup && check_fulli(*str, match + 2))
					break ;
				++str;
			}
			if (!*str)
				return (0);
		}
		else if (!check_char(&str, &match))
			return (0);
	}
	return (*str ? 0 : 1);
}
