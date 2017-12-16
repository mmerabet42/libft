/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:42:41 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/09 23:19:03 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char			*schar;
	unsigned char	cchar;

	cchar = (unsigned char)c;
	schar = (char *)s;
	while (n--)
		*schar++ = cchar;
	return (s);
}
