/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:25:59 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/19 19:33:41 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

size_t	ft_btree_size(t_btree *bt)
{
	if (bt)
		return (1 + ft_btree_size(bt->left) + ft_btree_size(bt->right));
	return (0);
}
