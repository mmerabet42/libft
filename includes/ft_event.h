
#include "ft_list.h"

/*
** Simple event system, when the event is triggered all callbacks functions are
** called in the same order ther were added.
*/

typedef struct	s_event
{
	t_list		*callbacks;
	int			trigger;
}				t_event;

typedef void (*t_callback)(t_event *event, void *data);

t_event			*ft_event_new(void);
void			ft_event_del(t_event **event);

int				ft_event_add(t_event *event, t_callback callback);
int				ft_event_remove(t_event *event, t_callback callback);

void			ft_event_trigger(t_event *event, void *data);
void			ft_event_release(t_event *event);

/*
** A little bit different, callbacks are called depending on their priority
** channels.
*/

typedef struct	s_pevent
{
	t_btree		*callbacks;
	int			trigger;
}				t_pevent;

typedef void (*t_pcallback)(t_pevent *event, void *data);

t_pevent		*ft_pevent_new(void);
void			ft_pevent_del(t_pevent **event);

int				ft_pevent_add(t_prevent *event, t_pcallback callback);
int				ft_pevent_addp(t_pevent *event,
						int priority,
						t_pcallback callback);
int				ft_pevent_remove(t_pevent *event, t_pcallback callback);
int				ft_pevent_removep(t_pevent *event,
						int priority,
						t_pcallback callback);

void			ft_pevent_trigger(t_pevent *event, void *data);
void			ft_pevent_release(t_pevent *event);
