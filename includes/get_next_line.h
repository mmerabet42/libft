/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 22:48:49 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/17 19:45:48 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 64

# include "libft.h"

typedef struct	s_fd
{
	int			fd;
	int			len;
	char		buffer[BUFF_SIZE + 1];
}				t_fd;

int				get_next_line(const int fd, char **line);

#endif
