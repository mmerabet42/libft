/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_delone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:36:14 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/28 16:38:15 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_delone(t_btree **abt, void (*del)(void *, size_t))
{
	if (abt && *abt)
	{
		if (del)
			del((*abt)->content, (*abt)->content_size);
		ft_memdel((void **)abt);
	}
}
