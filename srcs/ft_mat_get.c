/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 21:10:27 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/02 15:03:44 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	*ft_mat_get(t_mat *mat, size_t x, size_t y)
{
	if(!mat || !mat->matrix)
		return ((void *)0);
/*	while (x >= mat->columns)
		x -= mat->columns;
	while (y >= mat->rows)
		y += mat->rows;*/
	return (mat->matrix + (x + mat->columns * y));
}
