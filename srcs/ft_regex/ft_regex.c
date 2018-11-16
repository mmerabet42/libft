/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:26:52 by mmerabet          #+#    #+#             */
/*   Updated: 2018/11/16 20:10:41 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"
#include "ft_mem.h"

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
	if ((flags & (RGX_ADD | RGX_ADD_MULTI | RGX_GET | RGX_IMPORT | RGX_TO))
			|| (flags & (RGX_FREEGRP | RGX_FREE | RGX_CLEAN | RGX_SET))
			|| (flags & (RGX_GETRULE)))
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
