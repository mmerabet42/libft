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
	t_pair *p = (t_pair *)lst->content;
	ft_printf("{key:'%d'; value:'%c'}\n", p->key, p->value);
}

void pairdel(void *data, size_t data_size)
{
	free(data);
}

int main(int argc, char **argv)
{
	void *ptr = NULL;
	int l = 78;
	char c = 'P';
	unsigned long long v = "Hello world";
	ptr = ft_memjoin(ptr, 0, &l, sizeof(int));
	ptr = ft_memjoin(ptr, sizeof(int), &c, sizeof(char));
	ptr = ft_memjoin(ptr, sizeof(int) + sizeof(int), &v, sizeof(unsigned long long));
	t_pair *p = (t_pair *)ptr;
	ft_printf("%d %c '%p'\n", p->key, p->value, p->n);
	printf("%d %c '%p'\n", p->key, p->value, p->n);
	return (0);
	t_btree *bt = NULL;
	t_btree *tmp;
	t_list	*lst;
	t_pair pair;
	int	i = 0;
	while (i < 100)
	{
		pair.key = i;
		pair.value = 0;
		tmp = ft_btree_insertm(bt, ft_btree_new(&pair, sizeof(t_pair)), 0, sizeof(int));
		if (!bt)
			bt = tmp;
		++i;
	}
	bt = ft_btree_balancem(bt, 0, sizeof(int));
	ft_btree_dumpf(bt, printbtree);
	ft_lstiter(ft_btree_tolist(bt), lstprint);
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
