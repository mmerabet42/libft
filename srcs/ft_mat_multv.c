/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_multv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:29:05 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/02 16:37:25 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_mat	*ft_mat_multv(t_mat a, t_vec b, t_vec *res)
{
	size_t	i;
	size_t	j;

	if (a.columns == b.dimensions)
		return (NULL);
	res = ft_vec_opget(a.rows, res);
	while (i < a.rows)
	{
		
	}
}
