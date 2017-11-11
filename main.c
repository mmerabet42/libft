#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	
	printf("'%s'\n", ft_revnstr(argv[1], ft_atoi(argv[2])));
	return (0);
}
