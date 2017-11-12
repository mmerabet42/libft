/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 23:44:34 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/12 17:34:13 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplitstr(const char *s, const char *sep)
{
	char	**t;
	int		sz;
	int		pos;
	size_t	seplen;

	seplen = ft_strlen(sep);
	t = NULL;
	sz = 0;
	while (s)
	{
		pos = ft_strstr_pos(s, sep);
		if (pos > 0 || pos == -1)
		{
			t = (char **)ft_realloc_fail(t, sizeof(char *) * (sz + 1));
			t[sz++] = (pos != -1 ? ft_strndup(s, pos) : ft_strdup(s));
		}
		s = (pos != -1 ? s + (pos + seplen) : NULL);
	}
	t = (char **)realloc(t, sizeof(char *) * (sz + 1));
	t[sz] = NULL;
	return (t);
}
