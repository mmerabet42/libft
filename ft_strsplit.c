/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 23:09:09 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/09 23:44:27 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(const char *s, char sep)
{
	char	**t;
	int		sz;
	int		pos;

	t = NULL;
	sz = 0;
	while (s)
	{
		pos = ft_strchr_pos(s, sep);
		if (pos > 0 || pos == -1)
		{
			t = (char **)ft_realloc_fail(t, sizeof(char *) * (sz + 1));
			t[sz++] = (pos != -1 ? ft_strndup(s, pos) : ft_strdup(s));
		}
		s = (pos != -1 ? s + (pos + 1) : NULL);
	}
	t = (char **)realloc(t, sizeof(char *) * (sz + 1));
	t[sz] = NULL;
	return (t);
}
