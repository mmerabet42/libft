/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:43:23 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/19 19:33:58 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

# include <stdlib.h>
# include "ft_list.h"

# ifndef FT_CMPFUNC_T
#  define FT_CMPFUNC_T

typedef int	(*t_cmpfunc)(const void *, const void *, size_t);

# endif

typedef struct		s_btree
{
	void			*content;
	size_t			content_size;
	struct s_btree	*parent;
	struct s_btree	*left;
	struct s_btree	*right;
}					t_btree;

t_btree				*ft_btree_new(const void *content, size_t content_size);
t_btree				*ft_btree_create(const void *content, size_t content_size);
void				ft_btree_delone(t_btree **abt, void (*del)(void *, size_t));
void				ft_btree_del(t_btree **abt, void (*del)(void *, size_t));
t_btree				*ft_btree_insert(t_btree *bt, t_btree *elem);
t_btree				*ft_btree_insertf(t_btree *bt,
								t_btree *elem,
								t_cmpfunc cmp);
t_btree				*ft_btree_erase(t_btree *bt,
								const void *content,
								size_t content_size);
t_btree				*ft_btree_erasef(t_btree *bt,
								const void *content,
								size_t content_size,
								t_cmpfunc cmp);
t_btree				*ft_btree_search(t_btree *bt,
								const void *content,
								size_t content_size);
t_btree				*ft_btree_searchf(t_btree *bt,
								const void *content,
								size_t content_size,
								t_cmpfunc cmp);
t_btree				*ft_btree_left(t_btree *bt);
t_btree				*ft_btree_right(t_btree *bt);
t_list				*ft_btree_tolist(t_btree *bt);
t_btree				*ft_btree_fromlist(t_list *lst);
t_btree				*ft_btree_fromlistf(t_list *lst, t_cmpfunc cmp);
t_btree				*ft_btree_copy(t_btree *bt);
void				ft_btree_swap(t_btree *a, t_btree *b, int childs);
t_btree				*ft_btree_leftrotate(t_btree *bt);
t_btree				*ft_btree_rightrotate(t_btree *bt);
t_btree				*ft_btree_balance(t_btree *bt);
size_t				ft_btree_size(t_btree *bt);

#endif
