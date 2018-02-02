/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 21:24:23 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/02 16:28:55 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "ft_printf.h"

t_mat	*ft_mat_mult(t_mat a, t_mat b, t_mat *res)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (a.columns != b.rows)
		return (NULL);
	res = ft_mat_opget(a.rows, b.columns, res);
	i = 0;
	while (i < a.rows)
	{
		j = 0;
		while (j < b.columns)
		{
			k = 0;
			while (k < a.columns)
			{
				*ft_mat_get(res, j, i) +=
					*ft_mat_get(&a, k, i) * *ft_mat_get(&b, j, k);
				++k;
			}
			++j;
		}
		++i;
	}
	return (res);
}

t_mat	*ft_mat_multi(t_mat a, int scalar, t_mat *res)
{
	size_t	i;
	size_t	size;

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
