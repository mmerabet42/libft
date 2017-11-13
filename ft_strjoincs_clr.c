/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoincs_clr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:30:32 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/13 14:33:31 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoincs_clr(char a, char *b)
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
	free(b);
	return (s);
}
