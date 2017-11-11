/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:31:55 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/11 18:27:49 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*lst;

	if ((lst = (t_list *)ft_memmalloc(sizeof(t_list))))
	{
		if (content)
			lst->content = ft_memdup(content, content_size);
		lst->content_size = (content ? content_size : 0);
	}
	return (lst);
}
