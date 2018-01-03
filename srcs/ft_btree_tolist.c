/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_tolist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:05:12 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/19 19:36:17 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_list			*ft_btree_tolist(t_btree *bt)
{
	return (ft_btree_tolistm(bt, BT_INORDER));
}

static t_list	*inner_btree_bf(t_btree *bt, int n, int m)
{
	t_list	*lst;

	if (!bt)
		return (NULL);
	if (n == m)
		return (ft_lstnew(bt->content, bt->content_size));
	lst = NULL;
	ft_lstpushfront(&lst, inner_btree_bf(bt->left, n + 1, m));
	ft_lstpush(lst, inner_btree_bf(bt->right, n + 1, m));
	return (lst);
}

static t_list	*ft_btree_breadthfirst(t_btree *bt)
{
	t_list	*lst;
	t_list	*tmp;
	int		n;
	int		i;

	lst = NULL;
	n = ft_btree_depth(bt);
	i = 0;
	while (i < n)
	{
		tmp = ft_lstpush(lst, inner_btree_bf(bt, 0, i++));
		if (!lst)
			lst = tmp;
	}
	return (lst);
}

static t_list	*inner_btree_tolistm(t_btree *bt, t_btmode mode)
{
	t_list	*lst;
	t_list	*left;
	t_list	*right;

	if (!(lst = ft_lstnew(bt->content, bt->content_size)))
		return (NULL);
	left = ft_btree_tolistm(bt->left, mode);
	right = ft_btree_tolistm(bt->right, mode);
	if (mode == BT_INORDER)
	{
		ft_lstpushfront(&lst, left);
		ft_lstpush(lst, right);
	}
	else if (mode == BT_PREORDER)
	{
		ft_lstpush(lst, left);
		ft_lstpush(lst, right);
	}
	else if (mode == BT_POSTORDER)
	{
		ft_lstpushfront(&lst, right);
		ft_lstpushfront(&lst, left);
	}
	return (lst);
}

t_list			*ft_btree_tolistm(t_btree *bt, t_btmode mode)
{
	if (!bt)
		return (NULL);
	if (mode == BT_BREADTHFIRST)
		return (ft_btree_breadthfirst(bt));
	return (inner_btree_tolistm(bt, mode));
}
