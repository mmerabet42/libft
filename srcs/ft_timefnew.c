/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timefnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 18:47:44 by mmerabet          #+#    #+#             */
/*   Updated: 2018/01/12 18:49:54 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_time.h"
#include "ft_types.h"
#include "ft_mem.h"

t_timef	*ft_timefnew(const time_t *t)
{
	t_timef	*tf;
	char	*out;
	
	if (!(tf = ft_memalloc(sizeof(t_timef))))
		return (NULL);
	if (!(out = ctime(t)))
	{
		free(tf);
		return (NULL);
	}
	tf->hour = ft_atoui(out + 11);
	tf->min = ft_atoui(out + 14);
	tf->sec = ft_atoui(out + 17);
	tf->day = ft_atoui(out + 8);
	tf->year = ft_atoui(out + 20);
	tf->cday = ft_memdup((void *)out, sizeof(char) * 3);
	tf->cmonth = ft_memdup((void *)(out + 4), sizeof(char) * 3);
	return (tf);
}

void	ft_timefdel(t_timef **tf)
{
	if (!tf || !*tf)
		return ;
	free((*tf)->cday);
	free((*tf)->cmonth);
	free(*tf);
	*tf = NULL;
}
