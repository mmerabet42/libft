/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:08:11 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/02 22:38:31 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include <stdlib.h>

t_vec	*ft_vec_opget(size_t dimensions, t_vec *res)
{
	int	allocated;

	allocated = 0;
	if (!res)
	{
		if (!(res = ft_vec_new(dimensions)))
			return (NULL);
		allocated = 1;
	}
	res->dimensions = dimensions;
	if (!allocated && !(res->vector = (int *)malloc(sizeof(int) * dimensions)))
		return (NULL);
	return (res);
}

t_vec	*ft_vec_add(t_vec a, t_vec b, t_vec *res)
{
	size_t	i;
	size_t	dmin;

	dmin = ft_umin(a.dimensions, b.dimensions);
	if (!res || (res->vector != b.vector && res->vector != a.vector))
		res = ft_vec_opget(dmin, res);
	i = 0;
	while (i < dmin)
	{
		res->vector[i] = a.vector[i] + b.vector[i];
		++i;
	}
	return (res);
}

t_vec	*ft_vec_addi(t_vec a, int b, t_vec *res)
{
	size_t	i;

	if (!res || res->vector != a.vector)
		res = ft_vec_opget(a.dimensions, res);
	i = 0;
	while (i < a.dimensions)
	{
		res->vector[i] = a.vector[i] + b;
		++i;
	}
	return (res);
}

t_vec	*ft_vec_sub(t_vec a, t_vec b, t_vec *res)
{
	size_t	i;
	size_t	dmin;

	dmin = ft_umin(a.dimensions, b.dimensions);
	if (!res || (res->vector != b.vector && res->vector != a.vector))
		res = ft_vec_opget(dmin, res);
	i = 0;
	while (i < dmin)
	{
		res->vector[i] = a.vector[i] - b.vector[i];
		++i;
	}
	return (res);
}

t_vec	*ft_vec_subi(t_vec a, int b, t_vec *res)
{
	size_t	i;

	if (!res || res->vector != a.vector)
		res = ft_vec_opget(a.dimensions, res);
	i = 0;
	while (i < a.dimensions)
	{
		res->vector[i] = a.vector[i] - b;
		++i;
	}
	return (res);
}
