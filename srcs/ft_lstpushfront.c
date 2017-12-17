/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:22:48 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/17 18:39:18 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushfront(t_list **alst, t_list *elem)
{
	t_list	*lst_end;

	if (alst && elem)
	{
		lst_end = ft_lstend(elem);
		if ((lst_end->next = *alst))
			(*alst)->parent = lst_end;
		*alst = elem;
	}
}
