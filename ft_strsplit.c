/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 23:09:09 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/15 12:04:59 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char sep)
{
	int	count;
	int	pos;

	count = 0;
	while (s)
	{
		pos = ft_strchr_pos(s, sep);
		if (pos != 0 && s[0])
			++count;
		s = (pos != -1 ? s + (pos + 1) : NULL);
	}
	return (count);
}

char		**ft_strsplit(const char *s, char sep)
{
	char	**t;
	int		sz;
	int		pos;

	if (!s)
		return (NULL);
	t = NULL;
	sz = 0;
	t = (char **)ft_memalloc(sizeof(char *) * (ft_count_words(s, sep) + 1));
	if (t == NULL)
		return (NULL);
	while (s)
	{
		pos = ft_strchr_pos(s, sep);
		if (pos != 0 && s[0])
			t[sz++] = (pos != -1 ? ft_strndup(s, pos) : ft_strdup(s));
		s = (pos != -1 ? s + (pos + 1) : NULL);
	}
	return (t);
}
