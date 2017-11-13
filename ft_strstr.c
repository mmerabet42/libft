/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:07:59 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/13 17:04:35 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *a, const char *b)
{
	size_t	j;

	if (*b == '\0')
		return ((char *)a);
	while (*a)
	{
		j = 0;
		while (b[j] && a[j] && (b[j] == a[j]))
			++j;
		if (b[j] == '\0')
			return ((char *)a);
		++a;
	}
	return (NULL);
}
