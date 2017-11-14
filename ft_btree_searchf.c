/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_searchf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:00:28 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/14 12:59:10 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btree_searchf(t_btree *bt,
					const void *content,
					size_t content_size,
					t_cmpfunc cmp)
{
	int	cmp_n;

	if (!bt)
		return (NULL);
	cmp_n = cmp(bt->content, content, content_size);
	if (cmp_n == 0)
		return (bt);
	bt = (cmp_n < 0 ? bt->right : bt->left);
	return (ft_btree_searchf(bt, content, content_size, cmp));
}
