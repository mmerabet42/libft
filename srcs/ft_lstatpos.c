/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstatpos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 13:01:11 by mmerabet          #+#    #+#             */
/*   Updated: 2018/01/27 13:01:24 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lstatpos(t_list *lst, int i)
{
	if (lst && i > 0)
		return (ft_lstatpos(lst->next, i - 1));
	return (lst);
}
