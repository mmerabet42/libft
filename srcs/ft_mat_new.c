/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 14:44:01 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/01 18:10:50 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "ft_mem.h"
#include <stdarg.h>

t_mat	*ft_mat_new(int size)
{
	t_mat	*nmat;
	int		i;

	if (!(nmat = (t_mat *)malloc(sizeof(t_mat))))
		return (NULL);
	nmat->size = size;
	size *= size;
	if (!(nmat->matrix = (int *)malloc(sizeof(int) * size)))
	{
		free(nmat);
		return (NULL);
	}
	i = 0;
	while (i < size)
		nmat->matrix[i++] = 0;
	return (nmat);
}

t_mat	*ft_mat_newf(int size, int *mat)
{
	t_mat	*nmat;

	if (!(nmat = (t_mat *)malloc(sizeof(t_mat))))
		return (NULL);
	nmat->size = size;
	size *= size;
	if (!(nmat->matrix = (int *)ft_memdup((void *)mat, sizeof(int) * size)))
	{
		free(nmat);
		return (NULL);
	}
	return (nmat);
}

t_mat	*ft_mat_newi(int size, int scalar)
{
	t_mat	*nmat;
	int		i;

	if (!(nmat = (t_mat *)malloc(sizeof(t_mat))))
		return (NULL);
	nmat->size = size;
	size *= size;
	if (!(nmat->matrix = (int *)malloc(sizeof(int) * size)))
	{
		free(nmat);
		return (NULL);
	}
	i = 0;
	while (i < size)
		nmat->matrix[i++] = scalar;
	return (nmat);
}

t_mat	*ft_mat_newn(int size, ...)
{
	va_list	vp;
	t_mat	*nmat;
	int		i;

	va_start(vp, size);
	if (!(nmat = (t_mat *)malloc(sizeof(t_mat))))
		return (NULL);
	nmat->size = size;
	size *= size;
	if (!(nmat->matrix = (int *)malloc(sizeof(int) * size)))
	{
		free(nmat);
		return (NULL);
	}
	i = 0;
	while (i < size)
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
