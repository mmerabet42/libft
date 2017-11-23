/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_balance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:07:10 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/23 20:11:57 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btree_balance(t_btree *bt)
{
	int		leftlen;
	int		rightlen;
	t_btree	*newroot;

	newroot = bt;
	if (bt)
	{
		leftlen = ft_btree_size(bt->left);
		rightlen = ft_btree_size(bt->right);
		if (leftlen < rightlen - 1)
			newroot = ft_btree_leftrotate(bt);
		else if (rightlen < leftlen - 1)
			newroot = ft_btree_rightrotate(bt);
		if ((newroot->left = ft_btree_balance(newroot->left)))
			newroot->left->parent = newroot;
		if ((newroot->right = ft_btree_balance(newroot->right)))
			newroot->right->parent = newroot;
	}
	return (newroot);
}
