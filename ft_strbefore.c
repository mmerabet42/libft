/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbefore.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:10:29 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/13 13:36:25 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strbefore(const char *s, char a)
{
	int	pos;

	pos = ft_strchr_pos(s, a);
	return (pos == -1 ? NULL : ft_strndup(s, pos));
}
