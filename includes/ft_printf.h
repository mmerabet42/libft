/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:38:59 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/16 20:47:57 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct	s_ret
{
	char		*buf;
	int			len;
	int			err;
}				t_ret;

typedef struct	s_pcur
{
	va_list		ap;
	va_list		ap_cur;
}				t_pcur;

int				ft_printf(const char *format, ...);
int				ft_printf_fd(int fd, const char *format, ...);
int				ft_printf_s(char **buffer, const char *format, ...);

int				ft_vprintf(const char *format, va_list ap);
int				ft_vprintf_fd(int fd, const char *format, va_list ap);
int				ft_vprintf_s(char **buffer, const char *format, va_list ap);
t_ret			ft_inner_printf(const char *format, t_pcur *ap);

#endif
