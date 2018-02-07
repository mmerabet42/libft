/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmax.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 18:00:20 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/07 21:26:33 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

double	ft_fmax(double a, double b)
{
	return (a > b ? a : b);
}

double	ft_fmin(double a, double b)
{
	return (a < b ? a : b);
}
