/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_clr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 22:30:12 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/30 14:26:36 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_strs(char *a, char *b, int d)
{
	if (d == 0 && a)
		free(a);
	else if (d == 1 && b)
		free(b);
	else if (d == 2 && a && b)
	{
		free(a);
		free(b);
	}
}

char		*ft_strjoin_clr(char *a, char *b, int d)
{
	char	*s;
	char	*sa;
	char	*sb;
	size_t	i;

	sa = a;
	sb = b;
	if (!(s = (char *)malloc(sizeof(char) * (ft_strlen(a) + ft_strlen(b) + 1))))
		return (NULL);
	i = 0;
	if (a)
		while (*a)
			s[i++] = *a++;
	if (b)
		while (*b)
			s[i++] = *b++;
	s[i] = '\0';
	free_strs(sa, sb, d);
	return (s);
}
