/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 22:13:58 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/15 12:58:25 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revnstr(char *a, size_t n)
{
	size_t	i;

	if (!a)
		return (NULL);
	i = ft_strlen(a) - 1;
	n = (n > i ? i : n);
	i = 0;
	while (i < n)
		ft_swap(a + i++, a + n--);
	return (a);
}
