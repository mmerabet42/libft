/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:31:23 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/23 20:12:42 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btree_new(const void *content, size_t content_size)
{
	t_btree	*bt;

	if ((bt = (t_btree *)ft_memalloc(sizeof(t_btree))))
	{
		if (content)
			bt->content = ft_memdup(content, content_size);
		bt->content_size = (content ? content_size : 0);
	}
	return (bt);
}
