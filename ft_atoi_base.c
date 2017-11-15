/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:06:17 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/15 12:03:31 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_base(const char *s, const char *base)
{
	int	nb;
	int	baselen;
	int	sign;
	int	pos;
	int	i;

	if (!s || !base)
		return (0);
	baselen = ft_strlen(base);
	i = ft_strlen(s);
	nb = 0;
	sign = 1;
	while (ft_isspace(*s))
		++s;
	if ((*s == '+' || *s == '-') && *s++ == '-')
		sign = -1;
	while ((pos = ft_strchr_pos(base, *s++)) != -1)
		nb += pos * ft_pow(baselen, --i);
	return (nb * sign);
}
