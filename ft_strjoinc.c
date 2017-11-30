/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:49:58 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/30 14:39:48 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinc(const char *a, char b)
{
	char	*s;

	if ((s = ft_strmdup(a, 1)) == NULL)
		return (NULL);
	s[ft_strlen(a)] = b;
	return (s);
}
