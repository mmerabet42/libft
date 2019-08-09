#include "lexiq.h"
#include "ft_str.h"
#include "ft_list.h"
#include <stdlib.h>

static t_lq_rule_list g_rule_list = {NULL, NULL};

int lq_add_rule(int flags, const char *name, t_lq_node *parser, t_lq_func func)
{
	t_list *list;
	t_lq_rule *rule;

	if (!(rule = (t_lq_rule *)malloc(sizeof(t_lq_rule))))
		return (-1);
	rule->name = name;
	rule->func = func;
	rule->parser = parser;
	rule->flags = flags | LQ_SAVE_RULE_NAME | (parser ? LQ_STOP : 0);
	if (!(list = (t_list *)malloc(sizeof(t_list))))
	{
		free(rule);
		return (-1);
	}
	list->content = (void *)rule;
	list->content_size = sizeof(t_lq_rule);
	list->next = NULL;
	list->parent = g_rule_list.tail;
	if (!(list->parent = g_rule_list.tail))
		g_rule_list.head = list;
	else
		g_rule_list.tail->next = list;
	g_rule_list.tail = list;
	return (0); 
}

int lq_add(int flags, const char *name, t_lq_node *parser, t_lq_func func)
{
	t_lq_rule *rule;
	t_lq_node *it_node;

	if ((rule = lq_get_rule2(name)) && ((parser && rule->func) || (func && rule->parser)))
		return (-1);
	else if (rule)
	{
		if (!(it_node = rule->parser))
		{
			rule->func = func;
			rule->parser = parser;
		}
		while (it_node)
		{
			if (!it_node->next_or)
			{
				it_node->next_or = parser;
				break ;
			}
			it_node = it_node->next_or;	
		}	
		return (0);
	}
	return (lq_add_rule(flags, name, parser, func));
}

t_lq_rule *lq_get_rule2(const char *name)
{
	t_list *it;

	it = g_rule_list.head;
	while (it)
	{
		if (!ft_strcmp(name, ((t_lq_rule *)it->content)->name))
			return ((t_lq_rule *)it->content);
		it = it->next;
	}
	return (NULL);
}
