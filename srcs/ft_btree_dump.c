/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_dump.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:42:38 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/20 20:38:38 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include "ft_printf.h"

void	inner_btree_dump(t_btree *bt, int n)
{
	if (!bt)
	{
		ft_printf("%?*\tEND\n", n);
		return ;
	}
	ft_printf("%?*\t'%ld': '%s'\n%1$?*\tLeft {\n", n, bt->content_size,
			(char *)bt->content);
	inner_btree_dump(bt->left, n + 1);
	ft_printf("%?*\t}\n%1$?*\tRight {\n", n);
	inner_btree_dump(bt->right, n + 1);
	ft_printf("%?*\t}\n", n);
}

void	ft_btree_dump(t_btree *bt)
{
	inner_btree_dump(bt, 0);
}
