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
#include "ft_printf.h"

t_btree	*ft_btree_right(t_btree *bt)
{
	if (bt && bt->right)
		return (ft_btree_right(bt->right));
	return (bt);
}

t_btree	*ft_btree_rightrotate(t_btree *bt)
{
	t_btree	*left;

	left = bt;
	if (bt && (left = bt->left))
	{
		bt->left = left->right;
		left->parent = NULL;
		left->right = bt;
		bt->parent = left;
		if (bt->left)
			bt->left->parent = bt;
	}
	return (left);
}
