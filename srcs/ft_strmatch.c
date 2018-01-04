#include "ft_str.h"

static int	check_char(const char **str, const char **match)
{
	if (**str != **match)
		return (0);
	++(*str);
	++(*match);
	return (1);
}

int			ft_strmatch(const char *str, const char *match)
{
	while (*match)
	{
		if (*match == '*')
		{
			++match;
			if (*match == '*')
			{
				if (!check_char(&str, &match))
					return (0);
				continue;
			}
			if (!*match)
				return (1);
			while (*str && *str != *match)
				++str;
			if (!*str)
				return (0);
		}
		else if (!check_char(&str, &match))
			return (0);
	}
	return (*str ? 0 : 1);
}
