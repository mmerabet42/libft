#include "lexiq.h"

void subtract_tret(t_lq_eng *it_eng, int tret)
{
	int *last_len;
	t_lq_eng *eng_loop;
	t_lq_eng *eng_next;
	int eng_tret;

	eng_loop = NULL;
	eng_next = NULL;
	eng_tret = tret;
	if ((last_len = it_eng->len_ptr))
	{
		eng_tret = *last_len;
		*last_len -= tret;
	}
	it_eng = it_eng->parent_eng;
	while (it_eng && !eng_next)
	{
		if (it_eng->len_ptr != last_len)
		{
			if ((last_len = it_eng->len_ptr))
				*it_eng->len_ptr -= eng_tret;
		}
		if (!eng_next && !eng_loop
				&& get_min(it_eng) != get_max(it_eng)
				&& (get_max(it_eng) == -1
					|| (it_eng->i + 1 < get_max(it_eng)
						&& get_max(it_eng) != -1)))
			eng_loop = it_eng;
		if (!eng_next && it_eng->current->next)
			eng_next = it_eng;
		it_eng = it_eng->parent_eng;
	}
	if (it_eng && it_eng->len_ptr && it_eng->len_ptr != last_len)
		*it_eng->len_ptr -= eng_tret;
}

int get_proper_eng(t_lq_eng *it_eng, t_lq_eng **eng_loop, t_lq_eng **eng_next, int tret)
{
	int *last_len;
	int eng_tret;

	*eng_loop = NULL;
	*eng_next = NULL;
	eng_tret = tret;
	if ((last_len = it_eng->len_ptr))
	{
		*last_len += tret;
		eng_tret = *last_len;
	}
	it_eng = it_eng->parent_eng;
	while (it_eng && !*eng_next)
	{
		if (it_eng->len_ptr != last_len)
		{
			if ((last_len = it_eng->len_ptr))
				*it_eng->len_ptr += eng_tret;
		}
		if (!*eng_next && !*eng_loop
				&& get_min(it_eng) != get_max(it_eng)
				&& (get_max(it_eng) == -1
					|| (it_eng->i + 1 < get_max(it_eng)
						&& get_max(it_eng) != -1)))
			*eng_loop = it_eng;
		if (!*eng_next && it_eng->current->next)
			*eng_next = it_eng;
		it_eng = it_eng->parent_eng;
	}
	if (it_eng && it_eng->len_ptr && it_eng->len_ptr != last_len)
	{
		*it_eng->len_ptr += eng_tret;
	}
	return (it_eng ? 1 : 0);
}

t_lq_eng *proper_copy(t_lq_eng *a, t_lq_eng *b, int increment_i)
{
	a->len_ptr = NULL;
	a->current_group = NULL;
	a->rule_name_ptr = NULL;
	if ((a->parent_eng = b->parent_eng))
	{
		a->len_ptr = b->parent_eng->len_ptr;
		a->current_group = b->parent_eng->current_group;
		if (b->parent_eng->current->rule->flags & LQ_TRANSPARENT)
			a->rule_name_ptr = b->parent_eng->rule_name_ptr;
	}
	a->groups = b->groups;
	a->groups_head = b->groups_head;
	if (increment_i)
		a->i = b->i + 1;
	return (a);
}

int exec_lookahead1(t_lq_eng *eng, t_lq_eng *eng2, t_lq_eng **eng_next, int tret)
{
	t_lq_eng *eng_loop;
	int ret;

	eng_loop = NULL;
	lq_eng_copy(eng2, eng);
	get_proper_eng(eng, &eng_loop, eng_next, tret);
	if ((eng_loop && eng_loop->i + 1 < get_min(eng_loop))
			|| (!*eng_next && eng_loop && eng_loop->i + 1 >= get_min(eng_loop)))
	{
		proper_copy(eng2, eng_loop, 1);
		if ((ret = lq_run(eng_loop->current, eng2)) >= 0)
		{
			eng_loop->lookahead_ret = ret;
			return tret;
		}
	}
	else if (*eng_next)
	{
		if (eng_loop && eng_loop->i + 1 >= get_min(eng_loop))
		{
			proper_copy(eng2, eng_loop, 1);
			if ((ret = lq_run(eng_loop->current, eng2)) >= 0)
			{
				eng_loop->lookahead_ret = ret;
				return tret;
			}
		}
		else
		{
			proper_copy(eng2, *eng_next, 0);
			if ((ret = lq_run((*eng_next)->current->next, eng2)) >= 0)
			{
				(*eng_next)->lookahead_ret = ret;
				return tret;
			}
		}
	}
	subtract_tret(eng, tret);
	return -1;
}

