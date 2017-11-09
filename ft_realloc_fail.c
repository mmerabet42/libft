/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_fail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 23:12:21 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/09 23:39:44 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc_fail(void *ptr, size_t size)
{
	void	*new_ptr;

	if ((new_ptr = realloc(ptr, size)) == NULL)
		free(ptr);
	return (new_ptr);
}
