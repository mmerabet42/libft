/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 23:02:14 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/18 23:53:21 by mmerabet         ###   ########.fr       */
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
		if ((bread = ft_memchr_pos(fd->buffer, '\n', fd->len)) == -1)
			bread = fd->len;
		*l = (*l ? ft_memjoin_clr(*l, len, fd->buffer, bread)
				: ft_memdup(fd->buffer, bread));
		if (bread < fd->len)
		{
			fd->len -= bread + 1;
			ft_memcpy(fd->buffer, fd->buffer + (bread + 1), fd->len);
			return (len + bread);
		}
		len += fd->len;
		ft_bzero(fd->buffer, fd->len);
		fd->len = 0;
	}
	if ((fd->len = read(fd->fd, fd->buffer, BUFF_SIZE)) > 0)
		return (inner_get_next_line(fd, l, len));
	if (!*l && fd->len == 0)
		return (-2);
	return (*l ? len : fd->len);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*fds;
	t_fd			*curr_fd;

	if (fd < 0 || !line || !(curr_fd = get_fd(&fds, fd)))
		return (-1);
	*line = NULL;
	return (inner_get_next_line(curr_fd, line, 0));
}
