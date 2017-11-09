/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 23:04:27 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/09 23:07:02 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strstr_pos(const char *a, const char *b)
{
	int		pos;
	size_t	j;

	pos = 0;
	while (a[pos])
	{
		j = 0;
		while (b[j] && a[pos + j] && (b[j] == a[pos + j]))
			++j;
		if (b[j] == '\0')
			return (pos);
		++pos;
	}
	return (-1);
}

