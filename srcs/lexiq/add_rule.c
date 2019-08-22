#include "lexiq.h"
#include "ft_str.h"
#include "ft_list.h"
#include <stdlib.h>

static t_lq_rule_list g_rule_list = {NULL, NULL};

static int lq_add_rule(int flags, const char *name, t_lq_node *parser, t_lq_func func)
{
	t_lq_rule *rule;
	t_list *list;

	if (!(rule = (t_lq_rule *)malloc(sizeof(t_lq_rule))))
		return (-1);
	rule->name = name;
	rule->func = func;
	rule->parser = parser;
	rule->parsers = NULL;
	rule->parsers_tail = NULL;
	rule->parsers_it = NULL;
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

static t_list *new_rule_list(t_lq_node *parser, t_list *parent)
{
	t_list *list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	list->content = (void *)parser;
	list->content_size = sizeof(t_lq_node);
	list->parent = parent;
	list->next = NULL;
	return (list);
}

static int lq_add_parser(t_lq_rule *rule, t_lq_node *parser)
{
	t_list *list;

	if (!(list = new_rule_list(parser, NULL)))
		return (-1);
	if (rule->parser)
	{
		if (!(rule->parsers = new_rule_list(rule->parser, NULL)))
		{
			free(list);
			return (-1);
		}
		rule->parsers_tail = rule->parsers;
		rule->parser = NULL;
	}
	list->parent = rule->parsers_tail;
	rule->parsers_tail->next = list;
	rule->parsers_tail = list;
	return (0);
}

int lq_add(int flags, const char *name, t_lq_node *parser, t_lq_func func)
{
	t_lq_rule *rule = lq_get_rule(name);

	if (!rule)
		return (lq_add_rule(flags, name, parser, func));
	if (rule->func || func)
		return (-1);
	return (lq_add_parser(rule, parser));
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
