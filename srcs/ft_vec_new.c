/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:51:49 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/07 21:16:16 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "ft_mem.h"
#include <stdarg.h>

t_vec	*ft_vec_new(size_t dimensions)
{
	t_vec	*vec;

	if (!(vec = (t_vec *)malloc(sizeof(t_vec))))
		return (NULL);
	vec->dimensions = dimensions;
	if (!(vec->vector = (double *)ft_memalloc(sizeof(double) * dimensions)))
	{
		free(vec);
		return (NULL);
	}
	return (vec);
}

t_vec	*ft_vec_newf(size_t dimensions, double *vector)
{
	t_vec	*vec;

	if (!(vec = (t_vec *)malloc(sizeof(t_vec))))
		return (NULL);
	vec->dimensions = dimensions;
	if (!(vec->vector = (double *)ft_memdup((void *)vector,
					sizeof(double) * dimensions)))
	{
		free(vec);
		return (NULL);
	}
	return (vec);
}

t_vec	*ft_vec_newi(size_t dimensions, double scalar)
{
	t_vec	*vec;
	size_t	i;

	if (!(vec = (t_vec *)malloc(sizeof(t_vec))))
		return (NULL);
	vec->dimensions = dimensions;
	if (!(vec->vector = (double *)malloc(sizeof(double) * dimensions)))
	{
		free(vec);
		return (NULL);
	}
	i = 0;
	while (i < dimensions)
	{
		vec->vector[i] = scalar;
		++i;
	}
	return (vec);
}

t_vec	*ft_vec_newn(size_t dimensions, ...)
{
	t_vec	*vec;
	size_t	i;
	va_list	vp;

	if (!(vec = (t_vec *)malloc(sizeof(t_vec))))
		return (NULL);
	vec->dimensions = dimensions;
	if (!(vec->vector = (double *)malloc(sizeof(double) * dimensions)))
	{
		free(vec);
		return (NULL);
	}
	va_start(vp, dimensions);
	i = 0;
	while (i < dimensions)
	{
		vec->vector[i] = va_arg(vp, double);
		++i;
	}
	va_end(vp);
	return (vec);
}

void	ft_vec_del(t_vec **vec)
{
	if (!vec || !*vec)
		return ;
	free((*vec)->vector);
	free(*vec);
	*vec = NULL;
}
