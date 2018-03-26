/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrkstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:30:18 by mmerabet          #+#    #+#             */
/*   Updated: 2018/03/26 21:14:20 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

int	ft_strpbrkstr(const char *a, const char *strset)
{
	int	pos;

	while (*strset)
	{
		pos = ft_strchr_pos(strset, ':');
		if (pos == -1 && ft_strnequ(strset, a, ft_strlen(strset)))
			return (ft_strlen(strset));
		else if (pos != -1 && ft_strnequ(strset, a, pos))
			return (pos);
		strset += (pos == -1 ? ft_strlen(strset) : pos + 1);
	}
	return (0);
}
