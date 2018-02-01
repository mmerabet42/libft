/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:41:25 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/01 23:25:10 by mmerabet         ###   ########.fr       */
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

#endif
