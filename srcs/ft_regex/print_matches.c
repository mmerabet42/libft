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

#include "ft_regex.h"
#include "ft_printf.h"

void		ft_print_matches(const char *str, t_list *matches)
{
	int				i;
	int				n;
	const char		*color;
	t_regex_match	*m;

	if (!matches)
		return ;
	i = 0;
	n = 0;
	ft_printf("%#{magenta}{%{0}");
	while (matches)
	{
		m = (t_regex_match *)matches->content;
		color = (n ? "lcyan" : "lblue");
		if (m->id == -1)
			color = "white";
		ft_printf("%#{black}%{white}%.*s%{0}", m->pos - i, str + i);
		ft_print_groups(m, m->groups, color);
		ft_printf("%#{lred}%{black}%d%{0}", m->id);
		n = !n;
		i = m->pos + m->len;
		if (!(matches = matches->next))
			ft_printf("%{white}%#{black}%s%{0}", str + i);
	}
	ft_printf("%#{magenta}}%{0}\n");
}

static const char	*g_group_colors[] = {
	"lgreen", ";65;105;225", "magenta", ";238;18;137", ";60;179;113",
	";255;165;1", ";52;224;8", ";56;142;142", ";162;59;221", ";244;63;2"
};
static const int	g_gc_len = sizeof(g_group_colors) / sizeof(char *);

void		ft_print_groups(struct s_regex_match *m, t_list *group,
					const char *def)
{
	static int		i;
	int				j;
	t_regex_group	*grp;
	int				pos;
	const char		*color;

	if ((pos = m->pos) != -1 && i >= g_gc_len)
		i = 0;
	j = i;
	color = (def ? def : g_group_colors[j]);
	if (!group && m->len != -1)
		ft_printf("%{black}%#{%s}%.*s%{0}", color, m->len, m->str_begin + pos);
	while (group && ++i)
	{
		grp = (t_regex_group *)group->content;
		ft_printf("%{black}%#{%s}%.*s%{0}", color, grp->pos - pos,
				m->str_begin + pos);
		pos = grp->pos + grp->len;
		ft_print_groups(grp, grp->groups, NULL);
		if (!(group = group->next))
			ft_printf("%{black}%#{%s}%.*s%{0}", color, m->len - (pos - m->pos),
					m->str_begin + pos);
	}
	i = (def ? 0 : i);
}

void		ft_print_matches_tree(t_list *matches, int tab)
{
	t_regex_match	*mch;

	while (matches)
	{
		mch = (t_regex_match *)matches->content;
		ft_printf("%?*\t%#{white}%{black}<<<<%{0} ", tab);
		ft_printf("pos(%d) len(%d) ", mch->pos, mch->len);
		ft_printf("rule(%s) '%.*s'\n\n", mch->id_str, mch->len, mch->str);
		ft_print_matches_tree(mch->groups, tab + 1);
		matches = matches->next;
	}
}
