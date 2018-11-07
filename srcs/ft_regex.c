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
#include "ft_math.h"

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
		ft_printf("%#{black}%{white}%.*s", m->pos - i, str + i);
		ft_print_groups2(m->str, m->pos, m->len, m->groups, color);
		ft_printf("%#{lred}%{black}%d%{0}", m->id);
		n = !n;
		i = m->pos + m->len;
		if (!(matches = matches->next))
			ft_printf("%{white}%#{black}%s%{0}", str + i);
	}
	ft_printf("%#{magenta}}%{0}\n");
}

void		ft_print_groups(t_list *matches, int a)
{
	if (a)
	{
		t_list	*group_it = matches;
		while (group_it)
		{
			t_regex_group	*g = (t_regex_group *)group_it->content;
			ft_printf("\tgroup match: %d %d '%.*s'\n", g->len, g->pos, g->len, g->str);
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
			ft_printf("\tgroup match: %d %d '%.*s'\n", g->len, g->pos, g->len, g->str);
			group_it = group_it->next;
		}
		match_it = match_it->next;
	}
}

static const char	*g_group_colors[] = {
	"lgreen", "lmagenta", ";238;18;137", ";65;105;225", ";60;179;113",
	";255;165;0", ";52;224;8", ";56;142;142", ";162;59;221", ";244;63;2"
};
static const int	g_group_colors_len = sizeof(g_group_colors) / sizeof(char *);

static void	ft_print_group(t_list **group, int *i)
{
	int				j;
	const char		*str;
	int				pos;
	t_regex_group	*cur;
	t_regex_group	*next;

	j = (*i)++;
	if (*i >= g_group_colors_len)
		*i = 0;
	cur = (t_regex_group *)(*group)->content;
	next = NULL;
	if ((*group)->next)
		next = (t_regex_group *)(*group)->next->content;
	if (!next || cur->pos + cur->len <= next->pos)
	{
		*group = (*group)->next;
		ft_printf("%{black}%#{%s}%.*s%{0}", g_group_colors[j], cur->len, cur->str);
	}
	else
	{
		str = cur->str;
		pos = cur->pos;
		*group = (*group)->next;
		while (next && cur->pos + cur->len > next->pos)
		{
			ft_printf("%{black}%#{%s}%.*s%{0}", g_group_colors[j], next->pos - pos, str);
			pos = next->pos + next->len;
			str = cur->str_begin + pos;
			if (*group)
				ft_print_group(group, i);
			next = NULL;
			if (*group)
				next = (t_regex_group *)(*group)->content;
			if (!next || next->pos >= cur->pos + cur->len)
				ft_printf("%{black}%#{%s}%.*s%{0}", g_group_colors[j], cur->len - (pos - cur->pos), str);
		}
	}
}

void	ft_print_groups2(const char *match, int pos, int len, t_list *groups, const char *def)
{
	t_regex_group	*cur;
	int				i;
	int				init_pos;

	if (!groups)
		ft_printf("%{black}%#{%s}%.*s%{0}", def, len, match);
	i = 0;
	init_pos = pos;
	while (groups)
	{
		cur = (t_regex_group *)groups->content;
		ft_printf("%{black}%#{%s}%.*s%{0}", def, cur->pos - pos, match);
		pos = cur->pos + cur->len;
		match = cur->str_begin + pos;
		ft_print_group(&groups, &i);
		if (!groups && *match)
			ft_printf("%{black}%#{%s}%.*s%{0}", def, len - (pos - init_pos), match);
	}
}
