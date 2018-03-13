/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:42:54 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/19 21:44:18 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
		while (s[i])
			++i;
	return (i);
}

size_t	ft_strlen_e(const char *s)
{
	size_t	i;
	int		n;

	i = 0;
	n = 1;
	if (s)
	{
		while (*s)
		{
			if (*s == '\\' && n)
			{
				++s;
				n = 0;
			}
			else
			{
				n = 1;
				++i;
				++s;
			}
		}
	}
	return (i);
}
