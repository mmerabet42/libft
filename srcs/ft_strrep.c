/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:44:59 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/15 12:10:39 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrep(const char *s, char a, char b)
{
	char	*snew;
	char	*pos;

	if (!s || (snew = ft_strdup(s)) == NULL)
		return (NULL);
	pos = snew;
	while ((pos = ft_strchr(pos, a)))
		*pos++ = b;
	return (snew);
}
