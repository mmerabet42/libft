/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfindbysize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:33:40 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/26 14:36:01 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfindbysize(t_list *lst, size_t content_size)
{
	if (!lst)
		return (NULL);
	if (lst->content_size == content_size)
		return (lst);
	return (ft_lstfindbysize(lst->next, content_size));
}
