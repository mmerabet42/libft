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
	t_lq_node *round_bracket =
		lq_node("s", "(", 1, 1, NULL,
		lq_node("r",
				lq_node("!?", "()[]{}<>", 1, 1,
					lq_node("r", NULL, 1, 1, NULL, NULL),
					NULL),
			0, -1, NULL,
		lq_node("s", ")", 1, 1, NULL, NULL)));
	
	t_lq_node *curly_bracket =
		lq_node("s", "{", 1, 1, round_bracket,
		lq_node("r",
				lq_node("!?", "()[]{}<>", 1, 1,
					lq_node("r", NULL, 1, 1, NULL, NULL),
					NULL),
			0, -1, NULL,
		lq_node("s", "}", 1, 1, NULL, NULL)));

	t_lq_node *square_bracket =
		lq_node("s", "[", 1, 1, curly_bracket,
		lq_node("r",
				lq_node("!?", "()[]{}<>", 1, 1,
					lq_node("r", NULL, 1, 1, NULL, NULL),
					NULL),
			0, -1, NULL,
		lq_node("s", "]", 1, 1, NULL, NULL)));

	t_lq_node *bracket =
		lq_node("s", "<", 1, 1, square_bracket,
		lq_node("r",
				lq_node("!?", "()[]{}<>", 1, 1,
					lq_node("r", NULL, 1, 1, NULL, NULL),
					NULL),
			0, -1, NULL,
		lq_node("s", ">", 1, 1, NULL, NULL)));

	t_lq_node *delims =
		lq_node("^w", NULL, 1, 1, NULL,
			lq_node("r",
					lq_node("?", "a-zA-Z", 5, 5,
						lq_node("?", "a-zA-Z", 2, 2, NULL, NULL),
					NULL),
				1, 1, NULL,
		lq_node("r",
				lq_node("$w", NULL, 1, 1, NULL, NULL),
			1, 1, NULL, NULL)));

	"^w <[a-zA-Z]{5} | [a-zA-Z]{2}> $w";

	t_lq_node *delimsc =
		lq_node("^w", NULL, 1, 1, NULL,
		lq_node("g",
				lq_node("r",
						lq_node("?", "a-zA-Z", 5, 5,
							lq_node("?", "a-zA-Z", 2, 2, NULL, NULL),
						NULL),
					1, 1, NULL, NULL),
			1, 1, NULL,
		lq_node("$w", NULL, 1, 1, NULL, NULL)));

	t_lq_node *delimsb =
		lq_node("r",
				lq_node("r",
					lq_node("s", "h", 1, -1, NULL, NULL),
				1, 1, NULL, NULL),
			1, 1, NULL,
		lq_node("s", "hello", 1, 1, NULL, NULL));
	
	t_lq_node *begin =
		lq_node("s", "(", 1, 1, NULL,
		lq_node("r",
				lq_node("r",
						lq_node("?", "a-z", 1, -1, NULL, NULL),
					1, 1, NULL,
				lq_node("r",
						lq_node("s", ":", 1, 1, NULL,
						lq_node("r",
								lq_node("?", "0-9", 1, -1, NULL, NULL),
							1, 1, NULL, NULL)),
					1, 1, NULL,
				lq_node("s", ";", 1, 1, NULL, NULL))),
			1, -1, NULL,
		lq_node("s", ")", 1, 1, NULL, NULL)));

//	char *s = "     (lo(a)ol) l";
//	char *s = "   ([h]d{<a>d}((((((((((((((((((((e)))))))))))<b>)<c>))))))))dd) ookf erb";
	char *s = "(ab:78;vv:89945;)";
//	char *s = " -Helloo--ab";
//	char *s = "hhhhhello";
//	char *s = "hello world";
//	char *s = "Hello      ";
	int pos = 0;
	int false_ret = 0;
	int r = lexiq(LQ_RUN | LQ_POS | LQ_END, begin, s, &pos);
	printf("ret: %d %d: '%.*s'\n", r, false_ret, r, s + pos);

//	lq_node_del(&begin);
	return 0;
}
