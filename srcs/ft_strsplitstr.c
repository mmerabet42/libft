/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 23:44:34 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/15 12:04:44 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, const char *sep)
{
	int	count;
	int	pos;
	int	seplen;

	seplen = ft_strlen(sep);
	count = 0;
	while (s)
	{
		pos = ft_strstr_pos(s, sep);
		if (pos != 0 && s[0])
			++count;
		s = (pos != -1 ? s + (pos + seplen) : NULL);
	}
	return (count);
}

char		**ft_strsplitstr(const char *s, const char *sep)
{
	char	**t;
	int		sz;
	int		pos;
	size_t	seplen;

	if (!s || !sep)
		return (NULL);
	seplen = ft_strlen(sep);
	t = (char **)ft_memalloc(sizeof(char *) * (ft_count_words(s, sep) + 1));
	if (t == NULL)
		return (NULL);
	sz = 0;
	while (s)
	{
		pos = ft_strstr_pos(s, sep);
		if (pos != 0 && s[0])
			t[sz++] = (pos != -1 ? ft_strndup(s, pos) : ft_strdup(s));
		s = (pos != -1 ? s + (pos + seplen) : NULL);
	}
	return (t);
}
