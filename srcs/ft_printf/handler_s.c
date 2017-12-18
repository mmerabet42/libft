/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:56:04 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/14 18:55:44 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"
#include <wctype.h>

char	*handler_s(va_list lst, t_printf_params params)
{
	char	*gs;
	int		slen;

	if (params.flags[L_MOD])
		return (handler_s_m(lst, params));
	gs = (char *)va_arg(lst, char *);
	if (!gs)
		gs = "(null)";
	slen = ft_strlen(gs);
	if (params.precision_spec && params.precision < slen
			&& params.precision >= 0)
		slen = params.precision;
	gs = ft_strndup(gs, slen);
	return (perform_width(gs, &params));
}

char	*get_proper_gs(wchar_t *ws, t_printf_params *params)
{
	if (ws && params->precision_spec)
	{
		params->precision = ft_wstrnlen(ws, params->precision);
		return (ft_getnwstr(ws, params->precision));
	}
	return (ft_getwstr(ws));
}

char	*handler_s_m(va_list lst, t_printf_params params)
{
	wchar_t	*ws;
	char	*gs;
	char	*str;
	char	*ostr;
	int		slen;

	ws = (wchar_t *)va_arg(lst, wchar_t *);
	if (!(gs = get_proper_gs(ws, &params)) && ws)
		return (NULL);
	str = (gs ? gs : "(null)");
	slen = ft_strlen(str);
	if (params.precision_spec && params.precision < slen)
		slen = params.precision;
	ostr = str;
	str = ft_strndup(ostr, slen);
	if (gs)
		free(ostr); <-- CHANGE THIS
	return (perform_width(str, &params));
}
