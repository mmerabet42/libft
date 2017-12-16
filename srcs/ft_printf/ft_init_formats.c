/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_formats.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 22:52:10 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/16 20:34:28 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

static void		ft_init_bonuses(void)
{
	ft_printf_add_format("f", handler_f);
	ft_printf_add_format("F", handler_f);
	ft_printf_add_format("b", handler_b);
	ft_printf_add_format("y", handler_y);
	ft_printf_add_format("{", handler_color);
	ft_printf_add_format("n", handler_n);
}

void			ft_init_formats(void)
{
	static int	frst_call;

	if (!frst_call)
	{
		frst_call = 1;
		ft_printf_add_format("s", handler_s);
		ft_printf_add_format("S", handler_s_m);
		ft_printf_add_format("p", handler_p);
		ft_printf_add_format("d", handler_d);
		ft_printf_add_format("D", handler_d_m);
		ft_printf_add_format("i", handler_d);
		ft_printf_add_format("o", handler_o);
		ft_printf_add_format("O", handler_o_m);
		ft_printf_add_format("u", handler_u);
		ft_printf_add_format("U", handler_u_m);
		ft_printf_add_format("x", handler_x);
		ft_printf_add_format("X", handler_x_m);
		ft_printf_add_format("c", handler_c);
		ft_printf_add_format("C", handler_c_m);
		ft_init_bonuses();
	}
}
