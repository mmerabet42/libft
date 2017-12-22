/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 19:27:31 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/20 20:48:34 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_getwstr(const wchar_t *wcs)
{
	return (ft_getnwstr(wcs, ft_wstrlen(wcs)));
}

char	*ft_getnwstr(const wchar_t *wcs, int n)
{
	char	*str;
	char	*wc;

	if (!wcs || n < 0)
		return (NULL);
	n = ft_wstrnlen(wcs, n);
	str = ft_strnew(n - 1);
	while (*wcs && n--)
	{
		if (!(wc = ft_getwchar(*wcs++)))
		{
			free(str);
			return (NULL);
		}
		ft_strcat(str, wc);
		free(wc);
	}
	return (str);
}
