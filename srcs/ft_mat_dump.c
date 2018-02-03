/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_dump.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 16:00:05 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/03 19:29:52 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "ft_printf.h"

void	ft_mat_dump(const t_mat *mat)
{
	size_t	x;
	size_t	y;

	if (!mat)
		return ;
	y = 0;
	while (y < mat->rows)
	{
		x = 0;
		ft_printf("[");
		while (x < mat->columns)
		{
			ft_printf("%d%s", mat->matrix[x + mat->columns * y],
					(x + 1 < mat->columns ? ", " : "]"));
			if (x + 1 == mat->columns && y + 1 < mat->rows)
				ft_printf("\n");
			++x;
		}
		++y;
	}
}
