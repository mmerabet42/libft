#include "lexiq.h"
#include <string.h>
#include <ctype.h>

static int lq_rule_string(const char *arg, t_lq_eng *eng);
static int lq_rule_any(const char *arg, t_lq_eng *eng);
static int lq_rule_run(t_lq_node *arg, t_lq_eng *eng);
static int lq_rule_not(void *arg, t_lq_eng *eng);
static int lq_rule_func(t_lq_func func, t_lq_eng *eng);
static int lq_rule_delim(void *arg, t_lq_eng *eng);
//static int lq_rule_group(t_lq_node *arg, t_lq_eng *eng);

static const t_lq_rule g_builtin_rules[] = {
	{"s", (t_lq_func)lq_rule_string, 0},
	{"?", (t_lq_func)lq_rule_any, 0},
	{"r", (t_lq_func)lq_rule_run, LQ_STOP},
	{"r1", (t_lq_func)lq_rule_run, LQ_STOP},
	{"r2", (t_lq_func)lq_rule_run, LQ_STOP},
	{"r3", (t_lq_func)lq_rule_run, LQ_STOP},
	{"r4", (t_lq_func)lq_rule_run, LQ_STOP},
	{"r5", (t_lq_func)lq_rule_run, LQ_STOP},
	{"r6", (t_lq_func)lq_rule_run, LQ_STOP},
	{"r7", (t_lq_func)lq_rule_run, LQ_STOP},
	{"!", (t_lq_func)lq_rule_not, 0},
	{"!?", (t_lq_func)lq_rule_not, 0},
//	{"g", (t_lq_func)lq_rule_group, 0},
	{"func", (t_lq_func)lq_rule_func, 0},

	{"^", (t_lq_func)lq_rule_delim, 0},
	{"$", (t_lq_func)lq_rule_delim, 0},
	{"^n", (t_lq_func)lq_rule_delim, 0},
	{"$n", (t_lq_func)lq_rule_delim, 0},
	{"^w", (t_lq_func)lq_rule_delim, 0},
	{"$w", (t_lq_func)lq_rule_delim, 0},
};
static const size_t g_builtin_rules_len = (sizeof(g_builtin_rules) / sizeof(g_builtin_rules[0]));

const t_lq_rule *lq_get_rule(const char *name)
{
	size_t i;

	i = 0;
	while (i < g_builtin_rules_len)
	{
		if (!strcmp(name, g_builtin_rules[i].name))
			return &g_builtin_rules[i];
		++i;
	}
	return NULL;
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
	ret = lq_run(eng->flags, arg, &eng2);
	lq_printf(eng, "|run: '%s' %d %d\n", arg->rule->name, ret, eng->lookahead_ret);
	if (ret <= -1)
		return ret;
	else if (eng->lookahead_ret <= -1)
		return eng->lookahead_ret;
	eng->eng_flags |= LQ_STOP;
	return ret + eng->lookahead_ret;
}

static int lq_rule_not(void *arg, t_lq_eng *eng)
{
	t_lq_eng eng2;

	if (eng->current->rule->name[1] == '?')
	{
		if (*eng->str && lq_rule_any((const char *)arg, eng) < 0)
			return 1;
	}
	else if (lq_run(LQ_RUN | LQ_END, (t_lq_node *)arg, lq_eng_copy(&eng2, eng)) == -1)
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
		if (strchr("nw", eng->current->rule->name[1]))
		{
			if (*(eng->str - 1) == '\n')
				return 0;
			if (eng->current->rule->name[1] == 'w')
			{
				if (!(isalpha(*(eng->str - 1)) || isdigit(*(eng->str - 1))
						|| *(eng->str - 1) == '_'))
					return 0;
			}	
		}
	}
	else if (eng->current->rule->name[0] == '$')
	{	
		if (eng->str == eng->str_end)
			return 0;
		if (strchr("nw", eng->current->rule->name[1]))
		{
			if (*eng->str == '\n')
				return 0;
			if (eng->current->rule->name[1] == 'w')
			{
				if (!(isalpha(*eng->str) || isdigit(*eng->str) || *eng->str == '_'))
					return 0;
			}	
		}
	}
	return -1;
}
