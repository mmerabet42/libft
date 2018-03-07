/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:38:02 by mmerabet          #+#    #+#             */
/*   Updated: 2018/03/07 20:33:50 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memjoin(const void *a,
				size_t an,
				const void *b,
				size_t bn)
{
	void	*s;

	if (!(s = malloc((a ? an : 0) + (b ? bn : 0))))
		return (NULL);
	if (a)
		ft_memcpy(s, a, an);
	if (b)
		ft_memcpy((void *)((char *)s + an), b, bn);
	return (s);
}

void	*ft_memjoin_clr(void *a,
					size_t an,
					void *b,
					size_t bn)
{
	void	*s;

	if (!(s = malloc((a ? an : 0) + (b ? bn : 0))))
		return (NULL);
	if (a)
		ft_memcpy(s, a, an);
	if (b)
		ft_memcpy((void *)((char *)s + an), b, bn);
	free(a);
	return (s);
}

void	*ft_memjoin_clr2(void *a,
					size_t an,
					void *b,
					size_t bn)
{
	void	*s;

	if (!(s = malloc((a ? an : 0) + (b ? bn : 0))))
		return (NULL);
	if (a)
		ft_memcpy(s, a, an);
	if (b)
		ft_memcpy((void *)((char *)s + an), b, bn);
	free(a);
	free(b);
	return (s);
}
