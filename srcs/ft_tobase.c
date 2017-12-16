/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tobase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:20:40 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/15 11:53:31 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tobase(const char *s, char *fbase, char *tbase)
{
	return (ft_itoa_cbase(ft_atoi_base(s, fbase), tbase));
}
