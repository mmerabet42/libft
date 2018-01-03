#include "ft_event.h"

int	ft_pevent_add(t_pevent *event, t_pcallback callback)
{
	return (ft_pevent_addp(event, callback, 0));
}

int	ft_pevent_addp(t_pevent *event, t_pcallback callback, int channel)
{
	t_btree		*bt;
	t_event		ev;

	if (!event || !callback)
		return (0);
	ev.trigger = channel;
	ev.callbacks = NULL;
	if (!(bt = ft_btree_getnewm(event->callbacks, &ev, sizeof(t_event),
		make_ptrpos(0, sizeof(int)))))
		return (0);
	if (!event->callbacks)
		event->callbacks = bt;
	if (!ft_event_add((t_event *)bt->content, (t_callback)callback))
		return (0);
	return (1);
}
