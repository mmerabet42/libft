/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 23:02:14 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/17 19:43:43 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static int	fdcmp(const void *a, const void *b, size_t n)
{
	(void)n;
	return (((t_fd *)a)->fd - ((t_fd *)b)->fd);
}

static t_fd	*get_fd(t_list **lst, int fd)
{
	t_list	*lst_fd;
	t_fd	tmp_fd;

	tmp_fd.fd = fd;
	if (!(lst_fd = ft_lstfindf(*lst, &tmp_fd, sizeof(t_fd), fdcmp)))
	{
		ft_bzero(tmp_fd.buffer, BUFF_SIZE + 1);
		tmp_fd.len = 0;
		lst_fd = ft_lstpush(*lst, ft_lstnew(&tmp_fd, sizeof(t_fd)));
		if (*lst == NULL)
			*lst = lst_fd;
	}
	return ((t_fd *)lst_fd->content);
}

static int	inner_get_next_line(t_fd *fd, char **l, int len)
{
	int			bread;

	if (fd->len > 0)
	{
		if ((bread = ft_strchr_pos(fd->buffer, '\n')) != -1)
			fd->buffer[bread] = '\0';
		*l = (*l ? ft_strjoin_clr(*l, fd->buffer, 0) : ft_strdup(fd->buffer));
		if (bread != -1 && ft_strcpy(fd->buffer, fd->buffer + (bread + 1)))
		{
			fd->len -= bread + 1;
			return (len + bread);
		}
		cur_len += fd->len;
		ft_strclr(fd->buffer);
	}
	if ((bread = read(fd->fd, fd->buffer, BUFF_SIZE)) > 0)
	{
		fd->buffer[bread] = '\0';
		fd->len = bread;
		return (inner_get_next_line(fd, l, len));
	}
	return (*line ? len : bread);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*fds;
	t_fd			*curr_fd;

	if (fd < 0 || !line || !(curr_fd = get_fd(&fds, fd)))
		return (-1);
	*line = NULL;
	curr_fd->len = 0;
	return (inner_get_next_line(curr_fd, line, 0));
}
