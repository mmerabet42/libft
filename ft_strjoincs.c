/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoincs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:51:22 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/09 22:54:32 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoincs(char a, const char *b)
{
	char	*s;
	size_t	i;

	if ((s = (char *)malloc(sizeof(char) * (ft_strlen(b) + 2))) == NULL)
		return (NULL);
	i = 0;
	s[i++] = a;
	while (*b)
		s[i++] = *b++;
	s[i] = '\0';
	return (s);
}

