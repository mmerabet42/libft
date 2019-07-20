#include "lexiq.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

t_lq_node *lq_node(const char *rule, void *arg,
				int min, int max,
				t_lq_node *next_or, t_lq_node *next)
{
	t_lq_node *lq = (t_lq_node *)malloc(sizeof(t_lq_node));
	if (!lq)
		return NULL;
	lq->min = (min > max && max != -1 ? max : min);
	lq->max = (min > max && max != -1 ? min : max);
	lq->rule = lq_get_rule(rule);
	lq->arg = arg;
	lq->next = next;
//	lq->undirect_next = 0;
	if ((lq->next_or = next_or))
		lq->next_or->prev_or = lq;
	
	t_lq_node *it = lq->next_or;
	while (it)
	{
		if (it->next == LQ_PARENT)
			it->next = lq->next;
		it = it->next_or;
	}
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
