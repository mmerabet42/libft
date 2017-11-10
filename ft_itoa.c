/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:38:37 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/10 21:47:56 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define ABS(v) (v < 0 ? -v : v)

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		isneg;

	isneg = (n < 0) ? 1 : 0;
	i = ft_intlen(n);
	if ((str = ft_strnew(i)) == NULL)
		return (NULL);
	while (i >= 0)
	{
		str[--i] = ABS(n % 10) + 48;
		n /= 10;
	}
	str[0] = (isneg ? '-' : str[0]);
	return (str);
}
