/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 21:24:23 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/02 23:04:32 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "ft_printf.h"
#include "ft_mem.h"

t_mat	*ft_mat_mult(t_mat a, t_mat b, t_mat *res)
{
	size_t	i[3];

	if (a.columns != b.rows)
		return (NULL);
	res = ft_mat_opget(a.rows, b.columns, res);
	i[0] = 0;
	while (i[0] < a.rows)
	{
		i[1] = 0;
		while (i[1] < b.columns)
		{
			i[2] = 0;
			while (i[2] < a.columns)
			{
				*ft_mat_get(res, i[1], i[0]) +=
					*ft_mat_get(&a, i[2], i[0]) * *ft_mat_get(&b, i[1], i[2]);
				++i[2];
			}
			++i[1];
		}
		++i[0];
	}
	return (res);
}

t_mat	*ft_mat_multi(t_mat a, int scalar, t_mat *res)
{
	size_t	i;
	size_t	size;

	if (!res || res->matrix != a.matrix)
		res = ft_mat_opget(a.rows, a.columns, res);
	i = 0;
	size = a.rows * a.columns;
	while (i < size)
	{
		res->matrix[i] = a.matrix[i] * scalar;
		++i;
	}
	return (res);
}
