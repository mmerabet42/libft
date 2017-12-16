/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoincs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:51:22 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/30 14:41:09 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoincs(char a, const char *b)
{
	char	*s;
	size_t	i;

	i = 0;
	if ((s = ft_strnew(ft_strlen(b) + 1)) == NULL)
		return (NULL);
	s[i++] = a;
	if (b)
		while (*b)
			s[i++] = *b++;
	return (s);
}
