/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 16:24:21 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/16 16:27:54 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"
#include "get_next_line.h"
#include "ft_str.h"
#include "ft_mem.h"
#include <fcntl.h>
#include <unistd.h>

static int	get_attributes(t_regex_match *m, char **names)
{
	t_regex_group	*g;
	int				n;

	g = (t_regex_group *)m->groups->content;
	n = 1;
	if (*g->str == '-' || *g->str == '#')
		n = (*g->str == '-' ? 2 : 3);
	if (n > 1 && !(names[0] = ft_strndup(g->str + 1, g->len - 1)))
		return (0);
	else if (n == 1 && !(names[0] = ft_strndup(g->str, g->len)))
		return (0);
	g = (t_regex_group *)m->groups->next->content;
	if (!(names[1] = ft_strndupk(g->str + 1, g->len - 2)))
	{
		free(names[0]);
		return (0);
	}
	return (n);
}

static int	import_add(int ret, char **names, t_list **rules)
{
	int	flg;

	flg = RGX_READABLE | RGX_TO | (ret == 2 ? RGX_ID : 0);
	if (ret == 3)
	{
		ret = ft_regex(RGX_IMPORT | flg, names[1], NULL, rules);
		free(names[0]);
		free(names[1]);
		if (ret == -1)
			return (-1);
	}
	else if (ft_regex(RGX_ADD | flg, names[0], names[1], rules, NULL, -2) == -1)
	{
		free(names[0]);
		free(names[1]);
		return (-1);
	}
	else
		(*rules)->content_size = 0;
	return (0);
}

static int	interpret_fields(t_list *fields, t_list **rules)
{
	char	*names[2];
	int		ret;

	while (fields)
	{
		ft_bzero(names, sizeof(char *) * 2);
		ret = get_attributes((t_regex_match *)fields->content, names);
		if (!ret)
			return (-1);
		if (import_add(ret, names, rules) == -1)
			return (-1);
		fields = fields->next;
	}
	return (0);
}

int			regex_load(t_regex_info *rgxi, t_list **rules)
{
	int		fd;
	char	*str;
	t_list	*fields;

	if ((fd = open(rgxi->regex, O_RDONLY)) == -1)
		return (-1);
	str = NULL;
	if (get_next_delimstr(fd, EOF_NEVER_REACH, &str) == -1)
	{
		free(str);
		close(fd);
		return (-1);
	}
	close(fd);
	fields = NULL;
	fd = ft_regex(RGX_GLOBAL, LOAD_REGEX, str, &fields);
	if (interpret_fields(fields, rules) == -1)
		fd = -1;
	ft_regex(RGX_FREE, NULL, NULL, &fields);
	free(str);
	return (fd);
}
