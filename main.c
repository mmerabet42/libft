#include <stdio.h>
#include <limits.h>
#include <locale.h>
#include <wctype.h>
#include <fcntl.h>
#include <float.h>
#include <math.h>
#include "libft.h"

# define PRINTFT "%.400f\n", 0.0

typedef struct	s_pair
{
	int		key;
	char	value;
	unsigned long long n;
}				t_pair;

void printbtree(t_btree *bt)
{
	ft_printf("L: %s\n", bt->content);
}

void lstprint(t_list *lst)
{
	ft_printf("'%s'\n", lst->content);
}

void pairdel(void *data, size_t data_size)
{
	free(data);
}

int intcmp(const void *a, const void *b, size_t n)
{
	(void)n;
	return (ft_atoi(a) - ft_atoi(b));
}

int main(int argc, char **argv)
{
	t_btree *bt = NULL, *tmp;
	int i = 1;
	while (i < 1000)
	{
		char *str = ft_itoa(i);
		tmp = ft_btree_insertf(bt, ft_btree_create(str, ft_strlen(str) + 1), intcmp);
		if (!bt)
			bt = tmp;
		++i;
	}
	bt = ft_btree_balancef(bt, intcmp);
	//bt = ft_btree_balancef(bt, intcmp);
	ft_btree_dump(bt);
	return (0);
}
