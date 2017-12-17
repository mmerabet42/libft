/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:08:24 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/17 18:39:46 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpush(t_list *lst, t_list *elem)
{
	t_list	*lst_end;

	if ((lst_end = ft_lstend(lst)))
		if ((lst_end->next = elem))
			elem->parent = lst_end;
	return (elem);
}
