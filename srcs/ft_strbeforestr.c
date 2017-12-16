/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbeforestr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:13:55 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/15 13:10:28 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strbeforestr(const char *s, const char *a)
{
	int	pos;

	if (!s || !a)
		return (NULL);
	pos = ft_strstr_pos(s, a);
	return (pos == -1 ? NULL : ft_strndup(s, pos));
}
