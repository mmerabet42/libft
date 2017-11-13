/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strafterstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:07:09 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/13 14:08:35 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strafterstr(const char *s, const char *a)
{
	char	*pos;

	pos = ft_strstr(s, a);
	return (pos == NULL ? NULL : ft_strdup(pos + ft_strlen(a)));
}
