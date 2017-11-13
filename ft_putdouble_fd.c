/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:35:57 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/13 14:23:22 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdouble_fd(double n, int precision, int fd)
{
	int		i;
	int		firstp;
	double	secondp;
	double	precision_adder;

	firstp = (int)n;
	secondp = (double)(n - firstp) * (n < 0 ? -1 : 1);
	ft_putnbr_fd(firstp, fd);
	if (precision > 0)
	{
		ft_putchar_fd('.', fd);
		precision_adder = 0.1;
		i = 0;
		while (i++ < precision)
			precision_adder /= 10;
		secondp += precision_adder;
		while (--i)
		{
			ft_putnbr_fd((int)(secondp *= 10), fd);
			firstp = (int)secondp;
			secondp -= (double)firstp;
		}
	}
}
