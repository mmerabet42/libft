/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:41:25 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/09 22:36:33 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <string.h>

# define VX vector[0]
# define VY vector[1]
# define VZ vector[2]
# define VW vector[3]

typedef struct		s_vec2
{
	int				x;
	int				y;
}					t_vec2;

typedef struct		s_vec3
{
	float			x;
	float			y;
	float			z;
}					t_vec3;

typedef struct		s_vec3f
{
	float			x;
	float			y;
	float			z;
}					t_vec3f;

typedef struct		s_vec4
{
	float			x;
	float			y;
	float			z;
	float			w;
}					t_vec4;

typedef struct		s_vec
{
	float			*vector;
	size_t			dimensions;
}					t_vec;

typedef enum		e_calcmode
{
	OP_ADD, OP_SUB, OP_MULT, OP_DIV
}					t_calcmode;

int					ft_abs(int n);
float				ft_fabs(float n);

int					ft_pow(int x, int y);
int					ft_sqrt(int n);

int					ft_max(int a, int b);
int					ft_min(int a, int b);

float				ft_fmax(float a, float b);
float				ft_fmin(float a, float b);

unsigned int		ft_umax(unsigned int a, unsigned int b);
unsigned int		ft_umin(unsigned int a, unsigned int b);

t_vec				*ft_vec_new(size_t dimensions);
t_vec				*ft_vec_newf(size_t dimensions, float *vector);
t_vec				*ft_vec_newi(size_t dimensions, float scalar);
t_vec				*ft_vec_newn(size_t dimensions, ...);
t_vec				*ft_vec_zero(t_vec *vec);
t_vec				*ft_vec_copy(t_vec *dst, t_vec *src);
t_vec				*ft_vec_dup(t_vec *src);
void				ft_vec_del(t_vec **vec);

void				ft_vec_dump(const t_vec *vec);

t_vec				*ft_vec_opget(size_t dimensions, t_vec *res);

float				*ft_vec_get(const t_vec *vec, size_t x);

t_vec				*ft_vec_add(t_vec a, t_vec b, t_vec *res);
t_vec				*ft_vec_addi(t_vec a, float b, t_vec *res);
t_vec				*ft_vec_iadd(float a, t_vec b, t_vec *res);

t_vec				*ft_vec_sub(t_vec a, t_vec b, t_vec *res);
t_vec				*ft_vec_subi(t_vec a, float b, t_vec *res);
t_vec				*ft_vec_isub(float a, t_vec b, t_vec *res);

t_vec				*ft_vec_mult(t_vec a, t_vec b, t_vec *res);
t_vec				*ft_vec_multi(t_vec a, float b, t_vec *res);
t_vec				*ft_vec_imult(float a, t_vec b, t_vec *res);

t_vec				*ft_vec_div(t_vec a, t_vec b, t_vec *res);
t_vec				*ft_vec_divi(t_vec a, float b, t_vec *res);
t_vec				*ft_vec_idiv(float a, t_vec b, t_vec *res);

t_vec				*ft_vec_calc(t_vec a, t_vec b, t_vec *res, t_calcmode op);
t_vec				*ft_vec_calci(t_vec a, float b, t_vec *res, t_calcmode op);
t_vec				*ft_vec_icalc(float a, t_vec b, t_vec *res, t_calcmode op);

/*
https://www.google.fr/imgres?imgurl=http%3A%2F%2Fwww.codinglabs.net%2Fpublic%2Fcontents%2Farticle_world_view_projection_matrix%2Fimages%2FperspMatrix.png&imgrefurl=http%3A%2F%2Fwww.codinglabs.net%2Farticle_world_view_projection_matrix.aspx&docid=E-4UDpZVSYLZNM&tbnid=SNxmHlIvBa14QM%3A&vet=10ahUKEwiukan1y43ZAhVGe8AKHeEbBP0QMwg-KAgwCA..i&w=471&h=151&bih=623&biw=1366&q=perspective%20matrix&ved=0ahUKEwiukan1y43ZAhVGe8AKHeEbBP0QMwg-KAgwCA&iact=mrc&uact=8

https://www.scratchapixel.com/lessons/3d-basic-rendering/perspective-and-orthographic-projection-matrix/building-basic-perspective-projection-matrix

https://www.google.fr/imgres?imgurl=https%3A%2F%2Fs-media-cache-ak0.pinimg.com%2Foriginals%2Fff%2Fb3%2F2b%2Fffb32b24d885ae08b02e16345f7a4b30.jpg&imgrefurl=https%3A%2F%2Fwww.pinterest.fr%2Fpin%2F383580093238051605%2F&docid=DnGKbJAVdkJjSM&tbnid=tr39wZGU-Bsj8M%3A&vet=10ahUKEwiukan1y43ZAhVGe8AKHeEbBP0QMwhCKAwwDA..i&w=469&h=196&itg=1&bih=623&biw=1366&q=perspective%20matrix&ved=0ahUKEwiukan1y43ZAhVGe8AKHeEbBP0QMwhCKAwwDA&iact=mrc&uact=8

https://github.com/ssloy/tinyrenderer/wiki/Lesson-4:-Perspective-projection

https://stackoverflow.com/questions/18404890/how-to-build-perspective-projection-matrix-no-api

https://en.wikipedia.org/wiki/3D_projection

https://stackoverflow.com/questions/724219/how-to-convert-a-3d-point-into-2d-perspective-projection

http://www.flipcode.com/archives/Plotting_A_3D_Point_On_A_2D_Screen.shtml*/
#endif
