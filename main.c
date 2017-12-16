#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>
#include <wctype.h>
#include <fcntl.h>

#define PRINTFT "%5$d", 1, 2, 3, 4, 5, 6, 7, 8, 9 

typedef struct s_test
{
	unsigned long long a;
	unsigned long long b;
	unsigned long long c;
	unsigned long long d;
} t_test;

int main(int argc, char **argv)
{
	t_test a;
	//ft_printf("%d '%5$d'", 1, 2, 3, 4, 5, 6, 7, 8, 9);
	//printf("'%d' '%d' '%*5$d' '%d'", 1, 2, 3, 4, 5, 6, 7, 8, 9);

	//printf("%5$d %d %d %1$d %d", 78, 3, "Hello world", 7, 5, 99, 1, 89, 4);

	//int	i = -1;
	//while (i += 2 < argc)
	//	ft_printf("%{%s}", argv[i], argv[i + 1]);
	//ft_printf("Hello world%{eoc}");
	ft_printf("FT_PRINTF: \n'");
	int ftlen = ft_printf(PRINTFT);
	printf("'\nPRINTF: \n'");
	int len = printf(PRINTFT);
	printf("'\nmy : %d - his : %d\n", ftlen, len);
	return (0);
}
