#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/lexiq.h"

int func_ex(void *arg, t_lq_eng *eng)
{
	printf("state: '%s'\n", eng->str);
	return 0;
}

int main(int argc, char **argv)
{
/*	t_lq_node *bracket =
		lq_node("g", NULL, lq_quant(1, 1), NULL, NULL);

	t_lq_node *round_bracket =
		lq_node("s", "(", lq_quant(1, 1), NULL,
		lq_node("r",
				lq_node("!?", "()[]{}<>", lq_quant(1, 1),
					bracket,
				NULL),
			lq_quant(0, -1), NULL,
		lq_node("s", ")", lq_quant(1, 1), NULL,
		lq_node("name", "ROUND_BRACKET", lq_quant(1, 1), NULL, NULL))));
	
	t_lq_node *curly_bracket =
		lq_node("s", "{", lq_quant(1, 1), NULL,
		lq_node("r",
				lq_node("!?", "()[]{}<>", lq_quant(1, 1),
					bracket,
				NULL),
			lq_quant(0, -1), NULL,
		lq_node("s", "}", lq_quant(1, 1), NULL,
		lq_node("name", "CURLY_BRACKET", lq_quant(1, 1), NULL, NULL))));

	t_lq_node *square_bracket =
		lq_node("s", "[", lq_quant(1, 1), NULL,
		lq_node("r",
				lq_node("!?", "()[]{}<>", lq_quant(1, 1),
					bracket,
				NULL),
			lq_quant(0, -1), NULL,
		lq_node("s", "]", lq_quant(1, 1), NULL,
		lq_node("name", "SQUARE_BRACKET", lq_quant(1, 1), NULL, NULL))));

	t_lq_node *pin_bracket =
		lq_node("s", "<", lq_quant(1, 1), NULL,
		lq_node("r",
				lq_node("!?", "()[]{}<>", lq_quant(1, 1),
					bracket,
				NULL),
			lq_quant(0, -1), NULL,
		lq_node("s", ">", lq_quant(1, 1), NULL,
		lq_node("name", "PIN_BRACKET", lq_quant(1, 1), NULL, NULL))));

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
				lq_node("g1",
					lq_node("?", "h", lq_quant(1, -1), NULL, NULL),
				lq_quant(1, 1), NULL, NULL),
			lq_quant(1, 1), NULL,
		lq_node("s", "hello", lq_quant(1, 1), NULL, NULL));
	
	t_lq_node *begin =// bracket;
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
*/

	t_lq_node *quantifier_a =
		lq_node("s", "{", lq_quant(1, 1), NULL,
		lq_node("?", " \t", lq_quant(0, -1), NULL,
		lq_node("g",
				lq_node("?", "0-9", lq_quant(0, -1), NULL,
				lq_node("name", "MIN_MAX", lq_quant(1, 1), NULL, NULL)),
			lq_quant(1, 1), NULL,
		lq_node("s", " \t", lq_quant(0, -1), NULL,
		lq_node("s", "}", lq_quant(1, 1), NULL,
		lq_node("name", "QUANTIFIER_A", lq_quant(1, 1), NULL, NULL))))));

	t_lq_node *quantifier_ab =
		lq_node("s", "{", lq_quant(1, 1), NULL,
		lq_node("?", " \t", lq_quant(0, -1), NULL,
		lq_node("g",
				lq_node("?", "0-9", lq_quant(0, -1), NULL,
				lq_node("name", "MIN", lq_quant(1, 1), NULL, NULL)),
			lq_quant(1, 1), NULL,
		lq_node("?", " \t", lq_quant(0, -1), NULL,
		lq_node("s", ",", lq_quant(1, 1), NULL,
		lq_node("s", " \t", lq_quant(0, -1), NULL,
		lq_node("g",
				lq_node("?", "0-9", lq_quant(0, -1), NULL,
				lq_node("name", "MAX", lq_quant(1, 1), NULL, NULL)),
			lq_quant(1, 1), NULL,
		lq_node("s", " \t", lq_quant(0, -1), NULL,
		lq_node("s", "}", lq_quant(1, 1), NULL,
		lq_node("name", "QUANTIFIER_AB", lq_quant(1, 1), NULL, NULL))))))))));

	t_lq_node *quantifier_c =
		lq_node("s", "*", lq_quant(1, 1),
			lq_node("s", "+", lq_quant(1, 1),
				lq_node("s", "?", lq_quant(1, 1), NULL,
				lq_node("name", "MARK", lq_quant(1, 1), NULL, NULL)),
			lq_node("name", "PLUS", lq_quant(1, 1), NULL, NULL)),
		lq_node("name", "WILDCARD", lq_quant(1, 1), NULL, NULL));

	t_lq_node *quantifier =
		lq_node("r", quantifier_c, lq_quant(1, 1),
			lq_node("r", quantifier_a, lq_quant(1, 1),
				lq_node("r", quantifier_ab, lq_quant(1, 1), NULL, NULL),
			NULL),
		NULL); 

	t_lq_node *node_rule =
		lq_node("?", "a-zA-Z0-9_-", lq_quant(1, -1), NULL,
		lq_node("name", "RULE", lq_quant(1, 1), NULL, NULL));

	t_lq_node *backslash_char =
		lq_node("s", "\\", lq_quant(1, 1), NULL,
		lq_node("?", "", lq_quant(1, 1), NULL,
		lq_node("name", "BACKSLASH_CHAR", lq_quant(1, 1), NULL, NULL)));

	t_lq_node *quote =
		lq_node("s", "'", lq_quant(1, 1), NULL,
		lq_node("r",
				lq_node("g", backslash_char, lq_quant(1, 1),
					lq_node("g",
							lq_node("!?", "'\\", lq_quant(1, -1), NULL,
							lq_node("name", "CHAR", lq_quant(1, 1), NULL, NULL)),
						lq_quant(1, 1), NULL, NULL),
				NULL),
			lq_quant(0, -1), NULL,
		lq_node("s", "'", lq_quant(1, 1), NULL,/*
			lq_node("?", "", lq_quant(0, -1), NULL,
			lq_node("name", "UNKNOWN_QUOTE", lq_quant(1, 1), NULL, NULL)),*/
		lq_node("name", "QUOTE", lq_quant(1, 1), NULL, NULL))));

	t_lq_node *inner_bracket =
		lq_node("r",
				lq_node("g", backslash_char, lq_quant(1, 1),
					lq_node("g",
							lq_node("!?", "]\\", lq_quant(1, -1), NULL,
							lq_node("name", "CHAR", lq_quant(1, 1), NULL, NULL)),
						lq_quant(1, 1), NULL, NULL),
				NULL),
			lq_quant(0, -1), NULL,
		lq_node("name", "ARGUMENT", lq_quant(1, 1), NULL, NULL));

	t_lq_node *node_bracket =
		lq_node("s", "[", lq_quant(1, 1), NULL,
		lq_node("r",
				lq_node("g", node_rule, lq_quant(1, 1),
					lq_node("g",
							lq_node("name", "DEFAULT", lq_quant(1, 1), NULL, NULL),
						lq_quant(1, 1), NULL,
					lq_node("s", "@", lq_quant(0, 1), NULL, NULL)),
				lq_node("s", "@", lq_quant(1, 1), NULL, NULL)),
			lq_quant(1, 1), NULL,
		lq_node("r",
				lq_node("g", quote, lq_quant(1, 1),
					lq_node("g", inner_bracket, lq_quant(1, 1), NULL, NULL),
				NULL),
			lq_quant(1, 1), NULL,
		lq_node("s", "]", lq_quant(1, 1), NULL,
		lq_node("name", "BRACKET", lq_quant(1, 1), NULL, NULL)))));

	t_lq_node *node_dot =
		lq_node("s", ".", lq_quant(1, 1), NULL,
		lq_node("name", "DOT", lq_quant(1, 1), NULL, NULL));

	t_lq_node *node_boundary =
		lq_node("?", "^$", lq_quant(1, 1), NULL,
		lq_node("?", "nw", lq_quant(0, 1), NULL,
		lq_node("name", "BOUNDARY", lq_quant(1, 1), NULL, NULL)));

	t_lq_node *expression =
		lq_node("r", NULL, lq_quant(1, 1), NULL, NULL);

	t_lq_node *node_parenthesis =
		lq_node("s", "(", lq_quant(1, 1), NULL,
		lq_node("g", expression, lq_quant(1, 1), NULL,
		lq_node("s", ")", lq_quant(1, 1), NULL,
		lq_node("name", "PARENTHESIS", lq_quant(1, 1), NULL, NULL))));

	t_lq_node *node_capture =
		lq_node("s", "<", lq_quant(1, 1), NULL,
		lq_node("g", expression, lq_quant(1, 1), NULL,
		lq_node("s", ">", lq_quant(1, 1), NULL,
		lq_node("name", "CAPTURE", lq_quant(1, 1), NULL, NULL))));

	t_lq_node *node =
		lq_node("g",
				lq_node("r", node_rule, lq_quant(1, 1),
					lq_node("r", node_bracket, lq_quant(1, 1),
						lq_node("r", node_dot, lq_quant(1, 1),
							lq_node("r", quote, lq_quant(1, 1),
								lq_node("r", node_boundary, lq_quant(1, 1),
									lq_node("r", node_parenthesis, lq_quant(1, 1),
										lq_node("r", node_capture, lq_quant(1, 1), NULL, NULL),
									NULL),
								NULL),
							NULL),
						NULL),
					NULL),
				NULL),
			lq_quant(1, 1), NULL,
		lq_node("?", " \t", lq_quant(0, -1), NULL,
		lq_node("g", quantifier, lq_quant(0, 1), NULL,
		lq_node("name", "NODE", lq_quant(1, 1), NULL, NULL))));
	
	expression->arg =
		lq_node("r",
				lq_node("?", " \t", lq_quant(0, -1), NULL,
				lq_node("g",
						lq_node("r", node, lq_quant(1, 1),
							lq_node("?", "", lq_quant(1, -1), NULL,
							lq_node("name", "UNKNOWN_TOKEN", lq_quant(1, 1), NULL, NULL)),
						NULL),
					lq_quant(1, 1), NULL,
				lq_node("?", " \t", lq_quant(0, -1), NULL,
				lq_node("g",
						lq_node("s", "|", lq_quant(1, 1), NULL,
						lq_node("name", "OR", lq_quant(1, 1), NULL, NULL)),
					lq_quant(0, 1), NULL,
				lq_node("?", " \t", lq_quant(0, -1), NULL, NULL))))),
			lq_quant(0, -1), NULL,
		lq_node("name", "EXPRESSION", lq_quant(1, 1), NULL, NULL));

	lexiq(LQ_ADD, "ROUND_BRACKET",
		lq_node("s", "(", lq_quant(1, 1), NULL,
		lq_node("r",
				lq_node("!?", "()[]{}", lq_quant(1, 1),
					lq_node("BRACKET", NULL, lq_quant(1, 1), NULL, NULL),
				NULL),
			lq_quant(0, -1), NULL,
		lq_node("s", ")", lq_quant(1, 1), NULL, NULL)))
	);

	lexiq(LQ_ADD, "SQUARE_BRACKET",
		lq_node("s", "[", lq_quant(1, 1), NULL,
		lq_node("r",
				lq_node("!?", "()[]{}", lq_quant(1, 1),
					lq_node("BRACKET", NULL, lq_quant(1, 1), NULL, NULL),
				NULL),
			lq_quant(0, -1), NULL,
		lq_node("s", "]", lq_quant(1, 1), NULL, NULL)))
	);

	lexiq(LQ_ADD, "CURLY_BRACKET",
		lq_node("s", "{", lq_quant(1, 1), NULL,
		lq_node("r",
				lq_node("!?", "()[]{}", lq_quant(1, 1),
					lq_node("BRACKET", NULL, lq_quant(1, 1), NULL, NULL),
				NULL),
			lq_quant(0, -1), NULL,
		lq_node("s", "}", lq_quant(1, 1), NULL, NULL)))
	);

	lexiq(LQ_ADD, "BRACKET",
		lq_node("g",
				lq_node("ROUND_BRACKET", NULL, lq_quant(1, 1),
					lq_node("SQUARE_BRACKET",  NULL, lq_quant(1, 1),
						lq_node("CURLY_BRACKET", NULL, lq_quant(1, 1), NULL, NULL),
					NULL),
				NULL),
			lq_quant(1, 1), NULL, NULL)
	);

	lexiq(LQ_ADD, "UNKNOWN_TOKEN",
		lq_node("?", "", lq_quant(0, -1), NULL, NULL)
	);

	lexiq(LQ_ADD, "CONSTANT",
		lq_node("?", "0-9", lq_quant(1, -1), NULL, NULL)
	);

	lexiq(LQ_ADD, "FACTOR",
		lq_node("g",
				lq_node("CONSTANT", NULL, lq_quant(1, 1),
					lq_node("s", "(", lq_quant(1, 1), NULL,
					lq_node("EXPRESSION", NULL, lq_quant(1, 1), NULL,
					lq_node("s", ")", lq_quant(1, 1), NULL, NULL))),
				NULL),
			lq_quant(1, 1), NULL, NULL)
	);

	lexiq(LQ_ADD, "TERM",
		lq_node("g",
				lq_node("FACTOR", NULL, lq_quant(1, 1),
					lq_node("TERM", NULL, lq_quant(1, 1), NULL,
					lq_node("s", "*", lq_quant(1, 1), NULL,
					lq_node("FACTOR", NULL, lq_quant(1, 1), NULL, NULL))),
				NULL),
			lq_quant(1, 1), NULL, NULL)
	);

	lexiq(LQ_ADD, "EXPRESSION",
		lq_node("g",
				lq_node("TERM", NULL, lq_quant(1, 1),
					lq_node("EXPRESSION", NULL, lq_quant(1, 1), NULL,
					lq_node("s", "+", lq_quant(1, 1), NULL,
					lq_node("TERM", NULL, lq_quant(1, 1), NULL, NULL))),
				NULL),
			lq_quant(1, 1), NULL, NULL)
	);


	t_lq_node *begin = lq_node("g", expression, lq_quant(1, 1), NULL, NULL);
	//		lq_node("EXPRESSION", NULL, lq_quant(1, 1), NULL, NULL);
	/*	lq_node("g",
				lq_node("g",
						lq_node("g",
								lq_node("?", "0-9a-z", lq_quant(1, -1), NULL, NULL),
							lq_quant(1, 1), NULL, NULL),
					lq_quant(1, 1), NULL, NULL),
			lq_quant(1, -1), NULL,
		lq_node("g",
				lq_node("?", "0-9", lq_quant(1, -1), NULL, NULL),
			lq_quant(1, 1), NULL, NULL));*/

//	char *s = "bololfihvfhello";
//	char *s = "(l({ook}o[l])l<(he)[l{}]lo>)";
//	char *s = "()";
//	char *s = "   ([h]d{<a>d}((((((((((((((((((((e)))))))))))<b>)<c>))))))))dd) ookf erb";
//	char *s = "(ab:78;vv:89945;)";
//	char *s = " -Helloo--ab";
//	char *s = "hhhhhello";
	char *s = argv[1];
	int pos = 0;
	int false_ret = 0;
	t_lq_list *groups = NULL;
	int r = lexiq(LQ_RUN | LQ_GROUPS, begin, s, &groups);
	ft_printf("ret: %d %d: '%.*s'\n", r, false_ret, r, s + pos);
	ft_print_matches_tree(groups, 0);
//	ft_printf("original: '%s'\n", s);

//	lq_node_del(&begin);
	return 0;
}
/*
*/
