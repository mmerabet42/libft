#include "ft_event.h"

static void	btiter(t_btree *bt, t_pevent *event, void *data)
{
	t_list	*lst;

	if (!bt || !event)
		return ;
	btiter(bt->left, event, data);
	lst = ((t_event *)bt->content)->callbacks;
	while (lst && event->trigger)
	{
		if (lst->content)
			((t_pcallback)lst->content)(event, data);
		lst = lst->next;
	}
	if (event->trigger)
		btiter(bt->right, event, data);
}

void	ft_pevent_trigger(t_pevent *event, void *data)
{
	if (event)
	{
		event->trigger = 1;
		btiter(event->callbacks, event, data);
		event->trigger = 0;
	}
}

void	ft_pevent_release(t_pevent *event)
{
	if (event)
		event->trigger = 0;
}
