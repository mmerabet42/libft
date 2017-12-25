/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:20:51 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/21 16:19:56 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*ft_btree_right(t_btree *bt)
{
	if (bt && bt->right)
		return (ft_btree_right(bt->right));
	return (bt);
}

t_btree	*ft_btree_rightrotate(t_btree *bt)
{
	t_btree	*left;
	int		pos;

	left = bt;
	if (bt && (left = bt->left))
	{
		if ((pos = ft_btree_pos(bt->parent, bt)) == -1)
			bt->parent->left = left;
		else if (pos == 1)
			bt->parent->right = left;
		bt->left = left->right;
		left->parent = bt->parent;
		left->right = bt;
		bt->parent = left;
		if (bt->left)
			bt->left->parent = bt;
	}
	return (left);
}

t_btree	*ft_btree_rightrotatef(t_btree *bt, t_cmpfunc cmp)
{
	t_btree	*left;
	int		pos;

	left = bt;
	if (cmp && bt && (left = bt->left))
	{
		if (cmp(bt->content, left->content, bt->content_size) < 0)
			return (bt);
		if ((pos = ft_btree_pos(bt->parent, bt)) == -1)
			bt->parent->left = left;
		else if (pos == 1)
			bt->parent->right = left;
		bt->left = left->right;
		left->parent = bt->parent;
		left->right = bt;
		bt->parent = left;
		if (bt->left)
			bt->left->parent = bt;
	}
	return (left);
}
