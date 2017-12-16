/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:54:12 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/15 13:09:13 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(const char *s)
{
	double	firstp;
	double	secondp;
	char	*cfirstp;
	char	*csecondp;

	if (!s)
		return (0.0);
	if (ft_strchr(s, '.') == NULL)
		return ((double)ft_atoi(s));
	cfirstp = ft_strbefore(s, '.');
	csecondp = ft_strafter(s, '.');
	firstp = (double)ft_atoll(cfirstp);
	secondp = (double)ft_atoull(csecondp);
	while ((unsigned long long)secondp > 0)
		secondp /= 10;
	return (firstp + secondp);
}
