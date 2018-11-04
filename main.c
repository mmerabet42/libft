#include "includes/ft_regex.h"
#include "includes/ft_printf.h"

int main(int argc, char **argv)
{
	(void)argc;

	t_list	*matches = NULL;
	t_list	*groups = NULL;
	int		n;
	int		id = 0;

//	ft_regex(RGX_ADD, "DQUOTE", "\"*[?[\\\"@G]|?![\"]@or?]\"", NULL);
	ft_regex(RGX_ADD | RGX_ID, "BRACKET", "?[?[@BRACKET0]|?[@BRACKET1]|?[@BRACKET2]@or]", NULL, -2);
	ft_regex(RGX_ADD, "BRACKET0", "?[(*[?[@BRACKET]|?![{(){}[]}]@or?])@G]", NULL);
	ft_regex(RGX_ADD, "BRACKET1", "?[{[*[?[@BRACKET]|?![{(){}[]}]@or?]]@G}]", NULL);
	ft_regex(RGX_ADD, "BRACKET2", "?[\\{*[?[@BRACKET]|?![{(){}[]}]@or?]}@G]", NULL);
	ft_regex(RGX_ADD, "A0_OPEN", "?[?*]?[!@?][", NULL);
	ft_regex(RGX_ADD, "A0_CLOSE", "]", NULL);
	ft_regex(RGX_ADD | RGX_READABLE, "A0",
	R"(?[?[@A0_OPEN]
	*[
		?[@A0]
	|
		?[
			?![@A0_OPEN]
		&
			?![@A0_CLOSE]
		@and]
	@or?]
	?[@A0_CLOSE]@G])", NULL);

	n = ft_regex(RGX_GLOBAL, argv[1], argv[2], &matches);
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
	ft_printf("Regular expression: '%s'\nString: '%s'\n", argv[1], argv[2]);
	ft_print_matches(argv[2], matches);
	ft_printf("%d %d match\n", n, id);

	ft_regex(RGX_FREEGRP, NULL, NULL, &groups);
	ft_regex(RGX_FREE, NULL, NULL, &matches);
	ft_regex(RGX_CLEAN, NULL, NULL);
	return (0);
}
