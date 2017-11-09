/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:03:45 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/09 22:07:10 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_atoui(const char *s)
{
	unsigned int	nb;

	nb = 0;
	while (ft_isspace(*s))
		++s;
	while (ft_isdigit(*s))
		nb = nb * 10 + (*s++ - 48);
	return (nb);
}
