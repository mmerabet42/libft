#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

void print_strs(char **arr);

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	printf("'%s'", ft_itoa(INT_MIN));
	return (0);
}

void print_strs(char **arr)
{
	while (*arr)
		printf("'%s'\n", *arr++);
}
