/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:48:16 by mmerabet          #+#    #+#             */
/*   Updated: 2018/03/12 18:48:28 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

int ft_getch(void)
{
	int				r;
	unsigned char	c;
	if ((r = read(0, &c, sizeof(unsigned char))) < 0)
		return (r);
	return (c);
}

