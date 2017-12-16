/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:42:02 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/12 16:05:03 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *a, const void *b, size_t n)
{
	const unsigned char	*ca;
	const unsigned char	*cb;
	size_t				i;

	if (n == 0)
		return (0);
	i = 0;
	ca = (const unsigned char *)a;
	cb = (const unsigned char *)b;
	while (i < n - 1 && (ca[i] == cb[i]))
		++i;
	return ((int)(ca[i] - cb[i]));
}
