/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:00:22 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/18 19:01:57 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H
# define FT_HEXM "0123456789ABCDEF"
# define FT_HEX "0123456789abcdef"
# define FT_BIN "01"
# define FT_OCT "01234567"
# define FT_DEC "0123456789"

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*parent;
}					t_list;

typedef struct		s_btree
{
	void			*content;
	size_t			content_size;
	struct s_btree	*parent;
	struct s_btree	*left;
	struct s_btree	*right;
}					t_btree;

typedef int	(*t_cmpfunc)(const void *, const void *, size_t);

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memdup(const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memchr_pos(const void *s, int c, size_t n);
int					ft_memcmp(const void *a, const void *b, size_t n);
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

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strndup(const char *s, size_t n);
char				*ft_strmdup(const char *s, size_t n);
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
char				*ft_strnchr(const char *s, int c, size_t n);
char				*ft_strnrchr(const char *s, int c, size_t n);
char				*ft_strrstr(const char *a, const char *b);
char				*ft_strnrstr(const char *a, const char *b, size_t n);
int					ft_strchr_pos(const char *a, int b);
int					ft_strstr_pos(const char *a, const char *b);
char				*ft_strrepeat(const char *s, int n);
char				*ft_strrepeat_clr(char *s, int n);
char				*ft_revstr(char *a);
char				*ft_revnstr(char *a, size_t n);
void				ft_swap(char *a, char *b);
int					ft_strforeach(const char *s, int (*f)(char c));

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
char				*ft_strjoin_clr(char *a, char *b, int d);
char				*ft_strjoinc_clr(char *a, char b);
char				*ft_strjoincs_clr(char a, char *b);
char				*ft_strtrim(const char *s);
char				*ft_strtrim_clr(char *s);
char				**ft_strsplit(const char *s, char sep);
char				**ft_strsplitstr(const char *s, const char *sep);
int					ft_strcount(const char *s, char a);
int					ft_strcountstr(const char *s, const char *a);
char				*ft_strrep(const char *s, char a, char b);
char				*ft_strrepc(char *s, char a, char b);
char				*ft_strrepstr(const char *s, const char *a, const char *b);
char				*ft_strrep_clr(char *s, char a, char b);
char				*ft_strrepstr_clr(char *s, const char *a, const char *b);
char				*ft_strafterstr(const char *s, const char *a);
char				*ft_strafter(const char *s, char a);
char				*ft_strbeforestr(const char *s, const char *a);
char				*ft_strbefore(const char *s, char a);

int					ft_atoi(const char *s);
long				ft_atol(const char *s);
long long			ft_atoll(const char *s);
unsigned int		ft_atoui(const char *s);
unsigned long		ft_atoul(const char *s);
unsigned long long	ft_atoull(const char *s);
double				ft_atod(const char *s);
int					ft_atoi_base(const char *s, const char *base);

char				*ft_itoa(int n);
char				*ft_ltoa(long n);
char				*ft_lltoa(long long n);
char				*ft_uitoa(unsigned int n);
char				*ft_ultoa(unsigned long n);
char				*ft_ulltoa(unsigned long long n);
char				*ft_dtoa(double n, int precision);
char				*ft_ldtoa(long double n, int precision);
char				*ft_itoa_cbase(int n, const char *base);
char				*ft_uitoa_cbase(unsigned int n, const char *base);
char				*ft_ltoa_cbase(long n, const char *base);
char				*ft_ultoa_cbase(unsigned long n, const char *base);
char				*ft_lltoa_cbase(long long n, const char *base);
char				*ft_ulltoa_cbase(unsigned long long n, const char *base);
char				*ft_tobase(const char *s,
							char *fbase,
							char *tbase);

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

void				ft_putchar(char c);
void				ft_putnchar(char c, size_t n);
void				ft_putstr(const char *s);
void				ft_putnstr(const char *s, size_t n);
void				ft_putendl(const char *s);
void				ft_putnendl(const char *s, size_t n);
void				ft_putnbr(int n);
void				ft_putunbr(unsigned int n);
void				ft_putnbr_base(int n, const char *base);
void				ft_putullong_base(unsigned long long n, const char *base);
void				ft_putptr(void *ptr);
void				ft_putdouble(double n, int precision);

void				ft_putchar_fd(char c, int fd);
void				ft_putnchar_fd(char c, size_t n, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putnstr_fd(const char *s, size_t n, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnendl_fd(const char *s, size_t n, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putunbr_fd(unsigned int n, int fd);
void				ft_putnbr_base_fd(int n, const char *base, int fd);
void				ft_putullong_base_fd(unsigned long long n,
									const char *base,
									int fd);
void				ft_putptr_fd(void *ptr, int fd);
void				ft_putdouble_fd(double n, int precision, int fd);

t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *elem);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstpush(t_list *lst, t_list *elem);
void				ft_lstpushfront(t_list **alst, t_list *elem);
t_list				*ft_lstatpos(t_list *lst, int i);
t_list				*ft_lstfind(t_list *lst,
							const void *content,
							size_t content_size);
t_list				*ft_lstfindf(t_list *lst,
							const void *content,
							size_t content_size,
							t_cmpfunc cmp);
size_t				ft_lstsize(t_list *lst);
t_list				*ft_lstend(t_list *lst);
t_list				*ft_lstcopy(t_list *lst);
t_list				*ft_lstcopyone(t_list *lst);
t_list				*ft_lsterase(t_list **alst,
							const void *content,
							size_t content_size);
t_list				*ft_lsterasef(t_list **alst,
							const void *content,
							size_t content_size,
							t_cmpfunc cmp);

t_btree				*ft_btree_new(const void *content, size_t content_size);
t_btree				*ft_btree_create(const void *content, size_t content_size);
void				ft_btree_delone(t_btree **abt, void (*del)(void *, size_t));
void				ft_btree_del(t_btree **abt, void (*del)(void *, size_t));
t_btree				*ft_btree_insert(t_btree *bt, t_btree *elem);
t_btree				*ft_btree_insertf(t_btree *bt,
								t_btree *elem,
								t_cmpfunc cmp);
t_btree				*ft_btree_erase(t_btree *bt,
								const void *content,
								size_t content_size);
t_btree				*ft_btree_erasef(t_btree *bt,
								const void *content,
								size_t content_size,
								t_cmpfunc cmp);
t_btree				*ft_btree_search(t_btree *bt,
								const void *content,
								size_t content_size);
t_btree				*ft_btree_searchf(t_btree *bt,
								const void *content,
								size_t content_size,
								t_cmpfunc cmp);
t_btree				*ft_btree_left(t_btree *bt);
t_btree				*ft_btree_right(t_btree *bt);
t_list				*ft_btree_tolist(t_btree *bt);
t_btree				*ft_btree_fromlist(t_list *lst);
t_btree				*ft_btree_fromlistf(t_list *lst, t_cmpfunc cmp);
t_btree				*ft_btree_copy(t_btree *bt);
void				ft_btree_swap(t_btree *a, t_btree *b, int childs);
t_btree				*ft_btree_leftrotate(t_btree *bt);
t_btree				*ft_btree_rightrotate(t_btree *bt);
t_btree				*ft_btree_balance(t_btree *bt);
size_t				ft_btree_size(t_btree *bt);

int					ft_wcharlen(wchar_t wc);
char				*ft_getwchar(wchar_t wc);
int					ft_wstrlen(const wchar_t *wcs);
int					ft_wstrnlen(const wchar_t *wcs, int n);
char				*ft_getwstr(const wchar_t *wcs);
char				*ft_getnwstr(const wchar_t *wc, int n);

int					ft_intlen(int n);
int					ft_longlen(long n);
int					ft_llonglen(long long n);
int					ft_uintlen(unsigned int n);
int					ft_ulonglen(unsigned long n);
int					ft_ullonglen(unsigned long long n);
int					ft_abs(int n);
int					ft_pow(int x, int y);
int					ft_sqrt(int n);
void				ft_swapptr(void **a, void **b);

#endif
