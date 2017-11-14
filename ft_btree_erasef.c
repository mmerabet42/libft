/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_erasef.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:29:12 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/14 23:19:56 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_btree	*ft_btree_erase_case0(t_btree *found)
{
	t_btree	*rep;
	size_t	tmp;

	rep = (found->left ? found->left : found->right);
	ft_swapptr((void **)&found->content, (void **)&rep->content);
	tmp = found->content_size;
	found->content_size = rep->content_size;
	rep->content_size = tmp;
	ft_swapptr((void **)&found->left, (void **)&rep->left);
	ft_swapptr((void **)&found->right, (void **)&rep->right);
	return (rep);
}

static t_btree	*ft_btree_erase_case1(t_btree *found)
{
	t_btree	*mostleft;
	size_t	tmp;

	mostleft = ft_btree_left(found->right);
	if (mostleft->parent == found)
		mostleft->parent->right = mostleft->right;
	else
		mostleft->parent->left = mostleft->right;
	ft_swapptr((void **)&found->content, (void **)&mostleft->content);
	tmp = found->content_size;
	found->content_size = mostleft->content_size;
	mostleft->content_size = tmp;
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
	if (bt == NULL)
		return (bt);
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
