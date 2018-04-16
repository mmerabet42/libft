/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmatchl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:09:42 by mmerabet          #+#    #+#             */
/*   Updated: 2018/04/16 16:09:51 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

int			ft_strmatchl(const char *str, const char *match)
{
	char	*strl;
	int		ret;

	if (!str || !match || !(strl = ft_strdupli(str)))
		return (0);
	ret = ft_strmatch(strl, match);
	free(strl);
	return (ret);
}
