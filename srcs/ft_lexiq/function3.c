/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:28:48 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/16 16:33:19 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexiq.h"
#include "ft_str.h"
#include "ft_types.h"
#include "ft_mem.h"

static int	fake_expr(t_lq_eng *lqeng, t_lq_eng *t, t_lq_rule *rule)
{
	char			*str;
	int				r;

	if (!(str = ft_strndup(&rule->arg[2], rule->len_arg - 2)))
		return (-1);
	*t = *lqeng;
	t->id = NULL;
	t->expr = str;
	t->expr_begin = str;
	t->len = 0;
	t->flags &= ~(LQ_POS | LQ_GLOBAL | LQ_UGLOBAL | LQ_GROUP);
	t->flags &= ~(LQ_INNER_GROUP);
	t->flags |= LQ_END;
	r = lq_exec(t);
	free(str);
	return (r);
}

static int	get_global(t_lq_eng *lqeng, t_lq_eng *t, t_lq_rule *r)
{
	char	*str;
	char	*expr;
	int		res;

	if (!(expr = ft_strndup(r->arg + 4, r->len_arg - 4)))
		return (-1);
	str = NULL;
	if (r->arg[2] != '-')
		str = ft_strndup(lqeng->str, lq_variable(lqeng, &r->arg[2]));
	else
		str = ft_strdup(lqeng->str);
	if (!str && ft_memdel((void **)&expr))
		return (-1);
	*t = *lqeng;
	t->expr_begin = expr;
	t->expr = expr;
	t->str_begin = str;
	t->str = str;
	t->matches = NULL;
	t->flags = LQ_GLOBAL;
	res = lq_get_matches(t);
	free(expr);
	free(str);
	return (res);
}

static int	get_result(t_lq_eng *lqeng, t_lq_eng *tmp, t_lq_rule *rule)
{
	int		a;
	int		b;
	char	*s;

	if (rule->arg[1] == ',')
		return (get_global(lqeng, tmp, rule));
	a = lq_variable(lqeng, rule->arg + 2);
	if (!(s = ft_strnpbrk(rule->arg + 2, "+-/*%><=!", rule->len_arg - 2)))
		return (a);
	b = lq_variable(lqeng, s + 1);
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

int			expr_lq(t_lq_eng *lqeng, t_lq_rule *rule)
{
	int				r;
	int				ret;
	t_lq_eng		tmp;

	r = 0;
	if (rule->len_arg <= 1)
		return (-1);
	ret = 0;
	if (rule->arg[1] == ':' || rule->arg[1] == ';')
	{
		r = fake_expr(lqeng, &tmp, rule);
		if (rule->arg[0] == '0')
			return (r == -1 ? -1 : 0);
		else if (rule->arg[1] == ';')
			ret = r;
	}
	else
		r = get_result(lqeng, &tmp, rule);
	if (rule->arg[0] == '0')
		return (r ? 0 : -1);
	if (ft_isupper(rule->arg[0]))
		lqeng->vars[26 + rule->arg[0] - 65] = r;
	else if (ft_islower(rule->arg[0]))
		lqeng->vars[rule->arg[0] - 97] = r;
	return (ret);
}
