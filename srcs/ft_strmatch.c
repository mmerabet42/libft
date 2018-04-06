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

static int	check_chari(char c, const char *match)
{
	char	*til;
	int		pos;

	pos = ft_strchr_pos(match, '*');
	if (!(til = ft_strnchr(match, '-', (size_t)pos))
			&& ft_strnchr(match, c, pos))
		return (1);
	else
		while (*match != '-' && *++til != '*')
			if (c >= *match++ && c <= *til)
				return (1);
	return (0);
	
}

static int	check_char(const char **str, const char **match, int mode)
{
	int	pos;

	if (mode)
	{
		pos = ft_strchr_pos(*match, '*');
		if (!check_chari(**str, *match))
		{
			*match += pos + 1;
			return (0);
		}
		while (check_chari(**str, *match) && **str != *(*match + pos + 1))
			++(*str);
		*match += pos + 1;
	}
	else
	{
		if (**str != **match)
			return (0);
		++(*str);
		++(*match);
	}
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
				if (!check_char(&str, &match, 0))
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
		else if (!check_char(&str, &match, 0))
			return (0);
	}
	return (*str ? 0 : 1);
}

static int	check_ext(const char **str, const char **match, int *lookup)
{
	if (*(*match + 1) == '\\')
	{
		if (!check_char(str, match, 0))
			return (0);
		++(*match);
		return (2);
	}
	else if (*(*match + 1) == '*')
	{
		if (*(*match + 2) == '*')
			*lookup = 1;
		else if ((*match += 2))
		{
			if (!check_char(str, match, 1))
				return (0);
			return (2);
		}
	}
	if (!*++(*match))
		return (1);
	return (3);
}

int			ft_strmatchg(const char *str, const char *match)
{
	int	lookup;
	int	c;

	while (*match)
	{
		lookup = 0;
		if (*match == '*')
		{
			if ((c = check_ext(&str, &match, &lookup)) < 2)
				return (c);
			else
				continue ;
			while (*str && *str != *match)
			{
				if (lookup && check_chari(*str, match + 2))
					break ;
				++str;
			}
			if (!*str)
				return (0);
		}
		else if (!check_char(&str, &match, 0))
			return (0);
	}
	return (*str ? 0 : 1);
}
