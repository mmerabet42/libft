/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:29:02 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/12 17:32:14 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*snew;

	snew = (char *)malloc(sizeof(char) * (n + 1));
	snew[n] = '\0';
	return (ft_strncpy(snew, s, n));
}
