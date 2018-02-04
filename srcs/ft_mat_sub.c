/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 19:28:09 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/04 20:34:54 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_mat	*ft_mat_sub(t_mat a, t_mat b, t_mat *res)
{
	size_t	i;
	size_t	size;

	if (a.columns != b.columns || a.rows != b.rows)
		return (NULL);
	res = ft_mat_opget(a.rows, b.columns, res);
	size = a.rows * b.columns;
	i = 0;
	while (i < size)
	{
		res->matrix[i] = a.matrix[i] - b.matrix[i];
		++i;
	}
	return (res);
}

t_mat	*ft_mat_subi(t_mat a, int b, t_mat *res)
{
	size_t	i;
	size_t	size;

	res = ft_mat_opget(a.rows, a.columns, res);
	size = a.rows * a.columns;
	i = 0;
	while (i < size)
	{
		res->matrix[i] = a.matrix[i] - b;
		++i;
	}
	return (res);
}

t_mat	*ft_mat_isub(int a, t_mat b, t_mat *res)
{
	size_t	i;
	size_t	size;

	res = ft_mat_opget(b.rows, b.columns, res);
	size = b.rows * b.columns;
	i = 0;
	while (i < size)
	{
		res->matrix[i] = a - b.matrix[i];
		++i;
	}
	return (res);
}