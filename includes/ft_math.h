/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:41:25 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/01 18:16:40 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

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
	int			size;
}				t_mat;

int					ft_abs(int n);
double				ft_absf(double n);

int					ft_pow(int x, int y);
int					ft_sqrt(int n);

int					ft_max(int a, int b);
int					ft_min(int a, int b);

t_mat				*ft_mat_new(int size);
t_mat				*ft_mat_newf(int size, int *mat);
t_mat				*ft_mat_newi(int size, int scalar);
t_mat				*ft_mat_newn(int size, ...);
void				ft_mat_del(t_mat **mat);

void				ft_mat_dump(const t_mat *mat);

t_mat				*ft_mat_add(t_mat a, t_mat b, t_mat *res);
t_mat				*ft_mat_sub(t_mat a, t_mat b, t_mat *res);

#endif
