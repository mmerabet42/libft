/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 14:44:01 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/01 23:25:06 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "ft_mem.h"
#include <stdarg.h>

t_mat	*ft_mat_new(size_t rows, size_t columns)
{
	t_mat	*nmat;
	size_t	i;

	if (!(nmat = (t_mat *)malloc(sizeof(t_mat))))
		return (NULL);
	nmat->columns = columns;
	nmat->rows = rows;
	columns *= rows;
	if (!(nmat->matrix = (int *)malloc(sizeof(int) * columns)))
	{
		free(nmat);
		return (NULL);
	}
	i = 0;
	while (i < columns)
		nmat->matrix[i++] = 0;
	return (nmat);
}

t_mat	*ft_mat_newf(size_t rows, size_t columns, int *mat)
{
	t_mat	*nmat;

	if (!(nmat = (t_mat *)malloc(sizeof(t_mat))))
		return (NULL);
	nmat->columns = columns;
	nmat->rows = rows;
	columns *= rows;
	if (!(nmat->matrix = (int *)ft_memdup((void *)mat, sizeof(int) * columns)))
	{
		free(nmat);
		return (NULL);
	}
	return (nmat);
}

t_mat	*ft_mat_newi(size_t rows, size_t columns, int scalar)
{
	t_mat	*nmat;
	size_t	i;
	size_t	x;
	size_t	y;

	if (!(nmat = (t_mat *)malloc(sizeof(t_mat))))
		return (NULL);
	nmat->columns = columns;
	nmat->rows = rows;
	columns *= rows;
	if (!(nmat->matrix = (int *)malloc(sizeof(int) * columns)))
	{
		free(nmat);
		return (NULL);
	}
	i = 0;
	if (nmat->columns == nmat->rows)
	{
		y = 0;
	}
	else
		while (i < columns)
			nmat->matrix[i++] = scalar;
	return (nmat);
}

t_mat	*ft_mat_newn(size_t rows, size_t columns, ...)
{
	va_list	vp;
	t_mat	*nmat;
	size_t	i;

	va_start(vp, columns);
	if (!(nmat = (t_mat *)malloc(sizeof(t_mat))))
	{
		va_end(vp);
		return (NULL);
	}
	nmat->columns = columns;
	nmat->rows = rows;
	columns *= rows;
	if (!(nmat->matrix = (int *)malloc(sizeof(int) * columns)))
	{
		free(nmat);
		va_end(vp);
		return (NULL);
	}
	i = 0;
	while (i < columns)
		nmat->matrix[i++] = va_arg(vp, int);
	va_end(vp);
	return (nmat);
}

void	ft_mat_del(t_mat **mat)
{
	if (!mat || !*mat)
		return ;
	free((*mat)->matrix);
	free(*mat);
	*mat = NULL;
}
