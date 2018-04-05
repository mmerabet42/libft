/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrkstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:30:18 by mmerabet          #+#    #+#             */
/*   Updated: 2018/04/05 15:24:43 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

int	ft_strpbrkstr_len(const char *a, const char *strset)
{
	int	pos;

	while (*strset)
	{
		pos = ft_strchr_pos(strset, ':');
		if (pos == -1 && ft_strnequ(strset, a, ft_strlen(strset)))
			return (ft_strlen(strset));
		else if (pos != -1 && ft_strnequ(strset, a, pos))
			return (pos);
		strset += (pos == -1 ? ft_strlen(strset) : (size_t)(pos + 1));
	}
	return (0);
}

int	ft_strpbrkstrl_len(const char *a, const char *strset)
{
	int	pos;

	while (*strset)
	{
		pos = ft_strchr_pos(strset, ':');
		if (pos == -1 && ft_strnequl(strset, a, ft_strlen(strset)))
			return (ft_strlen(strset));
		else if (pos != -1 && ft_strnequl(strset, a, pos))
			return (pos);
		strset += (pos == -1 ? ft_strlen(strset) : (size_t)(pos + 1));
	}
	return (0);
}
