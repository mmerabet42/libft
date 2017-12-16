/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insertf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:49:22 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/15 12:07:44 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_btree	*ft_btree_insertf_(t_btree *parent,
								t_btree *bt,
								t_btree *elem,
								t_cmpfunc cmp)
{
	t_btree	*old_bt;

	old_bt = bt;
	if (bt == NULL || bt == elem)
	{
		if (elem)
			elem->parent = parent;
		return (elem);
	}
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
	return (ft_btree_insertf_(old_bt, bt, elem, cmp));
}

t_btree			*ft_btree_insertf(t_btree *bt, t_btree *elem, t_cmpfunc cmp)
{
	return (ft_btree_insertf_(bt, bt, elem, cmp));
}
