/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:21:14 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/02 22:34:15 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_vec	*ft_vec_mult(t_vec a, t_vec b, t_vec *res)
{
	size_t	i;
	size_t	dmin;

	dmin = ft_umin(a.dimensions, b.dimensions);
	if (!res || (res->vector != b.vector && res->vector != a.vector))
		res = ft_vec_opget(dmin, res);
	i = 0;
	while (i < dmin)
	{
		res->vector[i] = a.vector[i] * b.vector[i];
		++i;
	}
	return (res);
}

t_vec	*ft_vec_multi(t_vec a, int b, t_vec *res)
{
	size_t	i;

	if (!res || res->vector != a.vector)
		res = ft_vec_opget(a.dimensions, res);
	i = 0;
	while (i < a.dimensions)
	{
		res->vector[i] = a.vector[i] * b;
		++i;
	}
	return (res);
}
