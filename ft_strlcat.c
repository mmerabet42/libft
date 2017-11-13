/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:05:00 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/13 22:27:21 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *a, const char *b, size_t n)
{
	size_t	alen;
	size_t	blen;
	size_t	i;

	alen = ft_strlen(a);
	blen = ft_strlen(b);
	if (n <= alen)
		return (n + blen);
	i = alen;
	while (*b && i < n - 1)
		a[i++] = *b++;
	a[i] = '\0';
	return (alen + blen);
}
