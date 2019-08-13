#include "lexiq.h"
#include "ft_str.h"
#include "ft_types.h"
#include "ft_mem.h"

static int lq_rule_string(const char *arg, t_lq_eng *eng);
static int lq_rule_any(const char *arg, t_lq_eng *eng);
static int lq_rule_run(t_lq_node *arg, t_lq_eng *eng);
static int lq_rule_runn(t_lq_node *arg, t_lq_eng *eng);
static int lq_rule_not(void *arg, t_lq_eng *eng);
static int lq_rule_func(t_lq_func func, t_lq_eng *eng);
static int lq_rule_delim(void *arg, t_lq_eng *eng);
static int lq_rule_group(t_lq_node *arg, t_lq_eng *eng);
static int lq_rule_name(const char *name, t_lq_eng *eng);
static int lq_rule_backreference_name(const char *name, t_lq_eng *eng);

static const t_lq_rule g_builtin_rules[] = {
	{"s", (t_lq_func)lq_rule_string, NULL, LQ_TRANSPARENT},
	{"?", (t_lq_func)lq_rule_any, NULL, LQ_TRANSPARENT},
	{"r", (t_lq_func)lq_rule_run, NULL, LQ_STOP | LQ_TRANSPARENT},
	{"rn", (t_lq_func)lq_rule_runn, NULL, LQ_TRANSPARENT},
	{"g", (t_lq_func)lq_rule_group, NULL, LQ_STOP | LQ_TRANSPARENT},
	{"!", (t_lq_func)lq_rule_not, NULL, LQ_TRANSPARENT},
	{"!?", (t_lq_func)lq_rule_not, NULL, LQ_TRANSPARENT},
	{"func", (t_lq_func)lq_rule_func, NULL, LQ_TRANSPARENT},
	{"name", (t_lq_func)lq_rule_name, NULL, LQ_TRANSPARENT},
	{"bn", (t_lq_func)lq_rule_backreference_name, NULL, LQ_TRANSPARENT},

	{"^", (t_lq_func)lq_rule_delim, NULL, LQ_TRANSPARENT},
	{"$", (t_lq_func)lq_rule_delim, NULL, LQ_TRANSPARENT},
	{"^n", (t_lq_func)lq_rule_delim, NULL, LQ_TRANSPARENT},
	{"$n", (t_lq_func)lq_rule_delim, NULL, LQ_TRANSPARENT},
	{"^w", (t_lq_func)lq_rule_delim, NULL, LQ_TRANSPARENT},
	{"$w", (t_lq_func)lq_rule_delim, NULL, LQ_TRANSPARENT},
};
static const size_t g_builtin_rules_len = (sizeof(g_builtin_rules) / sizeof(g_builtin_rules[0]));

const t_lq_rule *lq_get_rule(const char *name)
{
	size_t i;

	i = 0;
	while (i < g_builtin_rules_len)
	{
		if (!ft_strcmp(name, g_builtin_rules[i].name))
			return (&g_builtin_rules[i]);
		++i;
	}
	return (lq_get_rule2(name));
}

static int lq_rule_string(const char *arg, t_lq_eng *eng)
{
	size_t i;

	i = 0;
	while (arg[i] && (eng->str + i) < eng->str_end && eng->str[i] == arg[i])
		++i;
	if (arg[i])
		return -1;
	return i;
}

static int lq_rule_any(const char *arg, t_lq_eng *eng)
{
	if (!*eng->str)
		return -1;
	if (!*arg)
		return 1;
	while (*arg)
	{
		if (*(arg + 1) == '-' && *(arg + 2))
		{
			if (*eng->str >= *arg && *eng->str <= *(arg + 2))
				return 1;
			arg += 3;
		}
		else
		{
			if (*eng->str == *arg)
				return 1;
			++arg;
		}
	}
	return -1;
}

static int lq_rule_run(t_lq_node *arg, t_lq_eng *eng)
{
	t_lq_eng eng2;
	int ret = 0;

	lq_eng_copy(&eng2, eng);
	eng2.parent_eng = eng;
	eng->lookahead_ret = 0;
	if (!arg)
		arg = eng->parser_begin;
	ret = lq_run(arg, &eng2);
	//lq_printf(eng, "run ret: %d %d\n", ret, eng->lookahead_ret);
	if (ret <= -1)
		return ret;
	else if (eng->lookahead_ret <= -1)
		return eng->lookahead_ret;
	return ret + eng->lookahead_ret;
}

