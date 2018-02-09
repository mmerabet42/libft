/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 21:04:44 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/09 22:17:59 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"
#include <math.h>

t_mat	*ft_mat_rotatex(float angle)
{
	return (ft_mat_newn(3, 3,
				1, 0, 0,
				0, cos(angle), -sin(angle),
				0, sin(angle), cos(angle)));
}

t_mat	*ft_mat_rotatey(float angle)
{
	return (ft_mat_newn(3, 3,
				cos(angle), 0, sin(angle),
				0, 1, 0,
				-sin(angle), 0, cos(angle)));
}

t_mat	*ft_mat_rotatez(float angle)
{
	return (ft_mat_newn(3, 3,
				cos(angle), -sin(angle), 0,
				sin(angle), cos(angle), 0,
				0, 0, 1));
}

t_mat	*ft_mat_rotate(t_vec eulerAngles)
{
	t_vec3f	c;
	t_vec3f	s;

	if (!eulerAngles.vector || eulerAngles.dimensions < 3)
		return (NULL);
	c.x = cosf(eulerAngles.vector[0]);
	c.y = cosf(eulerAngles.vector[1]);
	c.z = cosf(eulerAngles.vector[2]);
	s.x = sinf(eulerAngles.vector[0]);
	s.y = sinf(eulerAngles.vector[1]);
	s.z = sinf(eulerAngles.vector[2]);
	return (ft_mat_newn(3, 3,
			c.z * c.y, c.z * s.y * s.x - s.z * c.x, c.z * s.y * c.x + s.z * s.x,
			s.z * c.y, s.z * s.y * s.x + c.z * c.x, s.z * s.y * c.x - c.z * s.x,
			-s.y, c.y * s.x, c.y * c.x));
}
