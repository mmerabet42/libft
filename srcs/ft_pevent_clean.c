#include "ft_event.h"

static void	btiter(t_btree *bt)
{
	ft_event_del((t_event **)&bt->content);
}

void	ft_pevent_clean(t_pevent *event)
{
	if (event)
		ft_btree_iter(event->callbacks, btiter);
	ft_btree_del(&event->callbacks, NULL);
}

void	ft_pevent_cleanp(t_pevent *event, int channel)
{
	t_btree	*bt;

	if (!event || !(bt = ft_btree_erasem(&event->callbacks, &channel, 0,
		sizeof(int))))
		return ;
	ft_event_del((t_event **)&bt->content);
	ft_btree_del(&bt, NULL);
}
