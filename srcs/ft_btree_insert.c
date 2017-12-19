/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:48:27 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/19 22:25:50 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include "ft_mem.h"

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

t_btree	*ft_btree_insert(t_btree *bt, t_btree *elem)
{
	return (ft_btree_insertf(bt, elem, ft_memcmp));
}
