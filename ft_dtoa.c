/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:12:56 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/13 14:41:39 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dtoa(double n, int precision)
{
	int		firstp;
	double	secondp;
	char	*cfirstp;
	char	*csecondp;

	firstp = (int)n;
	secondp = (double)(n - firstp) * (n < 0 ? -1 : 1);
	cfirstp = ft_itoa(firstp);
	if (precision > 0)
	{
		while (--precision)
			secondp *= 10;
		csecondp = ft_ulltoa((unsigned long long)secondp);
		cfirstp = ft_strjoin(ft_strjoinc(cfirstp, '.'), csecondp);
	}
	return (cfirstp);
}
