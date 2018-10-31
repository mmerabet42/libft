#include "includes/ft_regex.h"
#include "includes/ft_printf.h"

int main(int argc, char **argv)
{
	(void)argc;

	t_list	*matches = NULL;
	t_list	*groups = NULL;
	int		n;
	int		id = 0;

	ft_regex(RGX_ADD, "DQUOTE", "\"*[\\\"|?![\"]@or?]\"", NULL);
	
	n = ft_regex(RGX_GROUP | RGX_ID, argv[1], argv[2], &id, &groups, &matches);

	t_list	*it = groups;
	while (it)
	{
		t_regex_group *grp = (t_regex_group *)it->content;
		ft_printf("group: '%.*s' %d %d %d\n", grp->len, grp->str, grp->pos, grp->len, grp->id);
		it = it->next;
	}
	ft_printf("%d %d match\n", n, id);
	
	ft_regex(RGX_FREEGRP, NULL, NULL, &groups);
	ft_regex(RGX_FREE, NULL, NULL, &matches);
	return (0);
}
