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
	t_pair *p = (t_pair *)bt->content;
	ft_printf("{key:'%d'; value:'%c'}", p->key, p->value);
}

void lstprint(t_list *lst)
{
	ft_printf("'%s'\n", lst->content);
}

void pairdel(void *data, size_t data_size)
{
	free(data);
}

void callback_test0(t_event *event, void *data)
{
	ft_printf("L: %d\n", *(int *)data);
}

void callback_test1(t_event *event, void *data)
{
	ft_printf("U: %d\n", *(int *)data);
}

int main(int argc, char **argv)
{
	t_btree *bt = NULL, *tmp;
	int i = 2;
	while (i < argc)
	{
		tmp = ft_btree_insert(bt, ft_btree_new(argv[i], ft_strlen(argv[i]) + 1));
		if (!bt)
			bt = tmp;
		++i;
	}
	ft_printf("ERASING %d TIME\n", ft_btree_count(bt, argv[1], ft_strlen(argv[1]) + 1));
	t_btree *erased = ft_btree_erase_all(&bt, argv[1], ft_strlen(argv[1]) + 1);
	ft_btree_dump(bt);
	ft_printf("ERASED :\n");
	ft_btree_dump(erased);
	return (0);
}
