/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_dump.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 16:00:05 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/01 18:01:00 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "ft_printf.h"

void	ft_mat_dump(const t_mat *mat)
{
	int	x;
	int	y;

	if (!mat)
		return ;
	y = 0;
	while (y < mat->size)
	{
		x = 0;
		ft_printf("[");
		while (x < mat->size)
		{
			ft_printf("%d%s", mat->matrix[x + mat->size * y],
					(x + 1 < mat->size ? ", " : "]\n"));
			++x;
		}
		++y;
	}
}
