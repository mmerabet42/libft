#include "ft_printf.h"
#include "get_next_line.h"
#include "handlers.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>
#include <wctype.h>
#include <fcntl.h>
#include <float.h>
#include <math.h>

# define PRINTFT "%.400f\n", 0.0

int	ft_intcmp(const void *a, const void *b, size_t n)
{
	(void)n;
	return (*(int *)a - *(int *)b);
}

int	ft_intcmpstr(const void *a, const void *b, size_t n)
{
	(void)n;
	return (ft_atoi((char *)a) - ft_atoi((char *)b));
}

void printbtree(t_btree *bt)
{
	ft_printf("'%d'", *(int *)bt->content);
}

void lstprint(t_list *lst)
{
	ft_printf("'%s' : '%s'\n", lst->content, (lst->parent ? lst->parent->content : NULL));
}

int main(int argc, char **argv)
{
	t_btree *bt = NULL;
	t_btree *tmp;
	int	i = 1;
	while (i < argc)
	{
		tmp = ft_btree_insertf(bt, ft_btree_create(argv[i], ft_strlen(argv[i]) + 1), ft_intcmpstr);
		if (!bt)
			bt = tmp;
	//	ft_printf("FOR : %s\n", argv[i]);
	//	ft_btree_dump(bt);
	//	ft_printf("%?3\n");
		bt = ft_btree_balancef(bt, ft_intcmpstr);
		++i;
	}
	ft_btree_dump(bt);
//	ft_printf("%?3\n");
//	bt = ft_btree_balancef(bt, ft_intcmp);
//	ft_btree_dump(bt);
	//ft_lstiter(ft_btree_tolist(bt), lstprint);
	//ft_printf("AFTER BALANCING : \n");
	//1ft_btree_dump(bt);
	//ft_printf("DEPTH : %ld; SIZE : %ld\n", ft_btree_depth(bt), ft_btree_size(bt));
	/*ft_printf("AFTER MOVE :\n");
	bt = ft_btree_splayf(bt, argv[1], ft_strlen(argv[1]), ft_intcmp);
	ft_btree_dump(bt);
	ft_printf("AFTER MOVE :\n");
	bt = ft_btree_splayf(bt, argv[2], ft_strlen(argv[2]), ft_intcmp);
	ft_btree_dump(bt);*/
	return (0);
}
