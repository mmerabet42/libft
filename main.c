#include "includes/ft_regex.h"
#include "includes/ft_printf.h"
#include "includes/ft_str.h"

int main(int argc, char **argv)
{
	(void)argc;

	t_list	*matches = NULL;
	t_list	*groups = NULL;
	int		n;

	n = ft_regex(RGX_LOAD, "rules.rgx", NULL);
	n = ft_regex(RGX_GLOBAL, argv[1], argv[2], &matches);
	ft_printf("Regular expression: '%s'\nString: '%s'\n\n\n", argv[1], argv[2]);

	ft_print_groups(matches, 0);
	ft_print_matches(argv[2], matches);
	ft_printf("%d match\n", n);

	ft_regex(RGX_FREEGRP, NULL, NULL, &groups);
	ft_regex(RGX_FREE, NULL, NULL, &matches);
	ft_regex(RGX_CLEAN, NULL, NULL);
	return (0);
}
