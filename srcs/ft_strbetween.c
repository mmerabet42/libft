/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbetween.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:05:05 by mmerabet          #+#    #+#             */
/*   Updated: 2018/03/09 17:05:20 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strbetween(const char *s, char a, char b)
{
	char	*res;
	char	olds;
	size_t	r;

	if (!s || !(res = ft_strnew(0)))
		return (NULL);
	r = 0;
	while ((olds = *s))
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
		if (*s == a && olds != '\\')
			++r;
		++s;
	}
	return (res);
}
