/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_cbase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 13:37:02 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/11 15:02:39 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulltoa_cbase(unsigned long long n, const char *base)
{
	char				*str;
	int					baselen;
	int					i;
	unsigned long long	nc;

	if (!base)
		return (NULL);
	baselen = ft_strlen(base);
	i = 1;
	nc = n;
	while (nc /= baselen)
		++i;
	if ((str = ft_strnew(i)) == NULL)
		return (NULL);
	while (--i >= 0)
	{
		str[i] = base[ft_abs(n % baselen)];
		n /= baselen;
	}
	return (str);
}
