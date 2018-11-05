/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 16:24:21 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/05 18:09:22 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"
#include "get_next_line.h"
#include "ft_str.h"
#include <fcntl.h>
#include <unistd.h>

static int	get_attributes(t_regex_match *m, char **name, char **regex)
{
	t_regex_group	*g;
	int				n;

	g = (t_regex_group *)m->groups->content;
	n = (*g->str == '-' ? 2 : 1);
	if (*g->str == '-' && !(*name = ft_strndup(g->str + 1, g->len - 1)))
		return (0);
	else if (*g->str != '-' && !(*name = ft_strndup(g->str, g->len)))
		return (0);
	g = (t_regex_group *)m->groups->next->content;
	if (!(*regex = ft_strndup(g->str + 1, g->len - 2)))
	{
		free(*name);
		return (0);
	}
	return (n);
}

int			regex_load(t_regex_info *rgxi, t_list **rules)
{
	int				fd;
	int				n;
	char			*str;
	t_list			*fields;
	t_list			*it;
	char			*name;
	char			*regex;
	t_regex_match	*m;

	if ((fd = open(rgxi->regex, O_RDONLY)) == -1)
		return (-1);
	str = NULL;
	if (get_next_delimstr(fd, EOF_NEVER_REACH, &str) == -1)
	{
		free(str);
		return (-1);
	}
	(void)rules;
	close(fd);
	fields = NULL;
	fd = ft_regex(RGX_GLOBAL, LOAD_REGEX, str, &fields);
	it = fields;
	while (it)
	{
		m = (t_regex_match *)it->content;
		name = NULL;
		regex = NULL;
		if (!(n = get_attributes((t_regex_match *)it->content, &name, &regex)))
			return (-1);
		if (ft_regex(RGX_ADD | RGX_READABLE | (n == 2 ? RGX_ID : 0), name, regex, NULL, -2) == -1)
		{
			free(name);
			free(regex);
			return (-1);
		}
		(*rules)->content_size = 0;
		it = it->next;
	}
	ft_regex(RGX_FREE, NULL, NULL, &fields);
	free(str);
	return (fd);
}
