/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insertf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:49:22 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/12 16:05:06 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btree_insertf(t_btree *bt, t_btree *elem, t_cmpfunc cmp)
{
	if (bt == NULL || bt == elem)
		return (elem);
	if (cmp(bt->content, elem->content, elem->content_size) > 0)
	{
		if (bt->left == NULL)
			bt->left = elem;
		bt = bt->left;
	}
	else
	{
		if (bt->right == NULL)
			bt->right = elem;
		bt = bt->right;
	}
	return (ft_btree_insertf(bt, elem, cmp));
}
