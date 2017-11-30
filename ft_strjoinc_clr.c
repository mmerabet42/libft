/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinc_clr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:29:58 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/30 15:11:23 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinc_clr(char *a, char b)
{
	char	*s;

	if ((s = ft_strmdup(a, 1)) == NULL)
		return (NULL);
	s[ft_strlen(a)] = b;
	free(a);
	return (s);
}
