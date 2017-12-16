/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_erasef.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:29:12 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/23 17:17:45 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_btree	*ft_btree_erase_case0(t_btree *found)
{
	t_btree	*rep;

	rep = (found->left ? found->left : found->right);
	ft_btree_swap(found, rep, 1);
	return (rep);
}

static t_btree	*ft_btree_erase_case1(t_btree *found)
{
	t_btree	*mostleft;

	mostleft = ft_btree_left(found->right);
	if (mostleft->parent == found)
		mostleft->parent->right = mostleft->right;
	else
		mostleft->parent->left = mostleft->right;
	ft_btree_swap(found, mostleft, 0);
	return (mostleft);
}

static t_btree	*ft_btree_erase_case2(t_btree *found)
{
	if (found == found->parent->left)
		found->parent->left = NULL;
	else
		found->parent->right = NULL;
	return (found);
}

t_btree			*ft_btree_erasef(t_btree *bt,
					const void *content,
					size_t content_size,
					t_cmpfunc cmp)
{
	int		cmp_n;
	t_btree	*tmp;

	tmp = NULL;
	if (!bt || !cmp)
		return (NULL);
	cmp_n = cmp(bt->content, content, content_size);
	if (cmp_n > 0)
		return (ft_btree_erasef(bt->left, content, content_size, cmp));
	else if (cmp_n < 0)
		return (ft_btree_erasef(bt->right, content, content_size, cmp));
	else
	{
		if ((bt->right && !bt->left) || (!bt->right && bt->left))
			tmp = ft_btree_erase_case0(bt);
		else if (bt->right && bt->left)
			tmp = ft_btree_erase_case1(bt);
		else
			tmp = ft_btree_erase_case2(bt);
		tmp->left = NULL;
		tmp->right = NULL;
		tmp->parent = NULL;
	}
	return (tmp);
}
