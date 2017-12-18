/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 22:05:26 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/18 22:56:17 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revstr(char *a)
{
	size_t	i;
	size_t	len;

	if (!a)
		return (NULL);
	i = 0;
	len = ft_strlen(a) - 1;
	while (i < len)
		ft_swap(a + i++, a + len--);
	return (a);
}

char	*ft_strrepeat(const char *s, int n)
{
	char	*result;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	len *= n;
	if (!(result = ft_strnew(len)))
		return (NULL);
	while (n--)
		ft_strcat(result, s);
	return (result);
}

char	*ft_strrepeat_clr(char *s, int n)
{
	char	*result;

	result = ft_strrepeat(s, n);
	free(s);
	return (result);
}
