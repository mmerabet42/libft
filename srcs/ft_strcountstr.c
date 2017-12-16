/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcountstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:48:02 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/15 13:14:48 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcountstr(const char *s, const char *a)
{
	int	count;
	int	j;

	count = 0;
	while (s && *s)
	{
		j = 0;
		while (a[j] && s[j] && (a[j] == s[j]))
			++j;
		if (a[j] == '\0')
			++count;
		++s;
	}
	return (count);
}
