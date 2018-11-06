/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_function3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:28:48 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/06 20:26:43 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"
#include "ft_str.h"
#include "ft_types.h"
#include "ft_mem.h"

static int	fake_regex(t_regex_info *rgxi, t_regex_info *t, t_regex_rule *rule)
{
	char			*str;
	int				r;

	if (!(str = ft_strndup(&rule->arg[2], rule->len_arg - 2)))
		return (-1);
	*t = *rgxi;
	t->id = NULL;
	t->regex = str;
	t->rgx_begin = str;
	t->len = 0;
	t->flags &= ~(RGX_POS | RGX_GLOBAL | RGX_UGLOBAL | RGX_GROUP);
	t->flags &= ~(RGX_INNER_GROUP);
	t->flags |= RGX_END;
	r = regex_exec(t);
	free(str);
	return (r);
}

static int	get_global(t_regex_info *rgxi, t_regex_info *t, t_regex_rule *r)
{
	char	*str;
	char	*rgx;
	int		res;

	if (!(rgx = ft_strndup(r->arg + 4, r->len_arg - 4)))
		return (-1);
	str = NULL;
	if (r->arg[2] != '-')
		str = ft_strndup(rgxi->str, regex_variable(rgxi, &r->arg[2]));
	else
		str = ft_strdup(rgxi->str);
	if (!str && ft_memdel((void **)&rgx))
		return (-1);
	*t = *rgxi;
	t->rgx_begin = rgx;
	t->regex = rgx;
	t->str_begin = str;
	t->str = str;
	t->matches = NULL;
	t->flags = RGX_GLOBAL;
	res = get_matches(t);
	free(rgx);
	free(str);
	return (res);
}

static int	get_result(t_regex_info *rgxi, t_regex_info *tmp, t_regex_rule *rule)
{
	int		a;
	int		b;
	char	*s;

	if (rule->arg[1] == ',')
		return (get_global(rgxi, tmp, rule));
	a = regex_variable(rgxi, rule->arg + 2);
	if (!(s = ft_strnpbrk(rule->arg + 2, "+-/*%><=!", rule->len_arg - 2)))
		return (a);
	b = regex_variable(rgxi, s + 1);
	if (*s == '+' || *s == '-')
		return (*s == '+' ? (a + b) : (a - b));
	else if (*s == '*')
		return (a * b);
	else if (*s == '=' || *s == '!')
		return (*s == '=' ? (a == b) : (a != b));
	else if (*s == '>' || *s == '<')
		return (*s == '>' ? (a > b) : (a < b));
	else if (*s == '/' && b != 0)
		return (a / b);
	else if (*s == '%' && b != 0)
		return (a % b);
	return (0);
}

int			expr_rgx(t_regex_info *rgxi, t_regex_rule *rule)
{
	int				r;
	int				ret;
	t_regex_info	tmp;

	r = 0;
	if (rule->len_arg <= 1)
		return (-1);
	ret = 0;
	if (rule->arg[1] == ':' || rule->arg[1] == ';')
	{
		r = fake_regex(rgxi, &tmp, rule);
		if (rule->arg[0] == '0')
			return (r == -1 ? -1 : 0);
		else if (rule->arg[1] == ';')
			ret = r;
	}
	else
		r = get_result(rgxi, &tmp, rule);
	if (rule->arg[0] == '0')
		return (r ? 0 : -1);
	if (ft_isupper(rule->arg[0]))
		rgxi->vars[26 + rule->arg[0] - 65] = r;
	else if (ft_islower(rule->arg[0]))
		rgxi->vars[rule->arg[0] - 97] = r;
	return (ret);
}
