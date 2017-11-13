/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_tolist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:05:12 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/13 22:21:13 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_btree_tolist(t_btree *bt)
{
	t_list	*lst;

	if (bt == NULL)
		return (NULL);
	if ((lst = ft_lstnew(bt->content, bt->content_size)) == NULL)
		return (NULL);
	ft_lstpushfront(&lst, ft_btree_tolist(bt->left));
	ft_lstpush(lst, ft_btree_tolist(bt->right));
	return (lst);
}
