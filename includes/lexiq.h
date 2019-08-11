#ifndef LEXIQ_H
# define LEXIQ_H

# include <stdlib.h>
# include "ft_printf.h"
# include "ft_list.h"

# define LQ_COMPILE (1 << 0)
# define LQ_RUN (1 << 1)
# define LQ_END (1 << 2)
# define LQ_POS (1 << 3)
# define LQ_STREND (1 << 4)
# define LQ_LOOKAHEAD (1 << 5)
# define LQ_GROUPS (1 << 6)
# define LQ_ADD (1 << 7)
# define LQ_FUNC (1 << 8)
# define LQ_FIND (LQ_RUN | LQ_POS | LQ_END)

# define LQ_STOP (1 << 0)
# define LQ_SAVE_RULE_NAME (1 << 1)
# define LQ_TRANSPARENT (1 << 2)

# define LQ_VAR_NUM 100

typedef struct s_lq_rule t_lq_rule;
typedef struct s_lq_match t_lq_match;
typedef struct s_lq_match t_lq_group;
typedef struct s_lq_list t_lq_list;

typedef struct s_lq_quant t_lq_quant;
struct s_lq_quant
{
	int min;
	int max;
	unsigned int min_var:1;
	unsigned int max_var:1;
};

t_lq_quant lq_quant(int min, int max);
t_lq_quant lq_quant0(int min, int max);
t_lq_quant lq_quant1(int min, int max);
t_lq_quant lq_quant2(int min, int max);

typedef struct s_lq_node t_lq_node;
struct s_lq_node
{
	const char *rule_name;
	const t_lq_rule *rule;
	void *arg;
	t_lq_quant quant;
	t_lq_node *next;
	t_lq_node *next_or;
};

typedef struct s_lq_eng t_lq_eng;
struct s_lq_eng
{
	t_lq_node *parser_begin;
	t_lq_node *current;
	t_lq_eng *parent_eng;
	t_lq_eng *prev_eng;
	t_lq_list **groups;
	t_lq_list *groups_head;
	t_lq_group *current_group;
	const char *str;
	const char *str_p;
	const char *str_begin;
	const char *str_end;
	int flags;
	int eng_flags;
	int *pos;
	int *len_ptr;
	const char **rule_name_ptr;
	int recur;
	int i;
	int lookahead_ret;
	int *vars;
};

typedef int(*t_lq_func)(void *arg, t_lq_eng *eng);

struct s_lq_rule
{
	const char *name;
	t_lq_func func;
	t_lq_node *parser;
	int flags;
};

typedef struct s_lq_rule_list
{
	t_list *head;
	t_list *tail;
} t_lq_rule_list;

struct s_lq_match
{
	const char *str_begin;
	const char *str;
	int pos;
	int len;
	const char *name;
	const char *rule_name;
	t_lq_list *groups;
};

struct s_lq_list
{
	struct s_lq_match *match;
	size_t size;
	t_lq_list *next;
	t_lq_list *parent;
};

void ft_print_matches(const char *str,t_lq_list *matches);
void ft_print_matches_tree(t_lq_list *matches, int tab);

void lq_printf(t_lq_eng *eng, const char *format, ...);

t_lq_eng *lq_eng_copy(t_lq_eng *a, t_lq_eng *b);

t_lq_node *lq_node(const char *rule, void *arg,
				t_lq_quant quant,
				t_lq_node *next_or, t_lq_node *next);
void lq_node_del(t_lq_node **lq);

int get_min(t_lq_eng *eng);
int get_max(t_lq_eng *eng);

const t_lq_rule *lq_get_rule(const char *name);
t_lq_rule *lq_get_rule2(const char *name);

int lq_add(int flags, const char *name, t_lq_node *parser, t_lq_func func);

int lq_compile(int flags, const char *expr);
int lq_run(t_lq_node *parser, t_lq_eng *eng);
int lq_pos(t_lq_node *parser, t_lq_eng *eng);

int lexiq(int flags, ...);

#endif // LEXIQ_H
