/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:26:52 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/10 18:57:08 by mmerabet         ###   ########.fr       */
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
	if ((flags & (RGX_ADD | RGX_ADD_MULTI | RGX_GET | RGX_LOAD))
			|| (flags & (RGX_FREEGRP | RGX_FREE | RGX_CLEAN)))
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
		ft_print_groups(m->str, m->pos, m->len, m->groups, color);
		ft_printf("%#{lred}%{black}%d%{0}", m->id);
		n = !n;
		i = m->pos + m->len;
		if (!(matches = matches->next))
			ft_printf("%{white}%#{black}%s%{0}", str + i);
	}
	ft_printf("%#{magenta}}%{0}\n");
}

static const char	*g_group_colors[] = {
	"lgreen", "lmagenta", ";238;18;137", ";65;105;225", ";60;179;113",
	";255;165;1", ";52;224;8", ";56;142;142", ";162;59;221", ";244;63;2"
};
static const int	g_gc_len = sizeof(g_group_colors) / sizeof(char *);

void		ft_print_groups(const char *str, int pos, int len, t_list *group, const char *def)
{
	static int		i;
	int				j;
	t_regex_group	*grp;
	int				ipos;
	const char		*color;

	ipos = pos;
	if (i >= g_gc_len)
		i = 0;
	j = i;
	color = (def ? def : g_group_colors[j]);
	if (!group && len != -1)
		ft_printf("%{black}%#{%s}%.*s%{0}", color, len, str);
	while (group && ++i)
	{
		grp = (t_regex_group *)group->content;
		ft_printf("%{black}%#{%s}%.*s%{0}", color, grp->pos - pos, str);
		str += grp->pos - pos + grp->len;
		pos = grp->pos + grp->len;
		ft_print_groups(grp->str, grp->pos, grp->len, grp->groups, NULL);
		if (!(group = group->next))
			ft_printf("%{black}%#{%s}%.*s%{0}", color, len - (pos - ipos), str);
	}
	if (def)
		i = 0;
}
