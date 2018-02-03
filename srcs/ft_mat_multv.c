/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_multv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:29:05 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/03 22:43:23 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include <stdlib.h>

t_vec	*ft_mat_multv(t_mat a, t_vec b, t_vec *res)
{
	size_t	i;
	size_t	j;
	int		*tmp;

	tmp = NULL;
	if (a.columns != b.dimensions)
		return (NULL);
	if (res && res->vector == b.vector && a.rows != res->dimensions)
	{
		res->dimensions = a.rows;
		tmp = res->vector;
		if (!(res->vector = (int *)malloc(sizeof(int) * a.rows)))
			res->vector = b.vector;
	}
	else
		res = ft_vec_opget(a.rows, res);
	i = 0;
	while (i < a.rows)
	{
		res->vector[i] = 0;
		j = 0;
		while (j < a.columns)
		{
			res->vector[i] += *ft_vec_get(&b, j) * *ft_mat_get(&a, j, i);
			++j;
		}
		++i;
	}
	free(tmp);
	return (res);
}
