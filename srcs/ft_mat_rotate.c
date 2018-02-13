/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 21:04:44 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/13 14:44:31 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"
#include <math.h>

t_mat	*ft_mat_rotatex(float angle)
{
	float	cangle;
	float	sangle;

	cangle = cosf(angle * M_PI / 180.f);
	sangle = sinf(angle * M_PI / 180.f);
	return (ft_mat_newn(4, 4,
				1.f, 0.f, 0.f, 0.f,
				0.f, cangle, -sangle, 0.f,
				0.f, sangle, cangle, 0.f,
				0.f, 0.f, 0.f, 1.f));
}

t_mat	*ft_mat_rotatey(float angle)
{
	float	cangle;
	float	sangle;

	cangle = cosf(angle * M_PI / 180.f);
	sangle = sinf(angle * M_PI / 180.f);
	return (ft_mat_newn(4, 4,
				cangle, 0.f, sangle, 0.f,
				0.f, 1.f, 0.f, 0.f,
				-sangle, 0.f, cangle, 0.f,
				0.f, 0.f, 0.f, 1.f));
}

t_mat	*ft_mat_rotatez(float angle)
{
	float	cangle;
	float	sangle;

	cangle = cosf(angle * M_PI / 180.f);
	sangle = sinf(angle * M_PI / 180.f);
	return (ft_mat_newn(4, 4,
				cangle, -sangle, 0.f, 0.f,
				sangle, cangle, 0.f, 0.f,
				0.f, 0.f, 1.f, 0.f,
				0.f, 0.f, 0.f, 1.f));
}

t_mat	*ft_mat_rotate(t_vec eulerAngles)
{
	t_mat	*res;
	t_mat	*rotx;
	t_mat	*roty;
	t_mat	*rotz;

	if (!eulerAngles.vector || eulerAngles.dimensions < 3)
		return (NULL);
	rotx = ft_mat_rotatex(eulerAngles.vector[0]);
	roty = ft_mat_rotatey(eulerAngles.vector[1]);
	rotz = ft_mat_rotatez(eulerAngles.vector[2]);
	res = ft_mat_mult(*rotz, *roty, NULL);
	ft_mat_mult(*res, *rotx, res);
	ft_mat_del(&rotx);
	ft_mat_del(&roty);
	ft_mat_del(&rotz);
	return (res);
}

t_mat	*ft_mat_scale(t_vec scale)
{
	if (!scale.vector || scale.dimensions < 3)
		return (NULL);
	return (ft_mat_newn(4, 4,
				scale.vector[0], 0.f, 0.f, 0.f,
				0.f, scale.vector[1], 0.f, 0.f,
				0.f, 0.f, scale.vector[2], 0.f,
				0.f, 0.f, 0.f, 1.f));
}

t_mat	*ft_mat_translate(t_vec translate)
{
	if (!translate.vector || translate.dimensions < 3)
		return (NULL);
	return (ft_mat_newn(4, 4,
				1.f, 0.f, 0.f, translate.vector[0],
				0.f, 1.f, 0.f, translate.vector[1],
				0.f, 0.f, 1.f, translate.vector[2],
				0.f, 0.f, 0.f, 1.f));
}

t_mat	*ft_mat_projection(float fovy, float aspect, float near, float far)
{
	float	tfovy;

	tfovy = tan((fovy * M_PI / 180.f) / 2.f);
	return (ft_mat_newn(4, 4,
				1.f / (tfovy * aspect), 0.f, 0.f, 0.f,
				0.f, 1.f / tfovy, 0.f, 0.f,
				0.f, 0.f, (far + near) / (near - far), (2 * near * far) / (near * far),
				0.f, 0.f, -1.f, 0.f));
}