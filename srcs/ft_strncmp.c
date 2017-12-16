/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:48:04 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/13 18:53:10 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *a, const char *b, size_t n)
{
	const unsigned char	*ua;
	const unsigned char *ub;

	ua = (const unsigned char *)a;
	ub = (const unsigned char *)b;
	while (n-- && (*ua || *ub))
	{
		if (*ua != *ub)
			return (*ua - *ub);
		++ua;
		++ub;
	}
	return (0);
}
