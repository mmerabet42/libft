/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:42:36 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/13 22:56:43 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*cdst;
	const char	*csrc;

	if (dst <= src)
		ft_memcpy(dst, src, n);
	else
	{
		cdst = dst + n - 1;
		csrc = src + n - 1;
		while (n--)
			*cdst-- = *csrc--;
	}
	return (dst);
}
