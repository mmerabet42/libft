#include "libft.h"
#include <stdio.h>
#include <string.h>

void print_strs(char **arr);

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	print_strs(ft_strsplitstr(argv[1], argv[2]));
	return (0);
}

void print_strs(char **arr)
{
	while (*arr)
		printf("'%s'\n", *arr++);
}
