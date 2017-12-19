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

void printbtree(t_btree *bt, int n)

int main(int argc, char **argv)
{
	t_btree *bt = NULL;
	t_btree *tmp;
	int	i = 1;
	while (i < argc)
	{
		tmp = ft_btree_insert(bt, ft_btree_new(argv[1], ft_strlen(argv[1])));
		if (!bt)
			bt = tmp;
		++i;
	}

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
	
}
