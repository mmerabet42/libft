/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:38:37 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/10 15:41:13 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	char	*fstr;
	int		i;

	i = ft_intlen(n);
	str = NULL;
	if (n < 0)
	{
		fstr = ft_itoa(-n);
		if (!(str = ft_strjoincs('-', fstr)))
			free(fstr);
		return (str);
	}
	if ((str = ft_strnew(i)) == NULL)
		return (NULL);
	while (n > 0 || str[i] == '\0')
	{
		str[--i] = (n % 10 + 48);
		n /= 10;
	}
	return (str);
}
