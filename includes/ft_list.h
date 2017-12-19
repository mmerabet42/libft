/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:39:12 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/19 20:19:09 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>

# ifndef FT_CMPFUNC_T
#  define FT_CMPFUNC_T

typedef int	(*t_cmpfunc)(const void *, const void *, size_t);

# endif

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*parent;
}					t_list;

t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *elem);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstpush(t_list *lst, t_list *elem);
void				ft_lstpushfront(t_list **alst, t_list *elem);
t_list				*ft_lstatpos(t_list *lst, int i);
t_list				*ft_lstfind(t_list *lst,
							const void *content,
							size_t content_size);
t_list				*ft_lstfindf(t_list *lst,
							const void *content,
							size_t content_size,
							t_cmpfunc cmp);
size_t				ft_lstsize(t_list *lst);
t_list				*ft_lstend(t_list *lst);
t_list				*ft_lstcopy(t_list *lst);
t_list				*ft_lstcopyone(t_list *lst);
t_list				*ft_lsterase(t_list **alst,
							const void *content,
							size_t content_size);
t_list				*ft_lsterasef(t_list **alst,
							const void *content,
							size_t content_size,
							t_cmpfunc cmp);
void				ft_lstswap(t_list *a, t_list *b);

#endif
