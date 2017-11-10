/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:00:22 by mmerabet          #+#    #+#             */
/*   Updated: 2017/11/10 18:26:21 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H

#include <stdlib.h>

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memdup(const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *a, const void *b, size_t n);
void				*ft_memmalloc(size_t size);
void				ft_memdel(void **ap);

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *a, const char *b);
char				*ft_strcatc(char *a, char b);
char				*ft_strncat(char *a, const char *b, size_t n);
size_t				ft_strlcat(char *a, const char *b, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *a, const char *b);
char				*ft_strnstr(const char *a, const char *b, size_t n);
int					ft_strcmp(const char *a, const char *b);
int					ft_strncmp(const char *a, const char *b, size_t n);

char				*ft_strnew(size_t size);
void				ft_strdel(char **ap);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char *s, char (*f)(char));
char				*ft_strmapi(char *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *a, const char *b);
int					ft_strnequ(const char *a, const char *b, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *a, const char *b);
char				*ft_strjoinc(const char *a, char b);
char				*ft_strjoincs(char a, const char *b);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char sep);
char				**ft_strsplitstr(const char *s, const char *sep);

int					ft_atoi(const char *s);
long				ft_atol(const char *s);
long long			ft_atoll(const char *s);
unsigned int		ft_atoui(const char *s);

char				*ft_itoa(int n);
char				*ft_ltoa(long n);
char				*ft_lltoa(long long n);
char				*ft_uitoa(unsigned int n);

int					ft_toupper(int c);
int					ft_tolower(int c);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_iscntrl(int c);
int					ft_isspace(int c);
int					ft_ispinct(int c);

/* ADDED FUNCTIONS */
char				*ft_strndup(const char *s, size_t n);
char				*ft_strmdup(const char *s, size_t n);
char				*ft_strnchr(const char *s, int c, size_t n);
char				*ft_strnrchr(const char *s, int c, size_t n);
char				*ft_strrstr(const char *a, const char *b);
char				*ft_strnrstr(const char *a, const char *b, size_t n);
int					ft_strchr_pos(const char *a, int b);
int					ft_strstr_pos(const char *a, const char *b);
void				*ft_realloc_fail(void *ptr, size_t size);
int					ft_intlen(int n);

#endif
