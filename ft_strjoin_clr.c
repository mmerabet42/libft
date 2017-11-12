/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_clr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 22:30:12 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/12 17:30:45 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_clr(char *a, char *b, int d)
{
	char	*s;
	size_t	i;

	s = (char *)malloc(sizeof(char) * (ft_strlen(a) + ft_strlen(b) + 1));
	i = 0;
	while (*a)
		s[i++] = *a++;
	while (*b)
		s[i++] = *b++;
	s[i] = '\0';
	if (d == 1)
		free(a);
	else if (d == 2)
		free(b);
	else if (d == 3)
	{
		free(a);
		free(b);
	}
	return (s);
}
