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
#include "ft_printf.h"

static t_btree	*ft_btree_align(t_btree *bt)
{
	
}

t_btree			*ft_btree_balance(t_btree *bt)
{
	int		leftlen;
	int		rightlen;
	int		pos;
	t_btree	*newroot;

	newroot = bt;
	if (newroot)
	{
		leftlen = ft_btree_depth(newroot->left);
		rightlen = ft_btree_depth(newroot->right);
		if ((pos = ft_btree_pos(newroot->parent, newroot)) == 1)
		{
			while (rightlen < leftlen)
			{
				newroot = ft_btree_rightrotate(
				leftlen = ft_btree_depth(newroot->left);
				rightlen = ft_btree_depth(newroot->right);
			}
		}
		else if (pos == -1)
		{

		}
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
