/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:41:14 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/15 12:56:52 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_fd(int n, const char *base, int fd)
{
	int	baselen;

	if (!base)
		return ;
	baselen = ft_strlen(base);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_base_fd(-(n / baselen), base, fd);
	}
	else if (n / baselen != 0)
		ft_putnbr_base_fd(n / baselen, base, fd);
	ft_putchar_fd(base[ft_abs((int)n % baselen)], fd);
}
