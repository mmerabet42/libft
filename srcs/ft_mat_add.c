/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 16:21:30 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/02 16:39:56 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include <stdlib.h>
#include "ft_printf.h"

t_mat	*ft_mat_opget(size_t rows, size_t columns, t_mat *res)
{
	int	allocated;

	allocated = 0;
	if (!res)
	{
		if (!(res = ft_mat_new(rows, columns)))
			return (NULL);
		allocated = 1;
	}
	res->columns = columns;
	res->rows = rows;
	columns *= rows;
	if (!allocated && !(res->matrix = (int *)malloc(sizeof(int) * columns)))
		return (NULL);
	return (res);
}

t_mat	*ft_mat_add(t_mat a, t_mat b, t_mat *res)
{
	size_t	i;
	size_t	size;
	
	if (a.columns != b.columns || a.rows != b.rows)
		return (NULL);
	res = ft_mat_opget(a.rows, b.columns, res);
	size = a.columns * b.rows;
	i = 0;
	while (i < size)
	{
		res->matrix[i] = a.matrix[i] + b.matrix[i];
		++i;
	}
	return (res);
}

t_mat	*ft_mat_addi(t_mat a, int b, t_mat *res)
{
	size_t	i;
	size_t	size;
	
	res = ft_mat_opget(a.rows, a.columns, res);
	size = a.rows * a.columns;
	i = 0;
	while (i < size)
	{
		res->matrix[i] = a.matrix[i] + b;
		++i;
	}
	return (res);
}

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
