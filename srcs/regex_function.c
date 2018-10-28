/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:31:44 by mmerabet          #+#    #+#             */
/*   Updated: 2018/10/28 16:09:07 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"
#include "ft_str.h"
#include "ft_math.h"

static int			default_rgx(t_regex_info *rgxi, t_regex_rule *rule)
{
	int	i;

	i = 0;
	while (i < rule->len_arg)
	{
		if (i + 2 < rule->len_arg && rule->arg[i + 1] == '-')
		{
			if (*rgxi->str >= rule->arg[i] && *rgxi->str <= rule->arg[i + 2])
				return (1);
			i += 2;
		}
		else if (*rgxi->str == rule->arg[i])
			return (1);
		++i;
	}
	if (!i)
		return (1);
	return (-1);
}

static int			other_rgx(t_regex_info *rgxi, t_regex_rule *rule)
{
	t_regex_info	rgxi2;

	regex_init(&rgxi2, rule->func->regex, rgxi->str);
	rgxi2.str_begin = rgxi->str_begin;
	rgxi2.flags = (RGX_END | (rule->func->flags & RGX_READABLE));
	rgxi2.param = rule->arg;
	rgxi2.len_param = rule->len_arg;
	rgxi2.vars = rgxi->vars;
	if (rgxi->cid == -2)
		rgxi2.id = rgxi->id;
	return (regex_exec(&rgxi2));
}

static int			regex_rgx(t_regex_info *rgxi, t_regex_rule *rule)
{
	char			*str;
	int				ret;
	t_regex_info	rgxi2;

	if (!(str = ft_strndup(rule->arg, rule->len_arg)))
		return (-1);
	rgxi2 = *rgxi;
	rgxi2.len = 0;
	rgxi2.flags = (RGX_END | (rgxi->flags & RGX_READABLE));
	rgxi2.regex = str;
	rgxi2.rgx_begin = str;
	ret = regex_exec(&rgxi2);
	free(str);
	if (*rule->rule == ',' || *rule->rule == ';')
	{
		if (*rule->rule == ',' && ret != -1)
			rgxi->str += ret;
		return (ret == -1 ? -1 : 0);
	}
	else if (*rule->rule == '!')
		return (ret == -1 ? 1 : -1);
	return (ret);
}

static t_regex_func	g_regexfs[] = {
	{"DEFAULT", NULL, default_rgx, 0, 0},
	{"OTHER", NULL, other_rgx, 0, 0},
	{"^", NULL, delim_rgx, 0, 0},
	{"$", NULL, delim_rgx, 0, 0},
	{"^n", NULL, delim_rgx, 0, 0},
	{"$n", NULL, delim_rgx, 0, 0},
	{"^w", NULL, bnd_rgx, 0, 0},
	{"$w", NULL, bnd_rgx, 0, 0},
	{"or", NULL, cond_rgx, 0, 0},
	{"and", NULL, cond_rgx, 0, 0},
	{"ror", NULL, cond_rgx, 0, 0},
	{"!", NULL, regex_rgx, 0, 0},
	{",", NULL, regex_rgx, 0, 0},
	{";", NULL, regex_rgx, 0, 0},
	{"R", NULL, recursive_rgx, 0, 0},
	{"E", NULL, expr_rgx, 0, 0},
	{"X", NULL, regex_rgx, 0, 0},

	{"upper", "?[A-Z]", NULL, 0, 0},
	{"lower", "?[a-z]", NULL, 0, 0},
	{"digit", "?[0-9]", NULL, 0, 0},
	{"alpha", "?[a-zA-Z]", NULL, 0, 0},
	{"alnum", "?[a-zA-Z0-9]", NULL, 0, 0},
	{"punct", "?[?![@alnum]&?![@space]@and]", NULL, 0, 0},
	{"word", "?[a-zA-Z0-9_]", NULL, 0, 0},
	{"space", "?[ \f\n\t\r\v]", NULL, 0, 0},
	{"nspace", "?[ \t\r\v]", NULL, 0, 0},
	{"int", "*[@space?]?[+-@?]*[0-9]", NULL, 0, 0},
	{"nint", "?[+-@?]*[0-9]", NULL, 0, 0},
	{"uint", "*[@space?]*[0-9]", NULL, 0, 0},
	{"getint", NULL, getint_rgx, 0, 0},
	{"ngetint", NULL, getint_rgx, 0, 0},

	{"print", NULL, print_rgx, 0, 0},
	{"case", NULL, case_rgx, 0, 0},
	{"return", NULL, print_rgx, 0, 0},
	{"debug", NULL, debug_rgx, 0, 0},
	{"%", NULL, modulus_rgx, 0, 0},
	{"set%", NULL, modulus_rgx, 0, 0},
	{"equ", "?[@%]", NULL, 0, 0},
	{"inf", "?[@inf]", NULL, 0, 0},
};
static size_t		g_regex_len = (sizeof(g_regexfs) / sizeof(t_regex_func));

static t_regex_func	*get_regex_rule(const char *name, int len_rule,
						t_regex_info *rgxi)
{
	t_list			*rules;
	t_regex_func	*func;
	int				len;

	rules = NULL;
	ft_regex(RGX_GET, NULL, NULL, &rules);
	while (rules)
	{
		func = (t_regex_func *)rules->content;
		len = ft_strlen(func->name);
		if (ft_strnequ(name, func->name, ft_max(len_rule, len)))
		{
			if (rgxi && rgxi->id)
				*rgxi->id = func->id;
			return (func);
		}
		rules = rules->next;
	}
	return (NULL);
}

t_regex_func		*get_regex_func(const char *name, int len_rule,
						t_regex_info *rgxi)
{
	size_t	i;
	int		len;

	if (!len_rule || !name || !*name)
		return (get_regex_func("DEFAULT", 7, rgxi));
	i = 0;
	while (i < g_regex_len)
	{
		len = ft_strlen(g_regexfs[i].name);
		if (ft_strnequ(name, g_regexfs[i].name, ft_max(len_rule, len)))
		{
			if (rgxi && rgxi->id)
				*rgxi->id = g_regexfs[i].id;
			return (&g_regexfs[i]);
		}
		++i;
	}
	return (get_regex_rule(name, len_rule, rgxi));
}
