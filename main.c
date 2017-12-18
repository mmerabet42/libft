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
	ft_printf("%l{%s;%s;%s}Hello%{0}", argv[1], argv[2], argv[3]);
	return (0);
	char	*line;
	int		len;
	int		fd = open(argv[1], O_RDWR);
	int		lnb = 0;
	while ((len = get_next_line(fd, &line)) != -2)
	{
		ft_printf("%-10d|%.*r\n", ++lnb, len, line);
	}
	//ft_printf("%-10d|%.*r\n", len, len, line);
	/*ft_printf("FT_PRINTF : %s\n'", "");
	int	ftlen = ft_printf(PRINTFT);
	printf("'\nPRINTF : \n'");
	int	len = printf(PRINTFT);
	printf("'\nmy : %d; his : %d\n", ftlen, len);*/

	ft_printf_free_formats();
	return (0);
}
