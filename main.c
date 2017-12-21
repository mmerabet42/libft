#include "ft_printf.h"
#include "get_next_line.h"
#include "handlers.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>
#include <wctype.h>
#include <fcntl.h>
#include <float.h>

# define PRINTFT "%f", -89.23

int	ft_intcmp(const void *a, const void *b, size_t n)
{
	(void)n;
	return (ft_atoi((char *)a) - ft_atoi((char *)b));
}

int main(int argc, char **argv)
{
	t_btree *bt = NULL;
	t_btree *tmp;
	int	i = 1;
	while (i < argc)
	{
		tmp = ft_btree_insertf(bt, ft_btree_create(argv[i], ft_strlen(argv[i])), ft_intcmp);
		if (!bt)
			bt = tmp;
		++i;
	}
	bt = ft_btree_balance(bt);
	ft_btree_dump(bt);
	/*ft_printf("AFTER MOVE :\n");
	bt = ft_btree_splay(bt, argv[1], ft_strlen(argv[1]));
	ft_btree_dump(bt);
	ft_printf("AFTER MOVE :\n");
	bt = ft_btree_splay(bt, argv[2], ft_strlen(argv[2]));
	ft_btree_dump(bt);*/
	return (0);
}
