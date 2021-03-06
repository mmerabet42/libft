/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 22:48:49 by mmerabet          #+#    #+#             */
/*   Updated: 2018/10/29 18:55:17 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 65536
# define EOF_NEVER_REACH "\01\02\033\033[EOFEOF]\n"

typedef struct	s_fd
{
	int			fd;
	int			len;
	char		buffer[BUFF_SIZE + 1];
}				t_fd;

int				get_next_line(const int fd, char **line);
int				get_next_delim(const int fd, char delim, char **line);
int				get_next_delimstr(const int fd, const char *delim, char **line);

#endif
