#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/lexiq.h"

int func_ex(void *arg, t_lq_eng *eng)
{
	printf("state: '%s'\n", eng->str);
	return 0;
}

int main()
{
	t_lq_node *bracket =
		lq_node("g", NULL, lq_quant(1, 1), NULL, NULL);

	t_lq_node *round_bracket =
		lq_node("s", "(", lq_quant(1, 1), NULL,
		lq_node("r",
				lq_node("!?", "()[]{}<>", lq_quant(1, 1),
					bracket,
				NULL),
			lq_quant(0, -1), NULL,
		lq_node("s", ")", lq_quant(1, 1), NULL, NULL)));
	
	t_lq_node *curly_bracket =
		lq_node("s", "{", lq_quant(1, 1), NULL,
		lq_node("r",
				lq_node("!?", "()[]{}<>", lq_quant(1, 1),
					bracket,
				NULL),
			lq_quant(0, -1), NULL,
		lq_node("s", "}", lq_quant(1, 1), NULL, NULL)));

	t_lq_node *square_bracket =
		lq_node("s", "[", lq_quant(1, 1), NULL,
		lq_node("r",
				lq_node("!?", "()[]{}<>", lq_quant(1, 1),
					bracket,
				NULL),
			lq_quant(0, -1), NULL,
		lq_node("s", "]", lq_quant(1, 1), NULL, NULL)));

	t_lq_node *pin_bracket =
		lq_node("s", "<", lq_quant(1, 1), NULL,
		lq_node("r",
				lq_node("!?", "()[]{}<>", lq_quant(1, 1),
					bracket,
				NULL),
			lq_quant(0, -1), NULL,
		lq_node("s", ">", lq_quant(1, 1), NULL, NULL)));

	bracket->arg = round_bracket;
	bracket->next_or =
		lq_node("g", curly_bracket, lq_quant(1, 1),
			lq_node("g", square_bracket, lq_quant(1, 1),
				lq_node("g", pin_bracket, lq_quant(1, 1),
					NULL, NULL),
				NULL),
			NULL);

	t_lq_node *delims =
		lq_node("^w", NULL, lq_quant(1, 1), NULL,
		lq_node("r",
				lq_node("?", "a-zA-Z", lq_quant(5, 5),
					lq_node("?", "a-zA-Z", lq_quant(2, 2), NULL, NULL),
				NULL),
			lq_quant(1, 1), NULL,
		lq_node("r",
				lq_node("$w", NULL, lq_quant(1, 1), NULL, NULL),
			lq_quant(1, 1), NULL, NULL)));

	"^w <[a-zA-Z]{5} | [a-zA-Z]{2}> $w";

	t_lq_node *delimsc =
		lq_node("^w", NULL, lq_quant(1, 1), NULL,
		lq_node("g",
				lq_node("r",
						lq_node("?", "a-zA-Z", lq_quant(5, 5),
							lq_node("?", "a-zA-Z", lq_quant(2, 2), NULL, NULL),
						NULL),
					lq_quant(1, 1), NULL, NULL),
			lq_quant(1, 1), NULL,
		lq_node("$w", NULL, lq_quant(1, 1), NULL, NULL)));

	t_lq_node *delimsb =
		lq_node("g",
				lq_node("g",
					lq_node("?", "h", lq_quant(1, -1), NULL, NULL),
				lq_quant(1, 1), NULL, NULL),
			lq_quant(1, 1), NULL,
		lq_node("s", "hello", lq_quant(1, 1), NULL, NULL));
	
	t_lq_node *begin = bracket;
		lq_node("s", "(", lq_quant(1, 1), NULL,
		lq_node("g",
				lq_node("g",
						lq_node("?", "a-z", lq_quant(1, -1), NULL, NULL),
					lq_quant(1, 1), NULL,
				lq_node("r",
						lq_node("s", ":", lq_quant(1, 1), NULL,
						lq_node("g",
								lq_node("?", "0-9", lq_quant(1, -1), NULL, NULL),
							lq_quant(1, 1), NULL, NULL)),
					lq_quant(1, 1), NULL,
				lq_node("s", ";", lq_quant(1, 1), NULL, NULL))),
			lq_quant(1, -1), NULL,
		lq_node("s", ")", lq_quant(1, 1), NULL, NULL)));

//	char *s = "bololfihvfhello";
//	char *s = "(l({ook}o[l])l<(he)[l{}]lo>)";
	char *s = "   ([h]d{<a>d}((((((((((((((((((((e)))))))))))<b>)<c>))))))))dd) ookf erb";
//	char *s = "(ab:78;vv:89945;)";
//	char *s = " -Helloo--ab";
//	char *s = "hhhhhello";
//	char *s = "Hello world";
//	char *s = "Hello      ";
	int pos = 0;
	int false_ret = 0;
	t_lq_list *groups = NULL;
	int r = lexiq(LQ_RUN | LQ_POS | LQ_END | LQ_GROUPS, begin, s, &pos, &groups);
	ft_printf("ret: %d %d: '%.*s'\n", r, false_ret, r, s + pos);
	ft_print_matches_tree(groups, 0);
//	ft_printf("original: '%s'\n", s);

//	lq_node_del(&begin);
	return 0;
}
