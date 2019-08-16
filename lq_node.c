#include "lexiq.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

t_lq_node *lq_node(const char *rule, void *arg,
				t_lq_quant quant,
				t_lq_node *next_or, t_lq_node *next)
{
	t_lq_node *lq = (t_lq_node *)malloc(sizeof(t_lq_node));
	if (!lq)
		return NULL;
	lq->rule_name = rule;
	lq->rule = lq_get_rule(rule);
	lq->arg = arg;
	lq->quant = quant;
	lq->next = next;
	lq->next_or = next_or;
	return lq;
}

void lq_node_del(t_lq_node **lq)
{
	if (!lq || !*lq)
		return ;
	t_lq_node *next = (*lq)->next;
	t_lq_node *next_or = (*lq)->next_or;
	free(*lq);
	*lq = NULL;
	lq_node_del(&next);
	lq_node_del(&next_or);
}

int get_min(t_lq_eng *eng)
{
	if (!eng->current->quant.min_var)
		return eng->current->quant.min;
	if (eng->current->quant.min < LQ_VAR_NUM)
		return eng->vars[eng->current->quant.min];
	return 0;
}

int get_max(t_lq_eng *eng)
{
	if (!eng->current->quant.max_var)
		return eng->current->quant.max;
	if (eng->current->quant.max < LQ_VAR_NUM)
		return eng->vars[eng->current->quant.max];
	return 0;
}
