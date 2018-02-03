/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:41:25 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/03 16:59:47 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <string.h>

typedef double	(*t_calcfunc)(double a, double b);

typedef struct	s_vec2
{
	int			x;
	int			y;
}				t_vec2;

typedef struct	s_vec3
{
	int			x;
	int			y;
	int			z;
}				t_vec3;

typedef struct	s_vec
{
	int			*vector;
	size_t		dimensions;
}				t_vec;

typedef struct	s_mat
{
	int			*matrix;
	size_t		rows;
	size_t		columns;
}				t_mat;

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
void				ft_vec_del(t_vec **vec);

void				ft_vec_dump(const t_vec *vec);

t_vec				*ft_vec_opget(size_t dimensions, t_vec *res);

t_vec				*ft_vec_add(t_vec a, t_vec b, t_vec *res);
t_vec				*ft_vec_addi(t_vec a, int b, t_vec *res);

t_vec				*ft_vec_sub(t_vec a, t_vec b, t_vec *res);
t_vec				*ft_vec_subi(t_vec a, int b, t_vec *res);

t_vec				*ft_vec_mult(t_vec a, t_vec b, t_vec *res);
t_vec				*ft_vec_multi(t_vec a, int b, t_vec *res);

t_mat				*ft_mat_new(size_t rows, size_t columns);
t_mat				*ft_mat_newf(size_t rows, size_t columns, int *mat);
t_mat				*ft_mat_newi(size_t rows, size_t columns, int scalar);
t_mat				*ft_mat_newn(size_t rows, size_t columns, ...);
void				ft_mat_del(t_mat **mat);

void				ft_mat_dump(const t_mat *mat);

t_mat				*ft_mat_opget(size_t rows, size_t cols, t_mat *res);

int					*ft_mat_get(t_mat *mat, size_t x, size_t y);

t_mat				*ft_mat_add(t_mat a, t_mat b, t_mat *res);
t_mat				*ft_mat_addi(t_mat a, int b, t_mat *res);

t_mat				*ft_mat_sub(t_mat a, t_mat b, t_mat *res);
t_mat				*ft_mat_subi(t_mat a, int b, t_mat *res);

t_mat				*ft_mat_mult(t_mat a, t_mat b, t_mat *res);
t_mat				*ft_mat_multi(t_mat a, int scalar, t_mat *res);
t_vec				*ft_mat_multv(t_mat a, t_vec b, t_vec *res);

#endif