int exec_lookahead2(t_lq_eng *eng, t_lq_eng *eng2, int tret)
{
	int ret;
	t_lq_eng *eng_next;
	t_lq_eng *eng_loop;

	lq_eng_copy(eng2, eng);
	get_proper_eng(eng, &eng_loop, &eng_next, tret);
	if (!eng_next && !eng_loop)
		return ((eng->flags & LQ_END) || eng->str >= eng->str_end ? tret : -1);
	if ((eng_loop && eng_loop->i + 1 < get_min(eng_loop))
			|| (!eng_next && eng_loop && eng_loop->i + 1 >= get_min(eng_loop)))
	{
		proper_copy(eng2, eng_loop, 1);
		eng_loop->lookahead_ret = lq_run(eng_loop->current, eng2);
	}
	else if (eng_next)
	{
		if (eng_loop && eng_loop->i + 1 >= get_min(eng_loop))
		{
			proper_copy(eng2, eng_loop, 1);
			if ((ret = lq_run(eng_loop->current, eng2)) <= -1)
			{
				subtract_tret(eng, tret);
				return ret;
			}
			eng_loop->lookahead_ret = ret;
		}
		else
		{
			proper_copy(eng2, eng_next, 0);
			if ((ret = lq_run(eng_next->current->next, eng2)) >= 0)
				eng_next->lookahead_ret = ret;
			else
			{
				subtract_tret(eng, tret);
				return ret;
			}
		}
	}
	return tret;
}

int exec_next(t_lq_eng *eng, t_lq_eng *eng2, int tret)
{
	int ret;

	if (eng->len_ptr)
		*eng->len_ptr += tret;
	lq_eng_copy(eng2, eng);
	eng2->len_ptr = NULL;
	eng2->current_group = NULL;
	eng2->rule_name_ptr = NULL;
	if (eng->parent_eng)
	{
		eng2->current_group = eng->parent_eng->current_group;
		eng2->len_ptr = eng->parent_eng->len_ptr;
		eng2->rule_name_ptr = eng->parent_eng->rule_name_ptr;
	}
	if ((ret = lq_run(eng->current->next, eng2)) >= 0)
		return tret + ret;
	if (eng->len_ptr)
		*eng->len_ptr -= tret;
	return -1;
}

int exec_or(t_lq_eng *eng, t_lq_eng *eng2, int ret)
{
	if (!eng->current->next_or)
		return ret;
	eng->str = eng->str_p;
	lq_eng_copy(eng2, eng);
	eng2->len_ptr = NULL;
	eng2->current_group = NULL;
	eng2->rule_name_ptr = NULL;
	if (eng->parent_eng)
	{
		eng2->current_group = eng->parent_eng->current_group;
		eng2->len_ptr = eng->parent_eng->len_ptr;
		eng2->rule_name_ptr = eng->parent_eng->rule_name_ptr;
	}
	return lq_run(eng->current->next_or, eng2);
}

int exec_optional(t_lq_eng *eng, t_lq_eng *eng2, t_lq_eng **eng_next, int tret)
{
	int ret;

	*eng_next = NULL;
	if (eng->i >= get_min(eng) && eng->current->next)
	{
		if ((ret = exec_next(eng, eng2, tret)) >= 0)
			return ret;
	}
	else if (eng->i >= get_min(eng))
	{
		if ((ret = exec_lookahead1(eng, eng2, eng_next, tret)) >= 0)
			return ret;
	}
	return -1;
}
#include <unistd.h>
int exec_parser(t_lq_eng *eng, t_lq_eng *eng2)
{
	int ret;
	t_list *parser_it;
	t_list *parser_it_tmp;

	if (eng->current->rule->parser)
	{
		lq_eng_copy(eng2, eng);
		eng2->parent_eng = eng;
		return (lq_run(eng->current->rule->parser, eng2));
	}
	else if ((parser_it = eng->current->rule->parsers_it))
	{
	//	t_lq_node *node = (t_lq_node *)parser_it->content;
	//	lq_printf(eng, "helo: '%s'\n", (node->rule ? node->rule->name : NULL));
		if (!(eng->current->rule->parsers_it = parser_it->next))
			eng->current->rule->parsers_it = eng->current->rule->parsers;
		parser_it_tmp = parser_it;
		while (parser_it)
		{
			lq_eng_copy(eng2, eng);
			eng2->parent_eng = eng;
			if ((ret = lq_run((t_lq_node *)parser_it->content, eng2)) >= 0)
				return (ret);
			parser_it = parser_it->next;
		}
		parser_it = eng->current->rule->parsers;
		while (parser_it != parser_it_tmp)
		{
			lq_eng_copy(eng2, eng);
			eng2->parent_eng = eng;
			if ((ret = lq_run((t_lq_node *)parser_it->content, eng2)) >= 0)
				return (ret);
			parser_it = parser_it->next;
		}
	}
	return (-1);
}

