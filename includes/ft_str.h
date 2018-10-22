/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:42:15 by mmerabet          #+#    #+#             */
/*   Updated: 2018/10/22 17:41:01 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

# include <stdlib.h>
# include <wctype.h>
# include <stdarg.h>

size_t				ft_strlen(const char *s);
size_t				ft_strlenl(const char *s);
size_t				ft_strlenk(const char *s);
size_t				ft_strlenli(const char *s);
char				*ft_strend(const char *str);

char				*ft_strdup(const char *s);
char				*ft_strndup(const char *s, size_t n);
char				*ft_strmdup(const char *s, size_t n);

char				*ft_strdupl(const char *s);
char				*ft_strndupl(const char *s, size_t n);
char				*ft_strdupk(const char *s);
char				*ft_strndupk(const char *s, size_t n);
char				*ft_strdupli(const char *s);
char				*ft_strndupli(const char *s, size_t n);

char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);

char				*ft_strcat(char *a, const char *b);
char				*ft_strcatc(char *a, char b);
char				*ft_strncat(char *a, const char *b, size_t n);
char				*ft_strcatl(char *a, const char *b);
char				*ft_strncatl(char *a, const char *b, size_t n);
size_t				ft_strlcat(char *a, const char *b, size_t n);

char				*ft_strchr(const char *s, int c);
char				*ft_strchrl(const char *s, int c);
char				*ft_strchrln(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *a, const char *b);
char				*ft_strnstr(const char *a, const char *b, size_t n);
char				*ft_strpbrk(const char *s, const char *charset);
char				*ft_strnpbrk(const char *s, const char *charset, size_t n);
int					ft_strpbrk_pos(const char *s, const char *charset);
int					ft_strnpbrk_pos(const char *s,
								const char *charset,
								size_t n);
int					ft_strnrpbrk_pos(const char *s,
								const char *charset,
								size_t n);
int					ft_strpbrkl_pos(const char *s, const char *charset);
char				*ft_strpbrkl(const char *s, const char *charset);
int					ft_strnpbrkl_pos(const char *s,
								const char *charset,
								size_t n);
char				*ft_strnpbrkl(const char *s,
								const char *charset,
								size_t n);

int					ft_strpbrkstr_len(const char *a, const char *strset);
int					ft_strpbrkstrl_len(const char *a, const char *strset);
int					ft_strpbrkstr_pos(const char *a, const char *strset);
int					ft_strpbrkstrl_pos(const char *a, const char *strset);
int					ft_strnpbrkstr_len(const char *a, const char *strset,
									int n);
int					ft_strnpbrkstrl_len(const char *a, const char *strset,
									int n);
int					ft_strnpbrkstr_pos(const char *a, const char *strset,
									int n);
int					ft_strnpbrkstrl_pos(const char *a, const char *strset,
									int n);
int					ft_strpbrkstrp_len(const char *a,
									int type,
									size_t size,
									...);
int					ft_strpbrkstrpl_len(const char *a,
									int type,
									size_t size,
									...);
int					ft_strpbrkstrpv_len(const char *a,
									int type,
									size_t size,
									va_list vp);
int					ft_strpbrkstrplv_len(const char *a,
									int type,
									size_t size,
									va_list vp);
int					ft_strpbrkstrp_pos(const char *a,
									int type,
									size_t size,
									...);
int					ft_strpbrkstrpl_pos(const char *a,
									int type,
									size_t size,
									...);

int					ft_strcmp(const char *a, const char *b);
int					ft_strncmp(const char *a, const char *b, size_t n);

int					ft_strequ(const char *a, const char *b);
int					ft_strequl(const char *a, const char *b);
int					ft_strnequl(const char *a, const char *b, size_t n);
int					ft_strequ_x(const char *a, const char *strset);

char				*ft_strnchr(const char *s, int c, size_t n);
char				*ft_strnchrl(const char *s, int c, size_t n);
char				*ft_strnchrln(const char *s, int c, size_t n);
int					ft_strnchrl_pos(const char *s, int c, size_t n);
int					ft_strnchrln_pos(const char *s, int c, size_t n);
char				*ft_strnrchr(const char *s, int c, size_t n);
int					ft_strnrchr_pos(const char *s, int c, size_t n);
int					ft_strrchr_pos(const char *s, int c);
char				*ft_strrstr(const char *a, const char *b);
char				*ft_strnrstr(const char *a, const char *b, size_t n);
int					ft_strchr_pos(const char *a, int b);
int					ft_strnchr_pos(const char *a, int b, size_t n);
int					ft_strchrl_pos(const char *a, int b);
int					ft_strstr_pos(const char *a, const char *b);
int					ft_strstrl_pos(const char *a, const char *b);

char				*ft_strrepeat(const char *s, int n);
char				*ft_strrepeat_clr(char *s, int n);

char				*ft_revstr(char *a);
char				*ft_revnstr(char *a, size_t n);
void				ft_swap(char *a, char *b);
int					ft_strforeach(const char *s, int (*f)(int c));

char				*ft_strnew(size_t size);
void				ft_strdel(char **ap);
char				*ft_strclr(char *s);
char				*ft_strnclr(char *s, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char *s, char (*f)(char));
char				*ft_strmapi(char *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *a, const char *b);
int					ft_strnequ(const char *a, const char *b, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strtrim(const char *s);
char				*ft_strtrim_clr(char *s);
char				**ft_strsplit(const char *s, char sep);
char				**ft_strsplitstr(const char *s, const char *sep);
size_t				ft_tabsize(char **tab);
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
char				*ft_strbetween(const char *s, char a, char b);
char				*ft_strbetweenl(const char *s, char a, char b);
char				*ft_strbetweenstr(const char *s,
									const char *a,
									const char *b);
int					ft_strbetweenps(char **s, const char *a, const char *b);
char				*ft_strbetweenstr_ext(const char *s, const char *ext);
int					ft_strbetweenps_ext(char **s, const char *ext);

char				*ft_strjoin(const char *a, const char *b);
char				*ft_strnjoin(const char *a, const char *b, size_t n);
char				*ft_strn2join(const char *a, const char *b, size_t n);
char				*ft_strjoinc(const char *a, char b);
char				*ft_strjoincs(char a, const char *b);
char				*ft_strnjoin_clr(char *a, char *b, size_t n, int d);
char				*ft_strn2join_clr(char *a, char *b, size_t n, int d);
char				*ft_strjoin_clr(char *a, char *b, int d);
char				*ft_strjoinc_clr(char *a, char b);
char				*ft_strjoincs_clr(char a, char *b);
char				*ft_strjoinl(const char *a, const char *b);
char				*ft_strnjoinl(const char *a, const char *b, size_t n);
char				*ft_strjoinl_clr(char *a, char *b, int d);
char				*ft_strnjoinl_clr(char *a, char *b, size_t n, int d);

char				*ft_strinsert(char *a, char *b, size_t start, size_t size);
char				*ft_strerase(char *a, size_t start, size_t end);

typedef struct		s_pairint
{
	char			*ext;
	char			*a;
	char			*b;
	int				len;
	int				la;
	int				lb;
	char			tmp;
}					t_pairint;

typedef struct		s_mchi
{
	char			*str;
	int				type;
	int				len;
	int				t;
	int				whatever;
	int				level;
	struct s_mchi	*next;
}					t_mchi;

typedef struct		s_strmchi
{
	char			*str;
	t_mchi			*mchi;
}					t_strmchi;

extern int			g_iread;
extern int			g_explicitlev;
extern int			g_ifound;

# include "ft_list.h"

# define RGX_END (1 << 0)
# define RGX_RGXN (1 << 1)
# define RGX_STRN (1 << 2)
# define RGX_POS (1 << 3)
# define RGX_GLOBAL (1 << 4)
# define RGX_UGLOBAL (1 << 5)
# define RGX_VAR (1 << 5)
# define RGX_ADD (1 << 6)
# define RGX_GET (1 << 7)
# define RGX_CLEAN (1 << 8)
# define RGX_FREE (1 << 9)
# define RGX_ID (1 << 10)

enum				e_regex_condtion
{
	RGX_GREAT = 1, RGX_LESS, RGX_EQUAL, RGX_MARK
};

typedef struct		s_regex_func t_regex_func;

typedef struct		s_regex_rule
{
	t_regex_func	*func;
	const char		*rule;
	const char		*arg;
	int				len_arg;
	int				len_rule;
	int				cond;
	int				l;
	char			type;
	int				neg;
	int				i;
}					t_regex_rule;

typedef struct		s_regex_info
{
	const char		*param;
	const char		*str_begin;
	const char		*rgx_begin;
	const char		*str;
	const char		*regex;
	const char		*next;
	int				*vars;
	int				len_param;
	int				param_i;
	int				len;
	int				rgxn;
	int				strn;
	int				flags;
	int				*pos;
	int				cid;
	int				*id;
	int				lvl;
	t_list			**matches;
}					t_regex_info;

typedef struct		s_regex_match
{
	const char		*str_begin;
	const char		*str;
	int				pos;
	int				len;
	int				id;
}					t_regex_match;

typedef int	(*t_regex_funcptr)(t_regex_info *regex_info, t_regex_rule *rule);
struct				s_regex_func
{
	const char		*name;
	t_regex_funcptr	func;
	int				id;
};

int					case_rgx(t_regex_info *rgxi, t_regex_rule *rule);
int					bnd_rgx(t_regex_info *rgxi, t_regex_rule *rule);
int					delim_rgx(t_regex_info *rgxi, t_regex_rule *rule);
int					cond_rgx(t_regex_info *rgxi, t_regex_rule *rule);
int					expr_rgx(t_regex_info *rgxi, t_regex_rule *rule);
int					print_rgx(t_regex_info *rgxi, t_regex_rule *rule);
int					getint_rgx(t_regex_info *rgxi, t_regex_rule *rule);
int					debug_rgx(t_regex_info *rgxi, t_regex_rule *rule);
int					recursive_rgx(t_regex_info *rgxi, t_regex_rule *rule);
t_regex_func		*get_regex_func(const char *name, int len_rule, t_regex_info *rgxi);
t_regex_func		*get_regex_rule(const char *name, int len_rule, t_regex_info *rgxi);

int					manage_rules(const char *str, t_list **rules, int flags, va_list vp);
int					regex_loop(t_regex_info *rgxi, t_regex_rule *rule);
int					regex_variable(t_regex_info *rgxi, const char *s);
int					regex_start(t_regex_info *rgxi, t_regex_rule *rule);
int					regex_wildcard(t_regex_info *rgxi);
int					regex_bracket(const char *str, int *s);
int					get_matches(t_regex_info *rgxi);
int					regex_pos(t_regex_info *rgxi);
int					regex_exec(t_regex_info *regex_info);
void				regex_init(t_regex_info *regex_info, const char *regex, const char *str);

int					ft_regex(int flags, const char *regex, const char *str, ...);
void				ft_print_matches(const char *str, t_list *matches);

# define RGX_BKSLSH 2
# define RGX_N 4

t_mchi				*ft_getmchi(const char *match);
void				ft_delmchi(t_mchi *head);
t_mchi				*mchi_db(const char *str);

int					ft_strmatch_old(const char *str, const char *match);
int					ft_strmatch(const char *str, const char *match);
int					ft_strmatchl(const char *str, const char *match);
int					ft_strmatch_x(const char *a, const char *strset);

int					ft_strnmatch(const char *str, const char *match, int n);
int					ft_strnmatchl(const char *str, const char *match, int n);

int					ft_strmatch_opt(const char *str,
							const char *match,
							int option);
int					ft_strnmatch_opt(const char *str,
							const char *match,
							int n,
							int option);

int					ft_strtks(const char *str, t_mchi *tks, int option);
int					ft_strntks(const char *str,
							t_mchi *tks,
							int n,
							int option);

int					checkwild3(const char **str,
							t_mchi *cur,
							t_mchi *nxt,
							int n);

int					ft_wcharlen(wchar_t wc);
char				*ft_getwchar(wchar_t wc);
int					ft_wstrlen(const wchar_t *wcs);
int					ft_wstrnlen(const wchar_t *wcs, int n);
char				*ft_getwstr(const wchar_t *wcs);
char				*ft_getnwstr(const wchar_t *wc, int n);

#endif
