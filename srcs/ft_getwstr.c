/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 19:27:31 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/12 16:00:13 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getwstr(const wchar_t *wcs)
{
	char	*str;
	char	*wc;

	str = ft_strnew(0);
	if (!wcs)
		return (NULL);
	while (*wcs)
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