int lq_run(t_lq_node *parser, t_lq_eng *eng)
{
	int ret;
	int ret2;
	t_lq_eng eng2;
	t_lq_eng *eng_next;
	const char *tmp_rule_name;

	ret = 0;
	eng->current = parser;
	if (eng->i >= get_max(eng) && get_max(eng) != -1)
	{
		if (!parser->next)
			return (exec_lookahead2(eng, &eng2, 0));
		return (exec_next(eng, &eng2, 0));
	}
	if (!parser->rule && !(parser->rule = lq_get_rule(parser->rule_name)))
		return (-1);
//	lq_printf(eng, "|node: '%s' '%s'\n", parser->rule->name, eng->str);
	tmp_rule_name = NULL;
	if (eng->rule_name_ptr && (parser->rule->flags & LQ_SAVE_RULE_NAME))
	{
		tmp_rule_name = *eng->rule_name_ptr;
		*eng->rule_name_ptr = parser->rule->name;
	}
	if (parser->rule->func)
		ret = parser->rule->func(parser->arg, eng);
	else if (parser->rule->parser || parser->rule->parsers)
	{
		ret = exec_parser(eng, &eng2);
		if (ret >= 0)
			return (ret + eng2.lookahead_ret);
	//	lq_eng_copy(&eng2, eng);
	//	eng2.parent_eng = eng;
	//	ret = lq_run(parser->rule->parser, &eng2);
	//	if (ret >= 0)
	//		return (ret);
	}
//	lq_printf(eng, "ret: '%s' %d\n", parser->rule->name, ret);
	if (ret <= -1 && eng->rule_name_ptr && (parser->rule->flags & LQ_SAVE_RULE_NAME))
		*eng->rule_name_ptr = tmp_rule_name;
	if (ret <= -1 && eng->i < get_min(eng))
		return (exec_or(eng, &eng2, ret));
	else if (ret <= -1)
	{
		if ((ret2 = exec_optional(eng, &eng2, &eng_next, 0)) >= 0)
			return (ret2);
		if (parser->next || eng_next)
			return (ret);
		if (eng->str < eng->str_end && !(eng->flags & LQ_END))
			return (ret);
		return (0);
	}
	if ((parser->rule->flags & LQ_STOP))
		return (ret);
	eng->i += 1;
	if (eng->str >= eng->str_end)
	{
		if (eng->i < get_min(eng))
			return (-1);
		if (!parser->next)
			return (exec_lookahead2(eng, &eng2, ret));
		return (exec_next(eng, &eng2, ret));
	}
	eng->str += ret;
	if (eng->len_ptr)
		*eng->len_ptr += ret;
	if (eng->i >= get_max(eng) && get_max(eng) != -1)
	{
		if (!parser->next)
			ret2 = exec_lookahead2(eng, &eng2, 0);
		else
			ret2 = exec_next(eng, &eng2, 0);
		if (ret2 <= -1)
		{
			eng->str -= ret;
			if (eng->len_ptr)
				*eng->len_ptr -= ret;
		}
		return (ret2 <= -1 ? ret2 : ret + ret2);
	}
	if ((ret2 = lq_run(parser, eng)) >= 0)
		return (ret + ret2);
	if ((ret2 = exec_optional(eng, &eng2, &eng_next, 0)) >= 0)
		return (ret + ret2);
	eng->str -= ret;
	if (eng->len_ptr)
		*eng->len_ptr -= ret;
	return (ret2);	
}