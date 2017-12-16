/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:58:49 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/12 14:09:00 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btree_search(t_btree *bt, const void *content, size_t content_size)
{
	return (ft_btree_searchf(bt, content, content_size, ft_memcmp));
}
