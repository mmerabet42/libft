/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexiq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:26:52 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/29 20:27:08 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexiq.h"
#include "ft_mem.h"

static void	get_args(t_lq_eng *lqeng, va_list vp)
{
	if (lqeng->flags & LQ_EXPRN)
		lqeng->exprn = (int)va_arg(vp, int);
	if (lqeng->flags & LQ_STRN)
		lqeng->strn = (int)va_arg(vp, int);
	if (lqeng->flags & (LQ_GLOBAL | LQ_UGLOBAL))
		lqeng->matches = (t_list **)va_arg(vp, t_lq_list **);
	else
	{
		if (lqeng->flags & LQ_POS)
			lqeng->pos = (int *)va_arg(vp, int *);
		if (lqeng->flags & (LQ_ID | LQ_IDSTR))
			lqeng->id = (int *)va_arg(vp, int *);
		if (lqeng->flags & LQ_IDSTR)
			lqeng->id_str = (const char **)va_arg(vp, const char **);
		if (lqeng->flags & LQ_GROUP)
			lqeng->groups = (t_list **)va_arg(vp, t_lq_list **);
		lqeng->groups_head = lqeng->groups;
		lqeng->free_groups = lqeng->groups;
	}
	if (lqeng->flags & LQ_DATA)
		lqeng->data = (int *)va_arg(vp, void *);
	if (lqeng->flags & LQ_VAR)
		lqeng->vars = (int *)va_arg(vp, int *);
	va_end(vp);
}

int			ft_lexiq(int flags, const char *expression, const char *str, ...)
{
	static t_list	*rules;
	t_lq_eng		lqeng;
	int				vars[52];
	va_list			vp;

	va_start(vp, str);
	lqeng.str = str;
	lqeng.expr = expression;
	if ((flags & (LQ_ADD | LQ_ADD_MULTI | LQ_GET | LQ_IMPORT | LQ_TO))
			|| (flags & (LQ_FREEGRP | LQ_FREE | LQ_CLEAN | LQ_SET))
			|| (flags & (LQ_GETRULE)))
		return (lq_manage_rules(&lqeng, &rules, flags, vp));
	lq_init(&lqeng, expression, str);
	ft_bzero(vars, sizeof(int) * (52));
	lqeng.vars = (int *)vars;
	lqeng.flags = flags;
	lqeng.param = "LEXIQ";
	lqeng.len_param = 5;
	get_args(&lqeng, vp);
	if (lqeng.matches)
		return (lq_get_matches(&lqeng));
	return (lq_pos(&lqeng));
}
