/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:53:46 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/13 20:05:05 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *a, const char *b, size_t n)
{
	size_t	blen;

	if (*a == '\0' || n == 0)
		return (NULL);
	if (*b == '\0')
		return ((char *)a);
	blen = ft_strlen(b);
	while (*a && n-- >= blen)
	{
		if (ft_strncmp(a, b, blen) == 0)
			return ((char *)(a));
		++a;
	}
	return (NULL);
}
