/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tobase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:20:40 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/11 17:31:47 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tobase(const char *s, const char *fbase, const char *tbase)
{
	return (ft_itoa_base(ft_atoi_base(s, fbase), tbase));
}
