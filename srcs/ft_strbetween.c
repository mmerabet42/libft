/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbetween.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:05:05 by mmerabet          #+#    #+#             */
/*   Updated: 2018/03/07 18:54:04 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_printf.h"

char	*ft_strbetween(const char *s, char a, char b)
{
	char	*res;
	size_t	r;

	if (!s)
		return (NULL);
	res = ft_strnew(0);
	r = 0;
	while (*s)
	{
		if (*s == b && r > 0)
			if (--r == 0)
				return (res);
		if (r > 0)
		{
			if (*s == '\\')
				++s;
			if (!(res = ft_strjoinc_clr(res, *s)))
				return (NULL);
		}
		if (*s == a)
			++r;
		++s;
	}
	return (res);
}
