/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:42:03 by mmerabet          #+#    #+#             */
/*   Updated: 2018/01/14 18:36:29 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEM_H
# define FT_MEM_H

# include <stdlib.h>

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memdup(const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memchr_pos(const void *s, int c, size_t n);
void				*ft_memstr(const void *a,
							size_t an,
							const void *b,
							size_t ab);
int					ft_memstr_pos(const void *a,
							size_t an,
							const void *b,
							size_t ab);
int					ft_memcmp(const void *a, const void *b, size_t n);
int					ft_memccmp(const void *a, const void *b, int c, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memjoin(const void *a,
							size_t an,
							const void *b,
							size_t bn);
void				*ft_memjoin_clr(void *a,
							size_t an,
							void *b,
							size_t bn);
void				ft_swapptr(void **a, void **b);

#endif
