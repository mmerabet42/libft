#include "includes/ft_regex.h"
#include "includes/ft_printf.h"
#include "includes/ft_printf_ext.h"
#include "includes/get_next_line.h"
#include "includes/ft_str.h"
/*
static t_regex_func	g_funcs[] = {
	{"LOL", "?[@alpha]", NULL, 0, 0},
	{"TEST", "?[@digit]", NULL, 0, 0}
};
*/
static void	print_groups(t_list *groups, int tab)
{
	while (groups)
	{
		t_regex_group	*grp = (t_regex_group *)groups->content;
		ft_printf("%?*\tgroup: %d %d %d '%.*s'\n", tab, grp->pos, grp->len, grp->id, grp->len, grp->str);
		print_groups(grp->groups, tab + 1);
		groups = groups->next;
	}
}

static void	print_matches(t_list *matches)
{
	while (matches)
	{
		t_regex_match	*mch = (t_regex_match *)matches->content;
		ft_printf("match: %d %d %d '%.*s'\n", mch->pos, mch->len, mch->id, mch->len, mch->str);
		print_groups(mch->groups, 1);
		matches = matches->next;
	}
}

int main(int argc, char **argv)
{
	(void)argc;

	t_list	*matches = NULL;
	t_list	*groups = NULL;
	int		n;

//	ft_regex(RGX_ADD_MULTI, NULL, NULL, g_funcs, sizeof(g_funcs) / sizeof(t_regex_func));

//	ft_regex(RGX_ADD | RGX_READABLE | RGX_TO, "lool", "?[@alpha]", &nothing, NULL);
	n = ft_regex(RGX_LOAD, "json.rgx", NULL);
	n = ft_regex(RGX_GLOBAL, argv[1], argv[2], &matches);
	ft_printf("Regular expression: '%s'\nString: '%s'\n\n\n", argv[1], argv[2]);

	print_matches(matches);
	ft_print_matches(argv[2], matches);
	
	ft_printf("\n%d match\n", n);

	ft_regex(RGX_FREEGRP, NULL, NULL, &groups);
	ft_regex(RGX_FREE, NULL, NULL, &matches);
	ft_regex(RGX_CLEAN, NULL, NULL);



	ft_printf_free_formats();
	get_next_line(0, NULL);
	get_next_delimstr(0, NULL, NULL);
	return (0);
}
