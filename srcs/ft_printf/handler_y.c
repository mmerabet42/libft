/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_q.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:58:10 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/16 20:56:22 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

char	*handler_y(va_list lst, t_printf_params params)
{
	char				*str;
	char				*base;
	unsigned long long	n;

	n = proper_cast_u(lst, params);
	base = (char *)va_arg(lst, char *);
	if (params.precision_spec && params.precision == 0 && n == 0)
		str = ft_strnew(0);
	else
		str = ft_ulltoa_cbase(n, base);
	return (perform_width(pad_zeroes(str, &params), &params));
}
