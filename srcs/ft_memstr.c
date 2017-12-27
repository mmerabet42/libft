#include "ft_mem.h"

void*	ft_memstr(const void *a, size_t an, const void *b, size_t ab)
{
	size_t	i;

	i = 0;
	while (i < an)
	{
		if (i + ab <= an && ft_memcmp((const char *)a + i, b, ab) == 0)
			return ((char *)a + i);
		++i;
	}
	return (NULL);
}

int		ft_memstr_pos(const void *a, size_t an, const void *b, size_t ab)
{
	size_t	i;

	i = 0;
	while (i < an)
	{
		if (i + ab <= an && ft_memcmp((const char *)a + i, b, ab) == 0)
			return (i);
		++i;
	}
	return (-1);
}
