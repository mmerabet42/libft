/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 12:44:56 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/15 12:56:31 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *lst, const void *content, size_t content_size)
{
	if (!lst)
		return (NULL);
	if (lst->content_size == content_size)
		if (ft_memcmp(lst->content, content, content_size) == 0)
			return (lst);
	return (ft_lstfind(lst->next, content, content_size));
}
