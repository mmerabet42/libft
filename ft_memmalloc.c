/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:14:01 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/09 22:19:12 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmalloc(size_t size)
{
	void	*mem;

	if ((mem = malloc(size)))
		return (ft_memset(malloc(size), 0, size));
	return (NULL);
}
