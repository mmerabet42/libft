/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:19:51 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/21 16:20:01 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*ft_btree_left(t_btree *bt)
{
	if (bt && bt->left)
		return (ft_btree_left(bt->left));
	return (bt);
}

t_btree	*ft_btree_leftrotate(t_btree *bt)
{
	t_btree	*right;

	right = bt;
	if (bt && (right = bt->right))
	{
		bt->right = right->left;
		right->parent = NULL;
		right->left = bt;
		bt->parent = right;
		if (bt->right)
			bt->right->parent = bt;
	}
	return (right);
}
