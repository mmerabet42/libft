/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:50:08 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/12 16:25:28 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getnwstr(const wchar_t *wcs, int n)
{
	char	*str;
	char	*wc;

	str = ft_strnew(0);
	if (!wcs || n < 0)
		return (NULL);
	while (*wcs && n--)
	{
		if (!(wc = ft_getwchar(*wcs++)))
		{
			free(str);
			return (NULL);
		}
		str = ft_strjoin_clr(str, wc, 2);
	}
	return (str);
}
