/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putullong_base_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:57:06 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/15 13:10:04 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putullong_base_fd(unsigned long long n, const char *base, int fd)
{
	int	baselen;

	if (!base)
		return ;
	baselen = ft_strlen(base);
	if (n / baselen != 0)
		ft_putullong_base_fd(n / baselen, base, fd);
	ft_putchar_fd(base[n % baselen], fd);
}
