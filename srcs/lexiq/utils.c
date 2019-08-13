#include "lexiq.h"
#include <stdarg.h>

t_lq_eng *lq_eng_copy(t_lq_eng *a, t_lq_eng *b)
{
	a->flags = b->flags;
	a->i = 0;
	a->eng_flags = 0;
	a->str = b->str;
	a->str_p = a->str;
	a->str_begin = b->str_begin;
	a->str_end = b->str_end;
	a->pos = b->pos;
	a->parser_begin = b->parser_begin;
	a->recur = b->recur + 1;
	a->lookahead_ret = b->lookahead_ret;
	a->prev_eng = b;
	a->parent_eng = b->parent_eng;
	a->groups_head = b->groups_head;
	a->groups = b->groups;
	a->master_groups_head = b->master_groups_head;
	a->lookahead_ret = 0;
	a->len_ptr = b->len_ptr;
	if (b->current->rule->flags & LQ_TRANSPARENT)
		a->rule_name_ptr = b->rule_name_ptr;
	else
		a->rule_name_ptr = NULL;
	a->current_group = b->current_group;
	return a;
}

void lq_printf(t_lq_eng *eng, const char *format, ...)
{
	ft_printf("% *c", eng->recur, ' ');
	va_list ap;
	va_start(ap, format);
	ft_vprintf(format, ap);
}
