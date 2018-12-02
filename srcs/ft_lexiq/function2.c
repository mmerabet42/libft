/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:28:06 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/16 16:35:33 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexiq.h"
#include "ft_types.h"
#include "ft_printf.h"

int	bnd_lq(t_lq_eng *lqeng, t_lq_rule *rule)
{
	(void)rule;
	if (*rule->rule == '^')
	{
		if (lqeng->str == lqeng->str_begin || !ft_isword(*(lqeng->str - 1)))
			return (0);
	}
	else if (!*lqeng->str)
		return (0);
	else if (!ft_isword(*lqeng->str))
	{
		++lqeng->str;
		return (0);
	}
	return (-1);
}

int	write_lq(t_lq_eng *lqeng, t_lq_rule *rule)
{
	int	i;

	if (rule->rule[0] == 't' || rule->rule[0] == 'f')
		return (rule->rule[0] == 't' ? 0 : -1);
	else if (rule->rule[0] == 'd')
	{
		ft_printf("DEBUG \"%.*s\" ->\n\tstr:\t\t'%s'\n\tstr_begin:\t'%s'\n",
				rule->len_arg, rule->arg, lqeng->str, lqeng->str_begin);
		ft_printf("\texpr:\t\t'%s'\n\texpr_begin:\t'%s'\n",
				lqeng->expr, lqeng->expr_begin);
		return (0);
	}
	i = 0;
	while (i < rule->len_arg)
	{
		if (rule->arg[i] == '%' && ft_isalpha(rule->arg[i + 1]))
			ft_printf("%d", lq_variable(lqeng, rule->arg + ++i));
		else
			ft_printf("%c", rule->arg[i]);
		++i;
	}
	ft_printf("\n");
	return (0);
}

int	getint_lq(t_lq_eng *lqeng, t_lq_rule *rule)
{
	int	ret;
	int	i;
	int	n;

	ret = 0;
	if (*rule->rule == 'n')
		ret = ft_lexiq(LQ_END, "?[@nint]", lqeng->str);
	else
		ret = ft_lexiq(LQ_END, "?[@int]", lqeng->str);
	if (!ft_isalpha(rule->arg[0]))
		return (ret);
	n = (ret == -1 ? 0 : ft_atoi(lqeng->str));
	i = 0;
	while (i < rule->len_arg)
	{
		if (ft_islower(rule->arg[i]))
			lqeng->vars[rule->arg[i] - 97] = n;
		else if (ft_isupper(rule->arg[i]))
			lqeng->vars[26 + rule->arg[i] - 65] = n;
		++i;
	}
	return (ret);
}

int	recursive_lq(t_lq_eng *lqeng, t_lq_rule *rule)
{
	t_lq_eng	tmp;

	tmp = *lqeng;
	tmp.len = 0;
	tmp.expr = tmp.expr_begin;
	tmp.flags &= ~(LQ_POS | LQ_GLOBAL | LQ_UGLOBAL | LQ_INNER_GROUP);
	tmp.flags |= LQ_END;
	if (ft_isdigit(*rule->arg))
		tmp.expr += ft_atoi(rule->arg);
	return (lq_exec2(&tmp));
}

int	modulus_lq(t_lq_eng *lqeng, t_lq_rule *rule)
{
	int	i;

	if (*rule->rule == 's')
	{
		lqeng->param = rule->arg;
		lqeng->len_param = rule->len_arg;
		lqeng->param_i = 0;
	}
	else
	{
		i = 0;
		while (i < lqeng->len_param)
		{
			if (lqeng->str[i] != lqeng->param[i])
				return (-1);
			++i;
		}
		return (i);
	}
	return (0);
}
