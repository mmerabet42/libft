/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrep_clr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:13:05 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/12 17:13:26 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrep_clr(const char *s, char a, char b)
{
	char	*snew;
	char	*pos;

	if ((snew = ft_strdup(s)) == NULL)
		return (NULL);
	pos = snew;
	while ((pos = ft_strchr(pos, a)))
		*pos++ = b;
	free(s);
	return (snew);
}

