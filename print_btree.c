#include "libft.h"
#include <stdio.h>

void print_btree(t_btree *bt, int n)
{
	if (!bt)
	{
		ft_putnchar('\t', n);
		ft_putendl("END");
		return ;
	}
	ft_putnchar('\t', n);
	printf("%lu '%d': (%d)\n", bt->content_size, *(int *)bt->content,(bt->parent?*(int*)bt->parent->content:-1));
	ft_putnchar('\t', n);
	printf("Left {\n");
	print_btree(bt->left, n + 1);
	ft_putnchar('\t', n);
	printf("}\n");
	ft_putnchar('\t', n);
	printf("Right {\n");
	print_btree(bt->right, n + 1);
	ft_putnchar('\t', n);
	printf("}\n");
}
