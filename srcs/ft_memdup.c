/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:42:27 by mmerabet          #+#    #+#             */
/*   Updated: 2018/04/18 17:37:57 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memdup(const void *s, size_t n)
{
	void	*mem;

	if (s && (mem = malloc(n)))
		return (ft_memcpy(mem, s, n));
	return (ft_memalloc(n));
}

int		ft_memdel(void **ap)
{
	if (ap && *ap)
	{
		free(*ap);
		*ap = NULL;
	}
	return (1);
}
