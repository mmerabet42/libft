/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:49:58 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/09 22:55:17 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinc(const char *a, char b)
{
	char	*s;
	size_t	i;

	if ((s = (char *)malloc(sizeof(char) * (ft_strlen(a) + 2))) == NULL)
		return (NULL);
	i = 0;
	while (*a)
		s[i++] = *a++;
	s[i++] = b;
	s[i] = '\0';
	return (s);
}
