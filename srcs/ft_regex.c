/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:26:52 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/06 20:11:38 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"
#include "ft_mem.h"

int			regex_pos(t_regex_info *rgxi)
{
	const char	*str;
	int			ret;

	if (rgxi->pos)
	{
		*rgxi->pos = 0;
		str = rgxi->str;
		ret = 0;
		while ((ret = regex_exec(rgxi)) == -1)
		{
			if (!*str)
				return (-1);
			rgxi->str = ++str;
			rgxi->regex = rgxi->rgx_begin;
			rgxi->len = 0;
			++*rgxi->pos;
		}
		return (ret);
	}
	return (regex_exec(rgxi));
}

int			ft_regex(int flags, const char *regex, const char *str, ...)
{
	static t_list	*rules;
	t_regex_info	regex_info;
	int				vars[52];
	va_list			vp;

	va_start(vp, str);
	regex_info.str = str;
	regex_info.regex = regex;
	if ((flags & (RGX_ADD | RGX_GET | RGX_CLEAN | RGX_FREE))
			|| (flags & (RGX_FREEGRP | RGX_LOAD)))
		return (manage_rules(&regex_info, &rules, flags, vp));
	regex_init(&regex_info, regex, str);
	ft_bzero(vars, sizeof(int) * (52));
	regex_info.vars = (int *)vars;
	regex_info.flags = flags;
	regex_info.param = "REGEX";
	regex_info.len_param = 5;
	get_args(&regex_info, vp);
	if (regex_info.matches)
		return (get_matches(&regex_info));
	return (regex_pos(&regex_info));
}

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
		ft_printf("%{white}%#{black}%.*s%{black}%#{%s}%.*s%#{lred}%d%{0}",
				m->pos - i, str + i, color, m->len, m->str, m->id);
		n = !n;
		i = m->pos + m->len;
		if (!(matches = matches->next))
			ft_printf("%{white}%#{black}%s%{0}", str + i);
	}
	ft_printf("%#{magenta}}%{0}\n");
}

/*
static const char	*g_group_colors[] = {
	"lgreen", "lmagenta", ";238;18;137", ";65;105;225", ";60;179;113",
	";255;165;0", ";56;142;142"
};
static const int	g_group_colors_len = sizeof(g_group_colors) / sizeof(char *);
*/
void		ft_print_groups(t_list *matches, int a)
{
	if (a)
	{
		t_list	*group_it = matches;
		while (group_it)
		{
			t_regex_group	*g = (t_regex_group *)group_it->content;
			ft_printf("\tgroup match: '%.*s'\n", g->len, g->str);
			group_it = group_it->next;
		}
		return ;
	}
	t_list	*match_it = matches;
	while (match_it)
	{
		t_regex_match	*m = (t_regex_match *)match_it->content;
		ft_printf("match: '%.*s'\n", m->len, m->str);
		t_list	*group_it = m->groups;
		while (group_it)
		{
			t_regex_group	*g = (t_regex_group *)group_it->content;
			ft_printf("\tgroup match: '%.*s'\n", g->len, g->str);
			group_it = group_it->next;
		}
		match_it = match_it->next;
	}
}
