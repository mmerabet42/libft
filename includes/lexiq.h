#ifndef LEXIQ_H
# define LEXIQ_h

# include "ft_printf.h"

# define LQ_COMPILE (1 << 0)
# define LQ_RUN (1 << 1)
# define LQ_END (1 << 2)
# define LQ_POS (1 << 3)
# define LQ_ATTACH (1 << 4)
# define LQ_FIND (LQ_RUN | LQ_POS | LQ_END)
# define LQ_STREND (1 << 5)
# define LQ_LOOKAHEAD (1 << 6)

# define LQ_STOP (1 << 0)

# define LQ_PARENT ((t_lq_node *)0x10)

typedef struct s_lq_rule t_lq_rule;

typedef struct s_lq_node t_lq_node;
struct s_lq_node
{
	int min;
	int max;
	const t_lq_rule *rule;
	void *arg;
	t_lq_node *next;
	t_lq_node *prev;
	t_lq_node *next_or;
	t_lq_node *prev_or;
};

typedef struct s_lq_eng t_lq_eng;
struct s_lq_eng
{
	const char *str;
	const char *str_begin;
	const char *str_end;
	int flags;
	int eng_flags;
	int *pos;
	int recur;
	int i;
	int *lookahead_ret;
	t_lq_node *lookahead;
	t_lq_node *parser_begin;
	t_lq_node *current;
	t_lq_eng *prev_eng;
};

typedef int(*t_lq_func)(void *arg, t_lq_eng *eng);

struct s_lq_rule
{
	const char *name;
	t_lq_func func;
	int flags;
};

void lq_printf(t_lq_eng *eng, const char *format, ...);

t_lq_eng *lq_eng_copy(t_lq_eng *a, t_lq_eng *b);

t_lq_node *lq_node(const char *rule, void *arg,
				int min, int max,
				t_lq_node *next_or, t_lq_node *next);
void lq_node_del(t_lq_node **lq);

const t_lq_rule *lq_get_rule(const char *name);

int lq_compile(int flags, const char *expr);
int lq_run(int flags, t_lq_node *parser, t_lq_eng *eng);
int lq_pos(int flags, t_lq_node *parser, t_lq_eng *eng);

int lexiq(int flags, ...);

#endif // LEXIQ_H
