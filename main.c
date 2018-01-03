#include <stdio.h>
#include <limits.h>
#include <locale.h>
#include <wctype.h>
#include <fcntl.h>
#include <float.h>
#include <math.h>
#include "libft.h"


void	callm1(t_pevent *event, void *data)
{
	ft_printf("%d\n", *(int *)data);
}

void	call0(t_pevent *event, void *data)
{
	*(int *)data += 2;
	ft_printf("%d\n", *(int *)data);
}

void	call1(t_pevent *event, void *data)
{
	ft_printf("%d\n", *(int *)data);
}

void	call2(t_pevent *event, void *data)
{
	ft_printf("%d\n", *(int *)data);
}

void	call3(t_pevent *event, void *data)
{
	ft_printf("%d\n", *(int *)data);
}

void btiter(t_list *bt)
{
	ft_printf("%s\n", bt->content);
}

int cmpint(const void *a, const void *b, size_t n)
{
	return (ft_atoi(a) - ft_atoi(b));
}

int main(int argc, char **argv)
{
	t_btree *bt = NULL, *tmp;
	int	i = 1;
	while (i < argc)
	{
		tmp = ft_btree_insert(bt, ft_btree_create(argv[i], ft_strlen(argv[i]) + 1));
		if (!bt)
			bt = tmp;
		++i;
	}
	ft_btree_dump(bt);
	ft_printf("BREADTH FIRST\n");
	ft_lstiter(ft_btree_tolist(bt), btiter);
	return (0);
	int data = 0;
	t_pevent *pevent = ft_pevent_new();
	ft_pevent_addp(pevent, call2, 2);
	ft_pevent_addp(pevent, call0, 1);
	ft_pevent_addp(pevent, call3, 3);
	ft_pevent_addp(pevent, call1, 1);
	ft_pevent_addp(pevent, call0, 1);
	ft_pevent_addp(pevent, call1, -500);
	ft_pevent_trigger(pevent, &data);
	ft_pevent_del(&pevent);
	return (0);
}
