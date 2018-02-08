/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_dump.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:02:40 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/08 17:07:54 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "ft_printf.h"
#include <stdio.h>

void	ft_vec_dump(const t_vec *vec)
{
	size_t	i;

	if (!vec)
		return ;
	i = 0;
	ft_printf("[");
	while (i < vec->dimensions)
	{
		ft_printf("%f%s", vec->vector[i],
				(i + 1 < vec->dimensions ? ", " : "]"));
		++i;
	}
}
