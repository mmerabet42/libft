/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsterase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:57:08 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/17 18:37:30 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	ft_swap_list(t_list *a, t_list *b)
{
	size_t	tmp;

	ft_swapptr(&a->content, &b->content);
	tmp = a->content_size;
	a->content_size = b->content_size;
	b->content_size = tmp;
}

t_list		*ft_lsterase(t_list **alst,
					const void *content,
					size_t content_size)
{
	t_list	*tmp;
	t_list	*lstdel;

	if (alst && (lstdel = ft_lstfind(*alst, content, content_size)))
	{
		if ((tmp = lstdel->parent))
		{
			if ((tmp->next = lstdel->next))
				lstdel->next->parent = tmp;
		}
		else if ((*alst)->next)
		{
			lstdel = (*alst)->next;
			if (((*alst)->next = lstdel->next))
				lstdel->next->parent = *alst;
			ft_swap_list(*alst, lstdel);
		}
		else
			*alst = NULL;
		lstdel->parent = NULL;
		lstdel->next = NULL;
		return (lstdel);
	}
	return (NULL);
}

t_list		*ft_lsterasef(t_list **alst,
					const void *content,
					size_t content_size,
					t_cmpfunc cmp)
{
	t_list	*tmp;
	t_list	*lstdel;

	if (alst && (lstdel = ft_lstfindf(*alst, content, content_size, cmp)))
	{
		if ((tmp = lstdel->parent))
		{
			if ((tmp->next = lstdel->next))
				lstdel->next->parent = tmp;
		}
		else if ((*alst)->next)
		{
			lstdel = (*alst)->next;
			if (((*alst)->next = lstdel->next))
				lstdel->next->parent = *alst;
			ft_swap_list(*alst, lstdel);
		}
		else
			*alst = NULL;
		lstdel->parent = NULL;
		lstdel->next = NULL;
		return (lstdel);
	}
	return (NULL);
}
