/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:38:13 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/28 16:38:50 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_del(t_btree **abt, void (*del)(void *, size_t))
{
	t_btree	*left;
	t_btree *right;

	left = NULL;
	right = NULL;
	if (abt && *abt)
	{
		left = (*abt)->left;
		right = (*abt)->right;
		ft_btree_delone(abt, del);
		if (left)
			ft_btree_del(&left, del);
		if (right)
			ft_btree_del(&right, del);
	}
}
