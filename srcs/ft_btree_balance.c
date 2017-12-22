/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_balance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:07:10 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/21 20:54:55 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include "ft_printf.h"

t_btree	*ft_btree_balance(t_btree *bt)
{
	//static int i;
	int		leftlen;
	int		rightlen;
	t_btree	*newroot;

	newroot = bt;
	if (newroot)
	{
		leftlen = ft_btree_size(newroot->left);
		rightlen = ft_btree_size(newroot->right);
		//ft_printf("BTREE %d %d %d :\n", i++, leftlen, rightlen);
		//ft_btree_dump(newroot);
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
