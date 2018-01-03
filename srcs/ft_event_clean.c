#include "ft_event.h"

void	ft_event_clean(t_event *event)
{
	if (event)
		ft_lstdel(&event->callbacks, NULL);
}
