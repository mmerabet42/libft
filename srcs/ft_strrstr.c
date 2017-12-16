/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:17:42 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/12 19:49:37 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrstr(const char *a, const char *b)
{
	int		i;
	int		j;
	size_t	blen;

	i = ft_strlen(a);
	blen = ft_strlen(b) - 1;
	while (--i >= 0)
	{
		j = blen;
		while (j >= 0 && a[i - (blen - j)] && (a[i - (blen - j)] == b[j]))
			--j;
		if (j == 0)
			return ((char *)(&a[i]));
	}
	return (NULL);
}
