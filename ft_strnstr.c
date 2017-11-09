/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:53:46 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/09 18:17:35 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *a, const char *b, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < n && a[i])
	{
		j = 0;
		while (b[j] && a[i + j] && (b[j] == a[i + j]))
			++j;
		if (b[j] == '\0')
			return ((char *)(&a[i]));
		++i;
	}
	return (NULL);
}
