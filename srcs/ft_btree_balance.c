/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_balance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:07:10 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/23 22:09:40 by mmerabet         ###   ########.fr       */
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
		leftlen = ft_btree_size(newroot->left);
		rightlen = ft_btree_size(newroot->right);
		if (leftlen < rightlen - 1)
			return (ft_btree_balance(ft_btree_leftrotate(newroot)));
		else if (rightlen < leftlen - 1)
			return (ft_btree_balance(ft_btree_rightrotate(newroot)));
		if ((newroot->left = ft_btree_balance(newroot->left)))
			newroot->left->parent = newroot;
		if ((newroot->right = ft_btree_balance(newroot->right)))
			newroot->right->parent = newroot;
	}
	return (newroot);
}
