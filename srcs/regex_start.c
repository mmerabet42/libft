/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:33:06 by mmerabet          #+#    #+#             */
/*   Updated: 2018/10/27 19:37:07 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"
#include "ft_str.h"

static int	loop_return(t_regex_info *rg, t_regex_info *t,
		t_regex_rule *r, int ret)
{
	if (r->cond == RGX_MARK)
		return (t->len == -1 ? 0 : rg->len + t->len);
	if ((r->cond == RGX_GREAT && r->i <= r->l)
			|| (r->cond == RGX_EQUAL && r->i < r->l)
			|| (!r->i && ((!r->neg && ret == -1) || (r->neg && ret != -1))))
		return (-1);
	if (t->len == -1 && !*rg->regex && (!*rg->str || (rg->flags & RGX_END)))
		return (rg->len);
	if (t->len == -1 && (!(rg->flags & RGX_END) || (t->regex && *t->regex)))
		return (-1);
	return (t->len == -1 ? -1 : rg->len + t->len);
}

static int	loop_stop(t_regex_info *rgxi, t_regex_info *tmp,
		t_regex_rule *r, int ret)
{
	int			lret;
	t_list		*end;

	rgxi->len += ret;
	rgxi->str += ret;
	*tmp = *rgxi;
	if (!r->cond || r->cond == RGX_MARK || r->cond == RGX_LESS
			|| (r->cond == RGX_GREAT && r->i >= r->l))
	{
		if (tmp->groups && (end = ft_lstend(*tmp->groups)))
			tmp->free_groups = &end->next;
		if (*tmp->regex && (lret = regex_exec(tmp)) != -1)
		{
//			if ((tmp->flags & RGX_END) && (nret = regex_loop(tmp, r)) != -1)
//				return (nret - lret);
			return (lret);
		}
	}
	if (++r->i == r->l && r->cond == RGX_EQUAL)
		return (0);
	else if (r->cond == RGX_LESS && r->i + 1 >= r->l)
		return (-1);
	return (-2);
}

int			regex_loop(t_regex_info *rgxi, t_regex_rule *rule)
{
	int				ret;
	int				lret;
	t_regex_info	tmp;

	lret = -1;
	ret = -1;
	tmp.regex = NULL;
	while (*rgxi->str)
	{
		if ((ret = rule->func->func(rgxi, rule)) == -1 && !rule->neg)
			break ;
		else if (ret != -1 && rule->neg)
			break ;
		ret = (ret == -1 ? 1 : ret);
		if ((lret = loop_stop(rgxi, &tmp, rule, ret)) != -2)
			return (lret);
		lret = -1;
	}
	tmp.len = lret;
	return (loop_return(rgxi, &tmp, rule, ret));
}

static int	regex_once(t_regex_info *rgxi, t_regex_rule *rule)
{
	int	ret;

	ret = rule->func->func(rgxi, rule);
	if (!rule->neg)
	{
		if (ret == -1 && rule->cond != RGX_MARK)
			return (-1);
		if (*rgxi->str && ret)
		{
			rgxi->str += (ret == -1 ? 0 : ret);
			rgxi->len += (ret == -1 ? 0 : ret);
		}
		else if (!*rgxi->str && ret)
			return (-1);
		return (0);
	}
	else if (ret == -1 && *rgxi->str)
	{
		++rgxi->str;
		++rgxi->len;
		return (0);
	}
	return (rule->cond == RGX_MARK ? 0 : -1);
}

int			regex_start(t_regex_info *rgxi, t_regex_rule *rule)
{
	t_regex_func	*tmp;

	if (!rule->func)
		return (-1);
	else if (!rule->func->func)
	{
		rule->rule = rule->func->name;
		rule->len_rule = ft_strlen(rule->rule);
		if (!(tmp = get_regex_func("OTHER", 5, NULL)))
			return (-1);
		rule->func->func = tmp->func;
	}
	if (rule->type == '*')
	{
		if (rule->cond == RGX_EQUAL && rule->l <= 0)
			return (0);
		else if (rule->cond == RGX_LESS && rule->l <= 1)
			return (0);
		return (regex_loop(rgxi, rule));
	}
	return (regex_once(rgxi, rule));
}
