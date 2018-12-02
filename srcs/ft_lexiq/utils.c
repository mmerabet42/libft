/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:57:21 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/27 18:23:56 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexiq.h"
#include "ft_mem.h"
#include "ft_types.h"

void	lq_init(t_lq_eng *lqeng, const char *expr , const char *str)
{
	ft_bzero(lqeng, sizeof(t_lq_eng));
	lqeng->str_begin = str;
	lqeng->expr_begin = expr;
	lqeng->str = str;
	lqeng->expr = expr;
	lqeng->exprn = -1;
	lqeng->strn = -1;
}

int		lq_variable(t_lq_eng *lqeng, const char *s)
{
	if (ft_isdigit(*s))
		return (ft_atoi(s));
	else if (ft_islower(*s))
		return (lqeng->vars[*s - 97]);
	else if (ft_isupper(*s))
		return (lqeng->vars[26 + *s - 65]);
	else if (*s == '%' && lqeng->param)
		return (ft_atoi(lqeng->param));
	return (0);
}

void	lq_free_rule(void *p, size_t s)
{
	if (!s)
	{
		free((void *)((t_lq_func *)p)->name);
		free((void *)((t_lq_func *)p)->expr);
	}
	free(p);
}

void	lq_free_match(void *p, size_t s)
{
	if (!p)
		return ;
	(void)s;
	ft_lstdel(&((struct s_lexiq_match *)p)->groups, lq_free_match);
	free(p);
}
