/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:45:25 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/13 22:14:33 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *a, const char *b)
{
	char	*s;
	size_t	i;

	if (!a || !b)
		return (NULL);
	if (!(s = (char *)malloc(sizeof(char) * (ft_strlen(a) + ft_strlen(b) + 1))))
		return (NULL);
	i = 0;
	while (*a)
		s[i++] = *a++;
	while (*b)
		s[i++] = *b++;
	s[i] = '\0';
	return (s);
}
