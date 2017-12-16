/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 22:05:26 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/15 12:58:12 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revstr(char *a)
{
	size_t	i;
	size_t	len;

	if (!a)
		return (NULL);
	i = 0;
	len = ft_strlen(a) - 1;
	while (i < len)
		ft_swap(a + i++, a + len--);
	return (a);
}
