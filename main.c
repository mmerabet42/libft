#include "includes/ft_regex.h"
#include "includes/ft_printf.h"

int main(int argc, char **argv)
{
	t_list	*matches = NULL;
	int		n;

	ft_regex(RGX_ADD | RGX_ID, NULL, "BRCKT:?[?[@BRCKT1]|?[@BRCKT2]|?[@BRCKT3]@or]", NULL, -2);
	ft_regex(RGX_ADD, NULL, "BRCKT1:(*[?[@BRCKT]|?![{(){}[]}]@or?])", NULL);
	ft_regex(RGX_ADD, NULL, "BRCKT2:[*[?[@BRCKT]|?![{(){}[]}]@or?]]", NULL);
	ft_regex(RGX_ADD, NULL, "BRCKT3:{*[?[@BRCKT]|?![{(){}[]}]@or?]}", NULL);
	ft_regex(RGX_ADD, NULL, "NCOMMENT:/?[*]*[@=%]?[*]/", NULL);
	ft_regex(RGX_ADD, NULL, "COMMENT:/?[*]*?[*]/", NULL);
	ft_regex(RGX_ADD, NULL, "42HEADER:*[?[76@NCOMMENT]\n@X=11]", NULL);

	n = ft_regex(RGX_GLOBAL, argv[1], argv[2], &matches);
	ft_print_matches(argv[2], matches);

	ft_printf("%d match\n", n);
	ft_regex(RGX_FREE, NULL, NULL, &matches);
	return (0);
}
