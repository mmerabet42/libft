#include "ft_printf.h"
#include "get_next_line.h"
#include "handlers.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>
#include <wctype.h>
#include <fcntl.h>

#define PRINTFT "%l{%d;%d;%d}Hello%{0}", ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3])

int main(int argc, char **argv)
{
	ft_printf("FT_PRINTF : %s\n'", "");
	int	ftlen = ft_printf(PRINTFT);
	printf("'\nPRINTF : \n'");
	int	len = printf(PRINTFT);
	printf("'\nmy : %d; his : %d\n", ftlen, len);
	
	ft_printf_free_formats();
	return (0);
}
