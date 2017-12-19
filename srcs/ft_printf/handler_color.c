/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 22:49:13 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/18 23:53:20 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

static char	*get_color_above(char *tcolor, int fb)
{
	if (ft_strequ(tcolor, "dgray"))
		return (!fb ? "\e[90m" : "\e[100m");
	else if (ft_strequ(tcolor, "lred"))
		return (!fb ? "\e[91m" : "\e[101m");
	else if (ft_strequ(tcolor, "lgreen"))
		return (!fb ? "\e[92m" : "\e[102m");
	else if (ft_strequ(tcolor, "lyellow"))
		return (!fb ? "\e[93m" : "\e[103m");
	else if (ft_strequ(tcolor, "lblue"))
		return (!fb ? "\e[94m" : "\e[104m");
	else if (ft_strequ(tcolor, "lmagenta"))
		return (!fb ? "\e[95m" : "\e[105m");
	else if (ft_strequ(tcolor, "lcyan"))
		return (!fb ? "\e[96m" : "\e[106m");
	else if (ft_strequ(tcolor, "white"))
		return (!fb ? "\e[97m" : "\e[107m");
	else if (ft_strequ(tcolor, "invert"))
		return ("\e[7m");
	else if (ft_strequ(tcolor, "hide"))
		return ("\e[8m");
	else if (ft_strequ(tcolor, "eoc") || ft_strequ(tcolor, "0"))
		return ("\e[0m");
	return ("");
}

static char	*get_color(char *tcolor, int fb)
{
	if (ft_strequ(tcolor, "black"))
		return (!fb ? "\e[30m" : "\e[40m");
	else if (ft_strequ(tcolor, "red"))
		return (!fb ? "\e[31m" : "\e[41m");
	else if (ft_strequ(tcolor, "green"))
		return (!fb ? "\e[32m" : "\e[42m");
	else if (ft_strequ(tcolor, "yellow"))
		return (!fb ? "\e[33m" : "\e[43m");
	else if (ft_strequ(tcolor, "blue"))
		return (!fb ? "\e[34m" : "\e[44m");
	else if (ft_strequ(tcolor, "magenta"))
		return (!fb ? "\e[35m" : "\e[45m");
	else if (ft_strequ(tcolor, "cyan"))
		return (!fb ? "\e[36m" : "\e[46m");
	else if (ft_strequ(tcolor, "lgray"))
		return (!fb ? "\e[37m" : "\e[47m");
	else if (ft_strequ(tcolor, "bold"))
		return ("\e[1m");
	else if (ft_strequ(tcolor, "dim"))
		return ("\e[2m");
	else if (ft_strequ(tcolor, "underlined"))
		return ("\e[4m");
	return (get_color_above(tcolor, fb));
}

static char	*perform_color(char *tcolor, t_printf_params params)
{
	char	esc_fb[12];
	char	*final_color;

	if (params.flags[MINUS_FLAG])
	{
		free(tcolor);
		return (ft_strdup("\e[0m"));
	}
	ft_strcpy(esc_fb, "\e[38;2;");
	if (params.width > 0)
		ft_strncpy(esc_fb + 2, "48", 2);
	if (params.precision > 0)
		final_color = ft_strjoin_clr(esc_fb, ft_strjoinc(tcolor, 'm'), 1);
	else
		final_color = ft_strdup(get_color(tcolor, params.width));
	free(tcolor);
	return (final_color);
}

char		*handler_color(va_list lst, t_printf_params params)
{
	char	*color;
	char	*tcolor;
	int		pos;

	(void)lst;
	if ((pos = ft_strchr_pos(*params.format, '}')) == -1)
		return (ft_strdup("{"));
	if (params.flags[HASH_FLAG])
		params.width = 1;
	if (params.flags[L_MOD])
		params.precision = 1;
	color = ft_strndup(*params.format, pos);
	*params.format += pos + 1;
	tcolor = ft_inner_printf(color, params.pcur).buf;
	free(color);
	return (perform_color(ft_strtrim_clr(tcolor), params));
}
