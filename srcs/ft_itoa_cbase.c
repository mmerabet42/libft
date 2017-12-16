/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:40:21 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/03 13:48:04 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_cbase(int n, const char *base)
{
	char	*str;
	int		baselen;
	int		i;
	int		nc;
	int		isneg;

	if (!base)
		return (NULL);
	isneg = (n < 0 ? 1 : 0);
	baselen = ft_strlen(base);
	i = (isneg ? 2 : 1);
	nc = n;
	while (nc /= baselen)
		++i;
	if ((str = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	str[i] = '\0';
	while (i >= 0)
	{
		str[--i] = base[ft_abs(n % baselen)];
		n /= baselen;
	}
	str[0] = (isneg ? '-' : str[0]);
	return (str);
}
