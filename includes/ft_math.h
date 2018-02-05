/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:41:25 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/04 21:59:25 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <string.h>

typedef double	(*t_calcfunc)(double a, double b);

typedef struct		s_vec2
{
	int				x;
	int				y;
}					t_vec2;

typedef struct		s_vec3
{
	int				x;
	int				y;
	int				z;
}					t_vec3;

typedef struct		s_vec
{
	int				*vector;
	size_t			dimensions;
}					t_vec;

typedef struct		s_mat
{
	int				*matrix;
	size_t			rows;
	size_t			columns;
}					t_mat;

typedef enum		e_calcmode
{
	OP_ADD, OP_SUB, OP_MULT, OP_DIV
}					t_calcmode;

int					ft_abs(int n);
double				ft_absf(double n);

int					ft_pow(int x, int y);
int					ft_sqrt(int n);

int					ft_max(int a, int b);
int					ft_min(int a, int b);

unsigned int		ft_umax(unsigned int a, unsigned int b);
unsigned int		ft_umin(unsigned int a, unsigned int b);

t_vec				*ft_vec_new(size_t dimensions);
t_vec				*ft_vec_newf(size_t dimensions, int *vector);
t_vec				*ft_vec_newi(size_t dimensions, int scalar);
t_vec				*ft_vec_newn(size_t dimensions, ...);
t_vec				*ft_vec_zero(t_vec *vec);
t_vec				*ft_vec_copy(t_vec *dst, t_vec *src);
t_vec				*ft_vec_dup(t_vec *src);
void				ft_vec_del(t_vec **vec);

void				ft_vec_dump(const t_vec *vec);

t_vec				*ft_vec_opget(size_t dimensions, t_vec *res);

int					*ft_vec_get(const t_vec *vec, size_t x);

t_vec				*ft_vec_add(t_vec a, t_vec b, t_vec *res);
t_vec				*ft_vec_addi(t_vec a, int b, t_vec *res);
t_vec				*ft_vec_iadd(int a, t_vec b, t_vec *res);

t_vec				*ft_vec_sub(t_vec a, t_vec b, t_vec *res);
t_vec				*ft_vec_subi(t_vec a, int b, t_vec *res);
t_vec				*ft_vec_isub(int a, t_vec b, t_vec *res);

t_vec				*ft_vec_mult(t_vec a, t_vec b, t_vec *res);
t_vec				*ft_vec_multi(t_vec a, int b, t_vec *res);
t_vec				*ft_vec_imult(int a, t_vec b, t_vec *res);

t_vec				*ft_vec_div(t_vec a, t_vec b, t_vec *res);
t_vec				*ft_vec_divi(t_vec a, int b, t_vec *res);
t_vec				*ft_vec_idiv(int a, t_vec b, t_vec *res);

t_vec				*ft_vec_calc(t_vec a, t_vec b, t_vec *res, t_calcmode op);
t_vec				*ft_vec_calci(t_vec a, int b, t_vec *res, t_calcmode op);
t_vec				*ft_vec_icalc(int a, t_vec b, t_vec *res, t_calcmode op);

t_mat				*ft_mat_new(size_t rows, size_t columns);
t_mat				*ft_mat_newf(size_t rows, size_t columns, int *mat);
t_mat				*ft_mat_newi(size_t rows, size_t columns, int scalar);
t_mat				*ft_mat_newn(size_t rows, size_t columns, ...);
t_mat				*ft_mat_zero(t_mat *mat);
t_mat				*ft_mat_copy(t_mat *dst, t_mat *src);
t_mat				*ft_mat_dup(t_mat *src);
void				ft_mat_del(t_mat **mat);

void				ft_mat_dump(const t_mat *mat);

t_mat				*ft_mat_opget(size_t rows, size_t cols, t_mat *res);

int					*ft_mat_get(const t_mat *mat, size_t x, size_t y);

t_mat				*ft_mat_add(t_mat a, t_mat b, t_mat *res);
t_mat				*ft_mat_addi(t_mat a, int b, t_mat *res);
t_mat				*ft_mat_iadd(int a, t_mat b, t_mat *res);

t_mat				*ft_mat_sub(t_mat a, t_mat b, t_mat *res);
t_mat				*ft_mat_subi(t_mat a, int b, t_mat *res);
t_mat				*ft_mat_isub(int a, t_mat b, t_mat *res);

t_mat				*ft_mat_mult(t_mat a, t_mat b, t_mat *res);
t_mat				*ft_mat_multi(t_mat a, int b, t_mat *res);
t_mat				*ft_mat_imult(int a, t_mat b, t_mat *res);
t_vec				*ft_mat_multv(t_mat a, t_vec b, t_vec *res);
t_vec				*ft_mat_vmult(t_vec a, t_mat b, t_vec *res);

t_mat				*ft_mat_div(t_mat a, t_mat b, t_mat *res);
t_mat				*ft_mat_divi(t_mat a, int b, t_mat *res);
t_mat				*ft_mat_idiv(int a, t_mat b, t_mat *res);

t_mat				*ft_mat_calc(t_mat a, t_mat b, t_mat *res, t_calcmode op);
t_mat				*ft_mat_calci(t_mat a, int b, t_mat *res, t_calcmode op);
t_mat				*ft_mat_icalc(int a, t_mat b, t_mat *res, t_calcmode op);

https://www.google.fr/imgres?imgurl=http%3A%2F%2Fwww.codinglabs.net%2Fpublic%2Fcontents%2Farticle_world_view_projection_matrix%2Fimages%2FperspMatrix.png&imgrefurl=http%3A%2F%2Fwww.codinglabs.net%2Farticle_world_view_projection_matrix.aspx&docid=E-4UDpZVSYLZNM&tbnid=SNxmHlIvBa14QM%3A&vet=10ahUKEwiukan1y43ZAhVGe8AKHeEbBP0QMwg-KAgwCA..i&w=471&h=151&bih=623&biw=1366&q=perspective%20matrix&ved=0ahUKEwiukan1y43ZAhVGe8AKHeEbBP0QMwg-KAgwCA&iact=mrc&uact=8

https://www.scratchapixel.com/lessons/3d-basic-rendering/perspective-and-orthographic-projection-matrix/building-basic-perspective-projection-matrix

https://www.google.fr/imgres?imgurl=https%3A%2F%2Fs-media-cache-ak0.pinimg.com%2Foriginals%2Fff%2Fb3%2F2b%2Fffb32b24d885ae08b02e16345f7a4b30.jpg&imgrefurl=https%3A%2F%2Fwww.pinterest.fr%2Fpin%2F383580093238051605%2F&docid=DnGKbJAVdkJjSM&tbnid=tr39wZGU-Bsj8M%3A&vet=10ahUKEwiukan1y43ZAhVGe8AKHeEbBP0QMwhCKAwwDA..i&w=469&h=196&itg=1&bih=623&biw=1366&q=perspective%20matrix&ved=0ahUKEwiukan1y43ZAhVGe8AKHeEbBP0QMwhCKAwwDA&iact=mrc&uact=8

https://github.com/ssloy/tinyrenderer/wiki/Lesson-4:-Perspective-projection

https://stackoverflow.com/questions/18404890/how-to-build-perspective-projection-matrix-no-api

https://en.wikipedia.org/wiki/3D_projection
#endif
