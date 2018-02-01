/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 16:21:30 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/01 18:16:43 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include <stdlib.h>
#include "ft_printf.h"

t_mat	*ft_mat_add(t_mat a, t_mat b, t_mat *res)
{
	int	i;
	int	size;

	if (a.size != b.size)
		return (NULL);
	if (!res && !((res = ft_mat_new(a.size))))
		return (NULL);
	res->size = a.size;
	size = a.size * b.size;
	if (!res->matrix && !(res->matrix = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	i = -1;
	while (++i < size)
		res->matrix[i] = a.matrix[i] + b.matrix[i];
	return (res);
}
