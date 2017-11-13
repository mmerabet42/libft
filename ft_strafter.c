/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strafter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:58:30 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/13 13:15:26 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strafter(const char *s, char a)
{
	char	*pos;

	pos = ft_strchr(s, a);
	return (pos == NULL ? NULL : ft_strdup(pos + 1));
}
