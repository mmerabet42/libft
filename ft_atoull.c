/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:05:31 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/13 14:08:46 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_atoull(const char *s)
{
	unsigned long long	nb;

	nb = 0;
	while (ft_isspace(*s))
		++s;
	while (ft_isdigit(*s))
		nb = nb * 10 + (*s++ - 48);
	return (nb);
}
