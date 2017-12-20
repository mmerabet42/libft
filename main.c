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

void printbtree(t_btree *bt, int n);

int main(int argc, char **argv)
{
	t_btree *bt = NULL;
	t_btree *tmp;
	int	i = 2;
	while (i < argc)
	{
		tmp = ft_btree_insert(bt, ft_btree_new(argv[i], ft_strlen(argv[i])));
		if (!bt)
			bt = tmp;
		++i;
	}
	ft_btree_erase(bt, argv[1], ft_strlen(argv[1]));
	printbtree(ft_btree_balance(bt), 0);
	return (0);
	ft_printf("FT_PRINTF : \n'");
	int	ftlen = ft_printf(PRINTFT);
	printf("'\nPRINTF : \n'");
	int	len = printf(PRINTFT);
	printf("'\nmy : %d; his : %d\n", ftlen, len);
	return (0);
}

void printbtree(t_btree *bt, int n)
{
	if (!bt)
	{
		ft_printf("%?*\tEND\n", n);
		return ;
	}
	ft_printf("%?*\t'%ld': '%s'\n%1$?*\tLeft {\n", n, bt->content_size, (char *)bt->content);
	printbtree(bt->left, n + 1);
	ft_printf("%?*\t}\n%1$?*\tRight {\n", n);
	printbtree(bt->right, n + 1);
	ft_printf("%?*\t}\n", n);
}
