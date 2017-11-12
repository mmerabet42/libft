/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoincs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:51:22 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/12 17:30:02 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoincs(char a, const char *b)
{
	char	*s;
	size_t	i;

	i = 0;
	if (b == NULL)
		return (NULL);
	if ((s = ft_strnew(ft_strlen(b) + 1)) == NULL)
		return (NULL);
	s[i++] = a;
	while (*b)
		s[i++] = *b++;
	return (s);
}
