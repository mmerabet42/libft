/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_leftrotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:02:11 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/23 17:39:46 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
