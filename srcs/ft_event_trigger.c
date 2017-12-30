#include "ft_event.h"

void	ft_event_trigger(t_event *event, void *data)
{
	t_list	*lst;

	if (!event)
		return ;
	lst = event->callbacks;
	event->trigger = 1;
	while (lst && event->trigger)
	{
		if (lst->content)
			((t_callback)lst->content)(event, data);
		lst = lst->next;
	}
	event->trigger = 0;
}

void	ft_event_release(t_event *event)
{
	if (event)
		event->trigger = 0;
}
