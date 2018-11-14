/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 16:12:50 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/14 18:29:38 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REGEX_H
# define FT_REGEX_H

# include "ft_list.h"
# include "ft_printf.h"
# include <stdarg.h>

# define LOAD_REGEX "?[?[-@?]*[@word]@G]*[@space?]?[\"*[\\\"|?![\"]@or?]\"@G]"
# define CONTROL_REGEX "#?[*[@word]@G]*[@space?]?[\"*[\\\"|?![\"]@or?]\"@G]"

# define RGX_END (1 << 0)
# define RGX_RGXN (1 << 1)
# define RGX_STRN (1 << 2)
# define RGX_POS (1 << 3)
# define RGX_GLOBAL (1 << 4)
# define RGX_UGLOBAL (1 << 5)
# define RGX_VAR (1 << 6)
# define RGX_ADD (1 << 7)
# define RGX_GET (1 << 8)
# define RGX_CLEAN (1 << 9)
# define RGX_FREE (1 << 10)
# define RGX_ID (1 << 11)
# define RGX_DATA (1 << 12)
# define RGX_READABLE (1 << 13)
# define RGX_GROUP (1 << 14)
# define RGX_INNER_GROUP (1 << 15)
# define RGX_IMPORT (1 << 16)
# define RGX_FREEGRP (1 << 17)
# define RGX_ADD_MULTI (1 << 18)
# define RGX_TO (1 << 19)
# define RGX_SET (1 << 20)
# define RGX_FLAG_NUM 21

enum				e_regex_condtion
{
	RGX_GREAT = 1, RGX_LESS, RGX_EQUAL, RGX_MARK
};

typedef struct s_regex_func	t_regex_func;

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
	void			*data;
	t_list			**groups_head;
	t_list			**groups;
	t_list			**free_groups;
	t_list			**matches;
}					t_regex_info;

typedef struct s_regex_match	t_regex_group;
typedef struct		s_regex_match
{
	const char		*str_begin;
	const char		*str;
	int				pos;
	int				len;
	int				id;
	const char		*id_str;
	t_list			*groups;
}					t_regex_match;

typedef int	(*t_regex_funcptr)(t_regex_info *regex_info, t_regex_rule *rule);
struct				s_regex_func
{
	const char		*name;
	const char		*regex;
	t_regex_funcptr	func;
	int				id;
	int				flags;
};

int					ugroups_rgx(t_regex_info *rgxi, t_regex_rule *rule);
int					groups_rgx(t_regex_info *rgxi, t_regex_rule *rule);
int					modulus_rgx(t_regex_info *rgxi, t_regex_rule *rule);
int					case_rgx(t_regex_info *rgxi, t_regex_rule *rule);
int					bnd_rgx(t_regex_info *rgxi, t_regex_rule *rule);
int					delim_rgx(t_regex_info *rgxi, t_regex_rule *rule);
int					cond_rgx(t_regex_info *rgxi, t_regex_rule *rule);
int					expr_rgx(t_regex_info *rgxi, t_regex_rule *rule);
int					write_rgx(t_regex_info *rgxi, t_regex_rule *rule);
int					getint_rgx(t_regex_info *rgxi, t_regex_rule *rule);
int					recursive_rgx(t_regex_info *rgxi, t_regex_rule *rule);
int					regex_rgx(t_regex_info *rgxi, t_regex_rule *rule);
t_regex_func		*get_regex_func(const char *name,
								int len_rule,
								t_regex_info *rgxi);

void				free_rule(void *s, size_t p);
void				free_match(void *s, size_t p);
int					manage_rules(t_regex_info *rgxi,
								t_list **rules,
								int flags,
								va_list vp);
int					regex_load(t_regex_info *rgxi, t_list **rules);
int					regex_loop(t_regex_info *rgxi, t_regex_rule *rule);
int					regex_variable(t_regex_info *rgxi, const char *s);
int					regex_start(t_regex_info *rgxi, t_regex_rule *rule);
int					regex_wildcard(t_regex_info *rgxi);
int					regex_bracket(const char *str, int *s);
int					get_matches(t_regex_info *rgxi);
int					regex_pos(t_regex_info *rgxi);
int					regex_exec2(t_regex_info *regex_info);
int					regex_exec(t_regex_info *regex_info);
void				regex_init(t_regex_info *regex_info,
								const char *regex,
								const char *str);

int					ft_regex(int flags,
								const char *regex,
								const char *str, ...);
void				ft_print_matches(const char *str, t_list *matches);
void				ft_print_groups(struct s_regex_match *m,
								t_list *groups,
								const char *def);
void				print_matches(t_list *matches);

#endif