static int lq_rule_runn(t_lq_node *arg, t_lq_eng *eng)
{
	t_lq_eng eng2;
	int ret = 0;

	lq_eng_copy(&eng2, eng);
	eng2.parent_eng = NULL;
	eng->lookahead_ret = 0;
	eng2.flags |= LQ_END;
	if (!arg)
		arg = eng->parser_begin;
	ret = lq_run(arg, &eng2);
	//lq_printf(eng, "run ret: %d %d\n", ret, eng->lookahead_ret);
	if (ret <= -1)
		return ret;
	else if (eng->lookahead_ret <= -1)
		return eng->lookahead_ret;
	return ret + eng->lookahead_ret;
}

static int lq_rule_group(t_lq_node *arg, t_lq_eng *eng)
{
	t_lq_eng eng2;
	int ret;
	t_lq_group group;
	t_lq_list group_list;
	t_lq_list *group_list_ptr;

	group_list.match = &group;
	group_list.size = sizeof(group);
	group_list.next = NULL;
	if ((group_list.parent = *eng->groups))
		(*eng->groups)->next = &group_list;
	else
		eng->groups_head = &group_list;
	*eng->groups = &group_list;
	group.str_begin = eng->str_begin;
	group.str = eng->str;
	group.pos = (int)(eng->str - eng->str_begin);
	group.groups = NULL;
	group.name = NULL;
	group.rule_name = NULL;
	group.len = 0;
	eng->len_ptr = &group.len;
	eng->rule_name_ptr = &group.rule_name;
	eng->current_group = &group;
	lq_eng_copy(&eng2, eng);
	eng2.groups = &group.groups;
	eng2.groups_head = NULL;
	eng2.parent_eng = eng;
	eng->lookahead_ret = 0;
	if (!arg)
		arg = eng->parser_begin;
	ret = lq_run(arg, &eng2);
//	group.len = ret;
//	eng->len_ptr = NULL;
	if (ret <= -1 || eng->lookahead_ret <= -1)
	{
		if ((*eng->groups = group_list.parent))
			group_list.parent->next = NULL;
		return (ret <= -1 ? ret : eng->lookahead_ret);
	}
	if (!(group_list_ptr = ft_memdup(&group_list, sizeof(t_lq_list))))
		return -1;
	if (!(group_list_ptr->match = ft_memdup(&group, sizeof(t_lq_group))))
		return -1;
	if (group_list_ptr->parent)
		group_list_ptr->parent->next = group_list_ptr;
	else
		eng->groups_head = group_list_ptr;
	*eng->groups = group_list_ptr;
	eng->current_group = group_list_ptr->match;
//	lq_printf(eng, "|captured: '%.*s' %d %d %d\n", ret, eng->str, ret, eng->lookahead_ret, group.len);
	return ret + eng->lookahead_ret;
}

static int lq_rule_not(void *arg, t_lq_eng *eng)
{
	t_lq_eng eng2;

	if (eng->current->rule->name[1] == '?')
	{
		if (*eng->str && lq_rule_any((const char *)arg, eng) < 0)
			return 1;
		return -1;
	}
	lq_eng_copy(&eng2, eng);
	eng2.flags |= LQ_END;
	if (lq_run((t_lq_node *)arg, lq_eng_copy(&eng2, eng)) == -1)
		return 1;
	return -1;
}

static int lq_rule_func(t_lq_func func, t_lq_eng *eng)
{
	if (func)
		func(NULL, eng);
	return 0;
}

static int lq_rule_delim(void *arg, t_lq_eng *eng)
{
	(void)arg;
	if (eng->current->rule->name[0] == '^')
	{
		if (eng->str == eng->str_begin)
			return 0;
		if (ft_strchr("nw", eng->current->rule->name[1]))
		{
			if (*(eng->str - 1) == '\n')
				return 0;
			if (eng->current->rule->name[1] == 'w')
			{
				if (!(ft_isalpha(*(eng->str - 1)) || ft_isdigit(*(eng->str - 1))
						|| *(eng->str - 1) == '_'))
					return 0;
			}
		}
	}
	else if (eng->current->rule->name[0] == '$')
	{	
		if (eng->str == eng->str_end)
			return 0;
		if (ft_strchr("nw", eng->current->rule->name[1]))
		{
			if (*eng->str == '\n')
				return 0;
			if (eng->current->rule->name[1] == 'w')
			{
				if (!(ft_isalpha(*eng->str) || ft_isdigit(*eng->str) || *eng->str == '_'))
					return 0;
			}	
		}
	}
	return -1;
}

static int lq_rule_name(const char *name, t_lq_eng *eng)
{
	if (eng->current_group)
		eng->current_group->name = name;
	return 0;
}

static int lq_rule_backreference_name(const char *name, t_lq_eng *eng)
{
	(void)name; (void)eng;	
	return (0);
}
