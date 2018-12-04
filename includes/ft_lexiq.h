/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexiq.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 16:12:50 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/29 20:18:34 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXIQ_H
# define FT_LEXIQ_H

# include "ft_list.h"
# include <stdarg.h>

# define LOAD_EXPR "?[?[-#@?]*[@word]@G]*[@space?]?[\"*[\\\"|?![\"]@or?]\"@G]"

# define LQ_END (1 << 0)
# define LQ_EXPRN (1 << 1)
# define LQ_STRN (1 << 2)
# define LQ_POS (1 << 3)
# define LQ_GLOBAL (1 << 4)
# define LQ_UGLOBAL (1 << 5)
# define LQ_VAR (1 << 6)
# define LQ_ADD (1 << 7)
# define LQ_GET (1 << 8)
# define LQ_CLEAN (1 << 9)
# define LQ_FREE (1 << 10)
# define LQ_ID (1 << 11)
# define LQ_DATA (1 << 12)
# define LQ_READABLE (1 << 13)
# define LQ_GROUP (1 << 14)
# define LQ_INNER_GROUP (1 << 15)
# define LQ_IMPORT (1 << 16)
# define LQ_FREEGRP (1 << 17)
# define LQ_ADD_MULTI (1 << 18)
# define LQ_TO (1 << 19)
# define LQ_SET (1 << 20)
# define LQ_GETRULE (1 << 21)
# define LQ_IDSTR (1 << 22)
# define LQ_XREADABLE (1 << 23)
# define LQ_FLAG_NUM 24

enum				e_lexiq_condtion
{
	LQ_GREAT = 1, LQ_LESS, LQ_EQUAL, LQ_MARK
};

typedef struct s_lexiq_func	t_lq_func;

typedef struct		s_lexiq_rule
{
	t_lq_func		*func;
	const char		*rule;
	const char		*arg;
	int				len_arg;
	int				len_rule;
	int				cond;
	int				l;
	char			type;
	int				neg;
	int				i;
}					t_lq_rule;

typedef struct		s_lexiq_eng
{
	const char		*param;
	const char		*str_begin;
	const char		*expr_begin;
	const char		*str;
	const char		*expr;
	const char		*next;
	int				*vars;
	int				len_param;
	int				param_i;
	int				len;
	int				exprn;
	int				strn;
	int				flags;
	int				*pos;
	int				cid;
	int				*id;
	const char		**id_str;
	void			*data;
	t_list			**groups_head;
	t_list			**groups;
	t_list			**free_groups;
	t_list			**matches;
}					t_lq_eng;

typedef struct s_lexiq_match	t_lq_group;
typedef struct		s_lexiq_match
{
	const char		*str_begin;
	const char		*str;
	int				pos;
	int				len;
	int				id;
	const char		*id_str;
	t_list			*groups;
}					t_lq_match;

typedef int	(*t_lq_funcptr)(t_lq_eng *lq_eng, t_lq_rule *rule);
struct				s_lexiq_func
{
	const char		*name;
	const char		*expr;
	t_lq_funcptr	func;
	int				id;
	int				flags;
};
/*
typedef struct		s_func_slot
{
	const char		*name;
	t_list			*slot;
}					t_func_slot;
*/
typedef struct		s_rules
{
	int				n;
	t_list			*rules;
}					t_rules;

int					ugroups_lq(t_lq_eng *lqeng, t_lq_rule *rule);
int					groups_lq(t_lq_eng *lqeng, t_lq_rule *rule);
int					modulus_lq(t_lq_eng *lqeng, t_lq_rule *rule);
int					case_lq(t_lq_eng *lqeng, t_lq_rule *rule);
int					bnd_lq(t_lq_eng *lqeng, t_lq_rule *rule);
int					delim_lq(t_lq_eng *lqeng, t_lq_rule *rule);
int					cond_lq(t_lq_eng *lqeng, t_lq_rule *rule);
int					expr_lq(t_lq_eng *lqeng, t_lq_rule *rule);
int					write_lq(t_lq_eng *lqeng, t_lq_rule *rule);
int					getint_lq(t_lq_eng *lqeng, t_lq_rule *rule);
int					recursive_lq(t_lq_eng *lqeng, t_lq_rule *rule);
int					lexiq_lq(t_lq_eng *lqeng, t_lq_rule *rule);
t_lq_func			*lq_get_func(const char *name,
								int len_rule,
								t_lq_eng *lqeng);

void				lq_free_rule(void *s, size_t p);
void				lq_free_match(void *s, size_t p);
int					lq_manage_rules(t_lq_eng *lqeng,
								t_list **rules,
								int flags,
								va_list vp);
int					lq_import(t_lq_eng *lqeng, t_list **rules);
int					lq_loop(t_lq_eng *lqeng, t_lq_rule *rule);
int					lq_variable(t_lq_eng *lqeng, const char *s);
int					lq_start(t_lq_eng *lqeng, t_lq_rule *rule);
int					lq_wildcard(t_lq_eng *lqeng);
int					lq_bracket(const char *str, int *s);
int					lq_get_matches(t_lq_eng *lqeng);
int					lq_pos(t_lq_eng *lqeng);
int					lq_exec2(t_lq_eng *lqeng);
int					lq_exec(t_lq_eng *lqeng);
void				lq_init(t_lq_eng *lqeng,
								const char *expr,
								const char *str);

int					ft_lexiq(int flags,
								const char *expression,
								const char *str, ...);
void				ft_print_matches(const char *str,
								t_list *matches,
								int print_id);
void				ft_print_matches_tree(t_list *matches, int tab);

/*
ft_lexiq_add(rule_name, expr) -> ft_lexiq(LQ_ADD, rule_name, expr, NULL)
ft_lexiq_addcallback(rule_name, funcptr) -> ft_lexiq(LQ_ADD, rule_name, NULL, funcptr)
ft_lexiq_import(file_name) -> ft_lexiq(LQ_IMPORT, file_name, NULL)
ft_lexiq_getrule(rule_name) -> ft_lexiq(LQ_GETRULE, rule_name, NULL, &return)
ft_lexiq_getrule_byid(id) -> ft_lexiq(LQ_GETRULE, NULL, NULL, id, &return)
ft_lexiq_clean(void) -> ft_lexiq(LQ_CLEAN, NULL, NULL)
ft_lexiq_set(rules) -> ft_lexiq(LQ_SET, NULL, NULL, rules)
ft_lexiq_get(rules) -> ft_lexiq(LQ_GET, NULL, NULL, rules)
ft_lexiq_find(expr, str, len) -> ft_lexiq(LQ_POS | LQ_END, expr, str, &return)
ft_lexiq_match(expr, str) -> ft_lexiq(0, expr, str)
ft_lexiq_matchgrp(expr, str, groups) -> ft_lexiq(LQ_GROUP, expr, str, groups)
ft_lexiq_global(expr, str) -> ft_lexiq(LQ_GLOBAL, expr, str, &return)
ft_lexiq_free(list) -> ft_lexiq(LQ_FREE, NULL, NULL, list)
*/

#endif
