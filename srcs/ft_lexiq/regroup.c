/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regroup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:27:06 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/27 18:25:07 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexiq.h"

int lq_addregroup(const char *expr, const char *str)
{
	// ADD REGROUP RULE
}

int	lq_regroup(int flags, const char *expr, const char *str, va_list vp)
{
	if (flags & LQ_ADDR)
		return (lq_addregroup(expr, str));
	// GET THE GROUP LIST FROM VP FIRST
}
