/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:00:41 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/11 16:34:41 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int					nb;
	int					sign;
	unsigned long long	max;

	nb = 0;
	max = 0;
	sign = 1;
	while (ft_isspace(*s))
		++s;
	if ((*s == '+' || *s == '-') && *s++ == '-')
		sign = -1;
	while (ft_isdigit(*s))
	{
		max = max * 10 + (*s - 48);
		if (sign == 1 && max >= 9223372036854775807)
			return (-1);
		else if (sign == -1 && max > 9223372036854775807)
			return (0);
		nb = nb * 10 + (*s++ - 48);
	}
	return (nb * sign);
}
