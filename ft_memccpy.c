/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:41:52 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/09 15:41:53 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdst;
	unsigned char	cc;
	size_t			i;

	i = 0;
	csrc = (unsigned char *)src;
	cdst = (unsigned char *)dst;
	cc = (unsigned char)c;
	while (i < n && *csrc != cc)
		cdst[i++] = *csrc++;
	return ((i == n) ? NULL : cdst);
}
