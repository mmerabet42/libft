/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_function2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:28:06 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/16 16:35:33 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"
#include "ft_types.h"
#include "ft_printf.h"

int	bnd_rgx(t_regex_info *rgxi, t_regex_rule *rule)
{
	(void)rule;
	if (*rule->rule == '^')
	{
		if (rgxi->str == rgxi->str_begin || !ft_isword(*(rgxi->str - 1)))
			return (0);
	}
	else if (!*rgxi->str)
		return (0);
	else if (!ft_isword(*rgxi->str))
	{
		++rgxi->str;
		return (0);
	}
	return (-1);
}

int	write_rgx(t_regex_info *rgxi, t_regex_rule *rule)
{
	int	i;

	if (rule->rule[0] == 't' || rule->rule[0] == 'f')
		return (rule->rule[0] == 't' ? 0 : -1);
	else if (rule->rule[0] == 'd')
	{
		ft_printf("DEBUG \"%.*s\" ->\n\tstr:\t\t'%s'\n\tstr_begin:\t'%s'\n",
				rule->len_arg, rule->arg, rgxi->str, rgxi->str_begin);
		ft_printf("\tregex:\t\t'%s'\n\tregex_begin:\t'%s'\n",
				rgxi->regex, rgxi->rgx_begin);
		return (0);
	}
	i = 0;
	while (i < rule->len_arg)
	{
		if (rule->arg[i] == '%' && ft_isalpha(rule->arg[i + 1]))
			ft_printf("%d", regex_variable(rgxi, rule->arg + ++i));
		else
			ft_printf("%c", rule->arg[i]);
		++i;
	}
	ft_printf("\n");
	return (0);
}

int	getint_rgx(t_regex_info *rgxi, t_regex_rule *rule)
{
	int	ret;
	int	i;
	int	n;

	ret = 0;
	if (*rule->rule == 'n')
		ret = ft_regex(RGX_END, "?[@nint]", rgxi->str);
	else
		ret = ft_regex(RGX_END, "?[@int]", rgxi->str);
	if (!ft_isalpha(rule->arg[0]))
		return (ret);
	n = (ret == -1 ? 0 : ft_atoi(rgxi->str));
	i = 0;
	while (i < rule->len_arg)
	{
		if (ft_islower(rule->arg[i]))
			rgxi->vars[rule->arg[i] - 97] = n;
		else if (ft_isupper(rule->arg[i]))
			rgxi->vars[26 + rule->arg[i] - 65] = n;
		++i;
	}
	return (ret);
}

int	recursive_rgx(t_regex_info *rgxi, t_regex_rule *rule)
{
	t_regex_info	tmp;

	tmp = *rgxi;
	tmp.len = 0;
	tmp.regex = tmp.rgx_begin;
	tmp.flags &= ~(RGX_POS | RGX_GLOBAL | RGX_UGLOBAL | RGX_INNER_GROUP);
	tmp.flags |= RGX_END;
	if (ft_isdigit(*rule->arg))
		tmp.regex += ft_atoi(rule->arg);
	return (regex_exec2(&tmp));
}

int	modulus_rgx(t_regex_info *rgxi, t_regex_rule *rule)
{
	int	i;

	if (*rule->rule == 's')
	{
		rgxi->param = rule->arg;
		rgxi->len_param = rule->len_arg;
		rgxi->param_i = 0;
	}
	else
	{
		i = 0;
		while (i < rgxi->len_param)
		{
			if (rgxi->str[i] != rgxi->param[i])
				return (-1);
			++i;
		}
		return (i);
	}
	return (0);
}
