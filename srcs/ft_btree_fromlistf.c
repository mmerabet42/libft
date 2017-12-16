/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_fromlistf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:28:59 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/15 13:03:17 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btree_fromlistf(t_list *lst, t_cmpfunc cmp)
{
	t_btree	*bt;
	t_btree	*elem;

	bt = NULL;
	while (lst && cmp)
	{
		elem = ft_btree_new(lst->content, lst->content_size);
		elem = ft_btree_insertf(bt, elem, cmp);
		if (!bt)
			bt = elem;
		lst = lst->next;
	}
	return (bt);
}
