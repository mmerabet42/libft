
#include "ft_list.h"

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
