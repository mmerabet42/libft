/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoincs_clr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:30:32 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/30 15:13:41 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoincs_clr(char a, char *b)
{
	char	*s;
	char	*sb;
	size_t	i;

	i = 0;
	sb = b;
	if ((s = ft_strnew(ft_strlen(b) + 1)) == NULL)
		return (NULL);
	s[i++] = a;
	if (b)
		while (*b)
			s[i++] = *b++;
	b = NULL;
	free(sb);
	return (s);
}
