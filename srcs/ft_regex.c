/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:26:52 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/12 13:05:23 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"
#include "ft_mem.h"
#include "ft_math.h"

static void	get_args(t_regex_info *rgxi, va_list vp)
{
	if (rgxi->flags & RGX_RGXN)
		rgxi->rgxn = (int)va_arg(vp, int);
	if (rgxi->flags & RGX_STRN)
		rgxi->strn = (int)va_arg(vp, int);
	if (rgxi->flags & (RGX_GLOBAL | RGX_UGLOBAL))
		rgxi->matches = (t_list **)va_arg(vp, t_list **);
	else
	{
		if (rgxi->flags & RGX_POS)
			rgxi->pos = (int *)va_arg(vp, int *);
		if (rgxi->flags & RGX_ID)
			rgxi->id = (int *)va_arg(vp, int *);
		if (rgxi->flags & RGX_GROUP)
			rgxi->groups = (t_list **)va_arg(vp, t_list **);
		rgxi->groups_head = rgxi->groups;
		rgxi->free_groups = rgxi->groups;
	}
	if (rgxi->flags & RGX_DATA)
		rgxi->data = (int *)va_arg(vp, void *);
	if (rgxi->flags & RGX_VAR)
		rgxi->vars = (int *)va_arg(vp, int *);
	va_end(vp);
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
	if ((flags & (RGX_ADD | RGX_ADD_MULTI | RGX_GET | RGX_LOAD | RGX_TO))
			|| (flags & (RGX_FREEGRP | RGX_FREE | RGX_CLEAN | RGX_SET)))
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
	"lgreen", "lmagenta", ";238;18;137", ";65;105;225", ";60;179;113",
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
