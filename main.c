#include "includes/ft_regex.h"
#include "includes/ft_printf.h"

int main(int argc, char **argv)
{
	(void)argc;

	t_list	*matches = NULL;
	t_list	*groups = NULL;
	int		n;
	int		id = 0;

	ft_regex(RGX_ADD, "DQUOTE", "\"*[?[\\\"@G]|?![\"]@or?]\"", NULL);
	ft_regex(RGX_ADD | RGX_ID, "BRACKET", "?[?[@BRACKET0]|?[@BRACKET1]|?[@BRACKET2]@or]", NULL, -2);
	ft_regex(RGX_ADD, "BRACKET0", "?[(*[?[@BRACKET]|?![{(){}[]}]@or?])@G]", NULL);
	ft_regex(RGX_ADD, "BRACKET1", "?[{[*[?[@BRACKET]|?![{(){}[]}]@or?]]@G}]", NULL);
	ft_regex(RGX_ADD, "BRACKET2", "?[\\{*[?[@BRACKET]|?![{(){}[]}]@or?]}@G]", NULL);

	n = ft_regex(RGX_GLOBAL, argv[1], argv[2], &matches);

/*	t_list	*it = groups;
	while (it)
	{
		t_regex_group *grp = (t_regex_group *)it->content;
		ft_printf("group: '%.*s' %d %d %d\n", grp->len, grp->str, grp->pos, grp->len, grp->id);
		it = it->next;
	}*/
	ft_printf("Regular expression: '%s'\nString: '%s'\n", argv[1], argv[2]);
	ft_print_matches(argv[2], matches);
	ft_printf("%d match\n", n, id);
	
	ft_regex(RGX_FREEGRP, NULL, NULL, &groups);
	ft_regex(RGX_FREE, NULL, NULL, &matches);
	ft_regex(RGX_CLEAN, NULL, NULL);
	return (0);
}
