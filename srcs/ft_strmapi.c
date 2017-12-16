/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:34:16 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/15 13:00:34 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	char	*snew;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	if ((snew = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	while (*s)
	{
		snew[i] = f(i, *s++);
		++i;
	}
	snew[i] = '\0';
	return (snew);
}
