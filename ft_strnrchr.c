/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:48:38 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/10 14:33:47 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnrchr(const char *s, int c, size_t n)
{
	int		i;
	size_t	len;

	len = ft_strlen(s);
	if (n >= len)
		n = len - 1;
	i = n;
	while (i >= 0 && s[i] != c)
		--i;
	return ((char *)(s[i] == c ? &s[i] : NULL));
}
