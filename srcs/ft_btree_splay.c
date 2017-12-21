/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_splay.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:16:30 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/21 15:53:47 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include "ft_mem.h"

t_btree	*ft_btree_splay(t_btree *bt, const void *content, size_t content_size)
{
	return (ft_btree_splayf(bt, content, content_size, ft_memcmp));
}

t_btree	*ft_btree_splayf(t_btree *bt,
					const void *content,
					size_t content_size,
					t_cmpfunc cmp)
{
	t_btree	*found;

	if (!(found = ft_btree_searchf(bt, content, content_size, cmp)))
		return (NULL);
	return (ft_btree_move(bt, found));
}

t_btree *ft_btree_move(t_btree *bt, t_btree *elem)
{
	int		pos;
	t_btree	*tmp;
	t_btree	*tmp0;

	if ((pos = ft_btree_pos(bt, elem)) == 0)
		return (bt);
	tmp0 = elem;
	if (pos == -1)
	{
		while ((pos = ft_btree_pos(tmp0->parent, tmp0)) == 1)
			tmp0 = tmp0->parent;
		ft_btree_disconnect(tmp0);
		tmp = ft_btree_left(elem);
		if ((tmp->left = tmp0))
			tmp0->parent = tmp;
		tmp = ft_btree_right(elem);
		tmp->right = bt;
	}
	else
	{
		while ((pos = ft_btree_pos(tmp0->parent, tmp0)) == -1)
			tmp0 = tmp0->parent;
		ft_btree_disconnect(tmp0);
		tmp = ft_btree_right(elem);
		if ((tmp->right = tmp0))
			tmp0->parent = tmp;
		tmp = ft_btree_left(elem);
		tmp->left = bt;
	}
	ft_btree_disconnect(elem);
	if ((pos = ft_btree_pos(bt, bt->parent)) == -1)
		bt->parent->left = elem;
	else if (pos == 1)
		bt->parent->right = elem;
	bt->parent = tmp;
	return (elem);
}

t_btree	*ft_btree_disconnect(t_btree *bt)
{
	int	pos;

	if (bt && (pos = ft_btree_pos(bt->parent, bt)) != 0)
	{
		if (pos == -1)
			bt->parent->left = NULL;
		else
			bt->parent->right = NULL;
	}
	bt->parent = NULL;
	return (bt);
}
