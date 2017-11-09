/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:48:38 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/09 19:42:54 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnrchr(const char *s, int c, size_t n)
{
	int		i;

	i = ft_strlen(s);
	if (n >= i)
		n = i - 1;
	i = n;
	while (i >= 0 && s[i] != c)
		--i;
	return ((char *)(s[i] == c ? &s[i] : NULL));
}
