/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:10:42 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/23 17:01:31 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_swap(t_btree *a, t_btree *b, int childs)
{
	size_t	tmp;
	void	*ptr;

	if (a && b)
	{
		tmp = a->content_size;
		a->content_size = b->content_size;
		b->content_size = tmp;
		ptr = a->content;
		a->content = b->content;
		b->content = ptr;
		if (childs)
		{
			ft_swapptr((void **)&a->left, (void **)&b->left);
			ft_swapptr((void **)&a->right, (void **)&b->right);
		}
	}
}
