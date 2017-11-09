/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:55:25 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/09 23:01:43 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	int	len;

	while (ft_isspace(*s))
		++s;
	len = ft_strlen(s) - 1;
	while (ft_isspace(s[len]))
			--len;
	return (ft_strndup(s, len));
}
