/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matches.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 20:09:21 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/27 17:29:03 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexiq.h"
#include "ft_printf.h"

static const char	*g_group_colors[] = {
	"lgreen", ";65;105;225", "magenta", ";238;18;137", ";60;179;113",
	";255;165;1", ";52;224;8", ";56;142;142", ";162;59;221", ";244;63;2"
};
static const int	g_gc_len = sizeof(g_group_colors) / sizeof(char *);
/*
static void inner_print_matches(const char *s, int len, t_lq_list *matches)
{
	static int i = 0;
	int current_pos;
	t_lq_match *mch;

	current_pos = 0;
	while (matches)
	{
		mch = matches->match;
		if (mch->str > s)
			ft_printf("%.*s", (int)(mch->str - s), s + current_pos);
		current_pos = mch->pos + mch->len;
		inner_print_matches(mch->str, mch->len, mch->groups);
		if (current_pos < len)
			ft_printf("%.*s")
	}
}

void ft_print_matches(t_lq_list *matches)
{
	inner_print_matches(matches->match->str_begin, ft_strlen(matches->match->str_begin), matches);
}
*/

static void	ft_print_groups(struct s_lq_match *m, t_lq_list *group,
					const char *def)
{
	static int		i;
	int				j;
	t_lq_group		*grp;
	int				pos;
	const char		*color;

	if ((pos = m->pos) != -1 && i >= g_gc_len)
		i = 0;
	j = i;
	color = (def ? def : g_group_colors[j]);
	if (!group && m->len != -1)
		ft_printf("%#{black}%{%s}%.*s%{0}", color, m->len, m->str_begin + pos);
	while (group && ++i)
	{
		grp = group->match;
		ft_printf("%#{black}%{%s}%.*s%{0}", color, grp->pos - pos,
				m->str_begin + pos);
		pos = grp->pos + grp->len;
		ft_print_groups(grp, grp->groups, NULL);
		if (!(group = group->next))
			ft_printf("%#{black}%{%s}%.*s%{0}", color, m->len - (pos - m->pos),
					m->str_begin + pos);
	}
	i = (def ? 0 : i);
}

void		ft_print_matches(const char *str, t_lq_list *matches)
{
	int				i;
	int				n;
	const char		*color;
	t_lq_match		*m;

	if (!matches)
		return ;
	i = 0;
	n = 0;
	ft_printf("%#{magenta}{%{0}");
	while (matches && (m = matches->match))
	{
		color = (n ? "lcyan" : "lblue");
		ft_printf("%#{black}%{white}%.*s%{0}", m->pos - i, str + i);
		ft_print_groups(m, m->groups, color);
		n = !n;
		i = m->pos + m->len;
		if (!(matches = matches->next))
			ft_printf("%{white}%#{black}%s%{0}", str + i);
	}
	ft_printf("%#{magenta}}%{0}\n");
}

void		ft_print_matches_tree(t_lq_list *matches, int tab)
{
	t_lq_match	*mch;

	while (matches)
	{
		mch = matches->match;
		ft_printf("%?*\t%#{white}%{black}<<<<%{0} ", tab);
		ft_printf("pos(%d) len(%d) name(%s) rule(%s) ", mch->pos, mch->len, mch->name, mch->rule_name);
		ft_printf("'%.*s'\n\n", mch->len, mch->str);
		ft_print_matches_tree(mch->groups, tab + 1);
		matches = matches->next;
	}
}
