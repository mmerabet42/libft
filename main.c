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

int main(int argc, char **argv)
{
	(void)argc;

	t_list	*matches = NULL;
	int		n;

	ft_regex(RGX_IMPORT, argv[1], NULL);
	n = ft_regex(RGX_GLOBAL, "?[@MAIN]", argv[2], &matches);
//	ft_printf("Regular expression: '%s'\nString: '%s'\n\n\n", argv[1], argv[2]);

	ft_print_matches_tree(matches, 0);
	ft_print_matches(argv[2], matches);
	
	ft_printf("\n%d match(es)\n", n);
	ft_regex(RGX_FREE, NULL, NULL, &matches);
	ft_regex(RGX_CLEAN, NULL, NULL);



	ft_printf_free_formats();
	get_next_line(0, NULL);
	get_next_delimstr(0, NULL, NULL);
	return (0);
}
