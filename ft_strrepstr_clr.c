/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepstr_clr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:13:51 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/12 17:14:11 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrepstr_clr(const char *s, const char *a, const char *b)
{
	char	*snew;
	char	*pos;
	int		lens[3];

	lens[0] = ft_strlen(a);
	lens[1] = ft_strlen(b);
	lens[2] = ft_strcountstr(s, a);
	lens[2] = ft_strlen(s) - (lens[0] * lens[2]) + (lens[1] * lens[2]);
	if ((snew = (char *)malloc(sizeof(char) * (lens[2] + 1))) == NULL)
		return (NULL);
	snew[lens[2]] = '\0';
	pos = ft_strstr(s, a);
	while (*s)
	{
		if (s == pos)
		{
			ft_strcpy(snew, b);
			snew += lens[1];
			s += lens[0];
			pos = ft_strstr(s, a);
		}
		else
			*snew++ = *s++;
	}
	free(s);
	return (snew - lens[2]);
}


