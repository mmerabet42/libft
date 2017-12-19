/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:42:49 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/19 21:48:51 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

char	*ft_strdup(const char *s)
{
	return ((char *)ft_memdup((void *)s, ft_strlen(s) + 1));
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*snew;

	if (!(snew = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	snew[n] = '\0';
	return (ft_strncpy(snew, s, n));
}

char	*ft_strmdup(const char *a, size_t n)
{
	return (ft_strndup(a, ft_strlen(a) + n));
}

void	ft_strdel(char **ap)
{
	ft_memdel((void **)ap);
}
