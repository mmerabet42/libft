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

int main(int argc, char **argv)
{
	t_btree *bt = NULL;
	t_btree *tmp;
	int	i = 2;
	while (i < argc)
	{
		tmp = ft_btree_insert(bt, ft_btree_create(argv[i], ft_strlen(argv[i])));
		if (!bt)
			bt = tmp;
		++i;
	}
	ft_btree_dump(bt);
	tmp = ft_btree_search(bt, argv[1], ft_strlen(argv[1]));
	ft_printf("BFORE : '%s' is on %s\n", tmp->content, ft_btree_pos(bt, tmp) == -1 ? "left" : "right");
	bt = ft_btree_balance(bt);
	ft_btree_dump(bt);
	tmp = ft_btree_search(bt, argv[1], ft_strlen(argv[1]));
	ft_printf("BFORE : '%s' is on %s\n", tmp->content, ft_btree_pos(bt, tmp) == -1 ? "left" : "right");
	return (0);
}
