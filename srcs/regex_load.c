/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 16:24:21 by mmerabet          #+#    #+#             */
/*   Updated: 2018/10/16 16:24:38 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

int	regex_load(t_regex_info *rgxi, t_list **rules)
{
	int			fd;
	char		*str;
	t_list		*fields;

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
	ft_print_groups(fields, 0);
	ft_regex(RGX_FREE, NULL, NULL, &fields);
	free(str);
	if (!fields)
		return (-1);
	return (fd);
}

