/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_rightrotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:40:21 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/23 18:07:03 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
			bt->right->parent = bt;
	}
	return (left);
}
