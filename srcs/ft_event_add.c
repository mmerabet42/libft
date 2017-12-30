#include "ft_event.h"

int	ft_event_add(t_event *event, t_callback callback)
{
	t_list	*lst;

	if (!event || !callback)
		return (0);
	lst = ft_lstpush(event->callbacks,
		ft_lstcreate(callback, sizeof(t_callback)));
	if (!event->callbacks)
		event->callbacks = lst;
	return (1);
}

int	ft_event_remove(t_event *event, t_callback callback)
{
	t_list	*lst;

	if (!event || !callback ||
		!(lst = ft_lsterase(&event->callbacks, callback, sizeof(t_callback))))
		return (0);
	ft_lstdel(&lst, NULL);
	return (1);
}
