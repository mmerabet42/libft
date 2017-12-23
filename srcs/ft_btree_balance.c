/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_balance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:07:10 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/22 22:02:29 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

static t_btree	*ft_btree_align(t_btree *bt)
{
	int	pos;
	int	leftlen;
	int	rightlen;

	if (!bt)
		return (NULL);
	leftlen = ft_btree_size(bt->left);
	rightlen = ft_btree_size(bt->right);
	if ((pos = ft_btree_pos(bt->parent, bt)) == -1 && leftlen < rightlen)
		return (ft_btree_align(ft_btree_leftrotate(bt)));
	else if (pos == 1 && rightlen < leftlen)
		return (ft_btree_align(ft_btree_rightrotate(bt)));
	return (bt);
}

t_btree			*ft_btree_balance(t_btree *bt)
{
	int		leftlen;
	int		rightlen;
	t_btree	*newroot;

	if ((newroot = bt))
	{
		if ((newroot->left = ft_btree_balance(ft_btree_align(newroot->left))))
			newroot->left->parent = newroot;
		if ((newroot->right = ft_btree_balance(ft_btree_align(newroot->right))))
			newroot->right->parent = newroot;
		leftlen = ft_btree_depth(newroot->left);
		rightlen = ft_btree_depth(newroot->right);
		if (leftlen < rightlen - 1)
			newroot = ft_btree_balance(ft_btree_leftrotate(newroot));
		else if (rightlen < leftlen - 1)
			newroot = ft_btree_balance(ft_btree_rightrotate(newroot));
	}
	return (newroot);
}
