/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 22:27:35 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/13 22:35:09 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btree_copy(t_btree *bt)
{
	t_btree	*newbt;

	if (!bt)
		return (NULL);
	newbt = ft_btree_new(bt->content, bt->content_size);
	newbt->left = ft_btree_copy(bt->left);
	newbt->right = ft_btree_copy(bt->right);
	return (newbt);
}
