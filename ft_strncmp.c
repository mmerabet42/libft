/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:48:04 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/12 19:35:35 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *a, const char *b, size_t n)
{
	const unsigned char	*ua;
	const unsigned char *ub;
	size_t				i;

	ua = (const unsigned char *)a;
	ub = (const unsigned char *)b;
	i = 0;
	while (i < n - 1 && (*ua && *ub) && (*ua == *ub))
	{
		++ua;
		++ub;
	}
	return ((int)(*ua - *ub));
}
