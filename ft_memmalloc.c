/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:14:01 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/11 18:29:21 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmalloc(size_t size)
{
	void	*mem;

	if ((mem = malloc(size)))
		ft_memset(mem, 0, size);
	return (mem);
}
