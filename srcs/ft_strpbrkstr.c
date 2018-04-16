/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrkstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:30:18 by mmerabet          #+#    #+#             */
/*   Updated: 2018/04/16 17:45:42 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

int	g_iread;

int	ft_strpbrkstr_len(const char *a, const char *strset)
{
	int		pos;
	int		len;
	char	*tmp;

	while (*strset)
	{
		pos = ft_strchrl_pos(strset, ':');
		len = (pos == -1 ? ft_strlen(strset) : pos);
		if (!(tmp = ft_strndup(strset, len + 1)))
			return (0);
		tmp[len] = '*';
		if (ft_strmatch(a, tmp) && ft_memdel((void **)&tmp))
			return (g_iread);
		free(tmp);
		strset += (pos == -1 ? ft_strlen(strset) : (size_t)(pos + 1));
	}
	return (0);
}

int	ft_strpbrkstrl_len(const char *a, const char *strset)
{
	int		pos;
	int		len;
	char	*tmp;

	while (*strset)
	{
		pos = ft_strchrl_pos(strset, ':');
		len = (pos == -1 ? ft_strlen(strset) : pos);
		if (!(tmp = ft_strndup(strset, len + 1)))
			return (0);
		tmp[len] = '*';
		if (ft_strmatchl(a, tmp) && ft_memdel((void **)&tmp))
			return (g_iread);
		free(tmp);
		strset += (pos == -1 ? ft_strlen(strset) : (size_t)(pos + 1));
	}
	return (0);
}

int	ft_strpbrkstr_pos(const char *a, const char *strset)
{
	int	pos;

	pos = 0;
	while (a[pos])
	{
		if (ft_strpbrkstr_len(&a[pos], strset))
			return (pos);
		++pos;
	}
	return (-1);
}

int	ft_strpbrkstrl_pos(const char *a, const char *strset)
{
	int	pos;

	pos = 0;
	while (a[pos])
	{
		if (ft_strpbrkstrl_len(&a[pos], strset))
			return (pos);
		++pos;
	}
	return (-1);
}
