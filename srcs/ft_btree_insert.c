/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:48:27 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/20 20:30:13 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include "ft_mem.h"

static t_btree	*inner_btree_insertf(t_btree *parent,
								t_btree *bt,
								t_btree *elem,
								t_cmpfunc cmp)
{
	t_btree	*old_bt;

	old_bt = bt;
	if (bt == NULL || bt == elem)
	{
		if (elem)
			elem->parent = parent;
		return (elem);
	}
	if (cmp(bt->content, elem->content, elem->content_size) > 0)
	{
		if (bt->left == NULL)
			bt->left = elem;
		bt = bt->left;
	}
	else
	{
		if (bt->right == NULL)
			bt->right = elem;
		bt = bt->right;
	}
	return (inner_btree_insertf(old_bt, bt, elem, cmp));
}

static t_btree	*inner_btree_insertm(t_btree *parent,
								t_btree *bt,
								t_btree *elem,
								t_ptrpos ppos)
{
	t_btree	*old_bt;

	old_bt = bt;
	if (bt == NULL || bt == elem)
	{
		if (elem)
			elem->parent = parent;
		return (elem);
	}
	if (ft_memcmp((char *)bt->content + ppos.start,
				(char *)elem->content + ppos.start, ppos.len) > 0)
	{
		if (bt->left == NULL)
			bt->left = elem;
		bt = bt->left;
	}
	else
	{
		if (bt->right == NULL)
			bt->right = elem;
		bt = bt->right;
	}
	return (inner_btree_insertm(old_bt, bt, elem, ppos));
}

t_btree			*ft_btree_insertf(t_btree *bt, t_btree *elem, t_cmpfunc cmp)
{
	return (inner_btree_insertf(bt, bt, elem, cmp));
}

t_btree			*ft_btree_insert(t_btree *bt, t_btree *elem)
{
	return (ft_btree_insertf(bt, elem, ft_memcmp));
}

t_btree			*ft_btree_insertm(t_btree *bt,
								t_btree *elem,
								size_t pstart,
								size_t plen)
{
	t_ptrpos	ppos;

	ppos.start = pstart;
	ppos.len = plen;
	return (inner_btree_insertm(bt, bt, elem, ppos));
}
