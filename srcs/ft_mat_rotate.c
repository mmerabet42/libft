/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 21:04:44 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/13 22:43:10 by mmerabet         ###   ########.fr       */
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

	tfovy = tan((fovy) / 2.f);
	return (ft_mat_newn(4, 4,
				1.f / (tfovy * aspect), 0.f, 0.f, 0.f,
				0.f, 1.f / tfovy, 0.f, 0.f, 0.f,
				0.f, 0.f, -((far + near) / (far - near)), -((2.f * near * far) / (far - near)),
				0.f, 0.f, -1.f, 0.f));
}

GLM_FUNC_QUALIFIER tmat4x4<T, defaultp> perspectiveRH(T fovy, T aspect, T zNear, T zFar)
{
	assert(abs(aspect - std::numeric_limits<T>::epsilon()) > static_cast<T>(0));
	
	T const tanHalfFovy = tan(fovy / static_cast<T>(2));

	tmat4x4<T, defaultp> Result(static_cast<T>(0));
	Result[0][0] = static_cast<T>(1) / (aspect * tanHalfFovy);
	Result[1][1] = static_cast<T>(1) / (tanHalfFovy);
	Result[2][3] = - static_cast<T>(1);

#	if GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE
		Result[2][2] = zFar / (zNear - zFar);
		Result[3][2] = -(zFar * zNear) / (zFar - zNear);
#	else
		Result[2][2] = - (zFar + zNear) / (zFar - zNear);
		Result[3][2] = - (static_cast<T>(2) * zFar * zNear) / (zFar - zNear);
#	endif
	
	return Result;
}

GLM_FUNC_QUALIFIER tmat4x4<T, P> lookAtRH
(
	tvec3<T, P> const & eye,
	tvec3<T, P> const & center,
	tvec3<T, P> const & up
)
{
	tvec3<T, P> const f(normalize(center - eye));
	tvec3<T, P> const s(normalize(cross(f, up)));
	tvec3<T, P> const u(cross(s, f));

	tmat4x4<T, P> Result(1);
	Result[0][0] = s.x;
	Result[1][0] = s.y;
	Result[2][0] = s.z;
	Result[0][1] = u.x;
	Result[1][1] = u.y;
	Result[2][1] = u.z;
	Result[0][2] =-f.x;
	Result[1][2] =-f.y;
	Result[2][2] =-f.z;
	Result[3][0] =-dot(s, eye);
	Result[3][1] =-dot(u, eye);
	Result[3][2] = dot(f, eye);
	return Result;
}
