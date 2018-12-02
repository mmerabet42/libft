/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:33:06 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/27 18:23:10 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexiq.h"
#include "ft_str.h"

static int	loop_return(t_lq_eng *eg, t_lq_eng *t,
		t_lq_rule *r, int ret)
{
	if (r->cond == LQ_MARK)
		return (t->len == -1 ? 0 : eg->len + t->len);
	if ((r->cond == LQ_GREAT && r->i <= r->l)
			|| (r->cond == LQ_EQUAL && r->i < r->l)
			|| (!r->i && ((!r->neg && ret == -1) || (r->neg && ret != -1))))
		return (-1);
	if (t->len == -1 && !*eg->expr && (!*eg->str || (eg->flags & LQ_END)))
		return (eg->len);
	if (t->len == -1 && (!(eg->flags & LQ_END) || (t->expr && *t->expr)))
		return (-1);
	return (t->len == -1 ? -1 : eg->len + t->len);
}

static int	loop_stop(t_lq_eng *lqeng, t_lq_eng *tmp,
		t_lq_rule *r, int ret)
{
	int			lret;
	t_list		*end;

	lqeng->len += ret;
	lqeng->str += ret;
	*tmp = *lqeng;
	if (!r->cond || r->cond == LQ_MARK || r->cond == LQ_LESS
			|| (r->cond == LQ_GREAT && r->i >= r->l))
	{
		if (tmp->groups && (end = ft_lstend(*tmp->groups)))
			tmp->free_groups = &end->next;
		if (*tmp->expr && (lret = lq_exec(tmp)) != -1)
			return (lret);
	}
	if (++r->i == r->l && r->cond == LQ_EQUAL)
		return (0);
	else if (r->cond == LQ_LESS && r->i + 1 >= r->l)
		return (-1);
	return (-2);
}

int			lq_loop(t_lq_eng *lqeng, t_lq_rule *rule)
{
	int				ret;
	int				lret;
	t_lq_eng		tmp;

	lret = -1;
	ret = -1;
	tmp.expr = NULL;
	while (*lqeng->str)
	{
		if ((ret = rule->func->func(lqeng, rule)) == -1 && !rule->neg)
			break ;
		else if (ret != -1 && rule->neg)
			break ;
		ret = (ret == -1 ? 1 : ret);
		if ((lret = loop_stop(lqeng, &tmp, rule, ret)) != -2)
			return (lret);
		lret = -1;
	}
	tmp.len = lret;
	return (loop_return(lqeng, &tmp, rule, ret));
}

static int	lq_once(t_lq_eng *lqeng, t_lq_rule *rule)
{
	int	ret;

	ret = rule->func->func(lqeng, rule);
	if (!rule->neg)
	{
		if (ret == -1 && rule->cond != LQ_MARK)
			return (-1);
		if (*lqeng->str && ret)
		{
			lqeng->str += (ret == -1 ? 0 : ret);
			lqeng->len += (ret == -1 ? 0 : ret);
		}
		else if (!*lqeng->str && ret)
			return (-1);
		return (0);
	}
	else if (ret == -1 && *lqeng->str)
	{
		++lqeng->str;
		++lqeng->len;
		return (0);
	}
	return (rule->cond == LQ_MARK ? 0 : -1);
}

int			lq_start(t_lq_eng *lqeng, t_lq_rule *rule)
{
	t_lq_func	*tmp;

	if (!rule->func)
		return (-1);
	else if (!rule->func->func)
	{
		rule->rule = rule->func->name;
		rule->len_rule = ft_strlen(rule->rule);
		if (!(tmp = lq_get_func("OTHER", 5, NULL)))
			return (-1);
		rule->func->func = tmp->func;
	}
	if (rule->type == '*')
	{
		if (rule->cond == LQ_EQUAL && rule->l <= 0)
			return (0);
		else if (rule->cond == LQ_LESS && rule->l <= 1)
			return (0);
		return (lq_loop(lqeng, rule));
	}
	return (lq_once(lqeng, rule));
}
