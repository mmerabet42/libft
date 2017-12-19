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

t_list	*ft_btree_tolist(t_btree *bt)
{
	t_list	*lst;

	if (!bt || (lst = ft_lstnew(bt->content, bt->content_size)) == NULL)
		return (NULL);
	ft_lstpushfront(&lst, ft_btree_tolist(bt->left));
	ft_lstpush(lst, ft_btree_tolist(bt->right));
	return (lst);
}
