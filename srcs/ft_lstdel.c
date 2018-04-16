/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:43:57 by mmerabet          #+#    #+#             */
/*   Updated: 2018/04/16 22:05:15 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_mem.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*nxt;

	nxt = (alst && *alst ? (*alst)->next : NULL);
	ft_lstdelone(alst, del);
	if (nxt)
		ft_lstdel(&nxt, del);
}

void	ft_lstdel_d(t_list **alst, t_delfunc_d del, void *data)
{
	t_list	*nxt;

	nxt = (alst && *alst ? (*alst)->next : NULL);
	ft_lstdelone_d(alst, del, data);
	if (nxt)
		ft_lstdel_d(&nxt, del, data);
}

void	ft_lstdelone_d(t_list **alst, t_delfunc del, void *data)
{
	if (alst && *alst)
	{
		if (del)
			del((*alst)->content, (*alst)->content_size, data);
		ft_memdel((void **)alst);
	}
}

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && *alst)
	{
		if (del)
			del((*alst)->content, (*alst)->content_size);
		ft_memdel((void **)alst);
	}
}
