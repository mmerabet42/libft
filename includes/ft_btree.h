/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:43:23 by mmerabet          #+#    #+#             */
/*   Updated: 2017/12/22 22:02:33 by mmerabet         ###   ########.fr       */
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

typedef struct		s_ptrpos
{
	size_t			start;
	size_t			len;
}					t_ptrpos;

/*
** Binary tree creations and deletions
*/

t_btree				*ft_btree_new(const void *content, size_t content_size);
t_btree				*ft_btree_create(void *content, size_t content_size);
void				ft_btree_delone(t_btree **abt, void (*del)(void *, size_t));
void				ft_btree_del(t_btree **abt, void (*del)(void *, size_t));

/*
** Binary tree insertions and removals.
** The insert functions inserts the element and returns it.
** The erase functions extract the first occurence of 'content' from the binary
** tree then returns it to be properly deleted by the user.
*/

t_btree				*ft_btree_insert(t_btree *bt, t_btree *elem);
t_btree				*ft_btree_insertf(t_btree *bt,
								t_btree *elem,
								t_cmpfunc cmp);
t_btree				*ft_btree_insertm(t_btree *bt,
								t_btree *elem,
								size_t pstart,
								size_t plen);
t_btree				*ft_btree_erase(t_btree **bt,
								const void *content,
								size_t content_size);
t_btree				*ft_btree_erasef(t_btree **bt,
								const void *content,
								size_t content_size,
								t_cmpfunc cmp);
t_btree				*ft_btree_erasem(t_btree **bt,
								const void *content,
								size_t pstart,
								size_t plen);

/*
** Extract all occurences of 'content' and put them all in a binary tree then
** returns it. The binary tree law is followed, so the returned binary tree
** will have only right childs, because when an element is greater or equal it
** is put on the right.
*/

t_btree				*ft_btree_erase_all(t_btree **bt,
								const void *content,
								size_t content_size);
t_btree				*ft_btree_erasef_all(t_btree **bt,
								const void *content,
								size_t content_size,
								t_cmpfunc cmp);
t_btree				*ft_btree_erasem_all(t_btree **bt,
								const void *content,
								size_t pstart,
								size_t plen);

/*
** Return the matched element 'content' as the user defines it
*/

t_btree				*ft_btree_search(t_btree *bt,
								const void *content,
								size_t content_size);
t_btree				*ft_btree_searchf(t_btree *bt,
								const void *content,
								size_t content_size,
								t_cmpfunc cmp);
t_btree				*ft_btree_searchm(t_btree *bt,
								const void *content,
								size_t pstart,
								size_t plen);

/*
** Searchs an element in SPLAY mode, this means that the matched element is
** set as root. Useful when the same elements are accessed frequently.
*/

t_btree				*ft_btree_splay(t_btree *bt,
								const void *content,
								size_t content_size);
t_btree				*ft_btree_splayf(t_btree *bt,
								const void *content,
								size_t content_size,
								t_cmpfunc cmp);
t_btree				*ft_btree_splaym(t_btree *bt,
								const void *content,
								size_t pstart,
								size_t plen);

/*
** Return number 'content's occurences in the given binary tree.
*/

int					ft_btree_count(t_btree *bt,
								const void *content,
								size_t content_size);
int					ft_btree_countf(t_btree *bt,
								const void *content,
								size_t content_size,
								t_cmpfunc cmp);
int					ft_btree_countm(t_btree *bt,
								const void *content,
								size_t pstart,
								size_t plen);

/*
** Returns the position of a binary tree relative to another one, -1 means it
** is on the left branch, 1 on the right one, and 0 means that they are not
** is the same tree.
*/

int					ft_btree_pos(t_btree *bt, t_btree *elem);

/*
** Returns the root of the current tree.
*/

t_btree				*ft_btree_root(t_btree *bt);

/*
** Gives the left/right most child of a binary tree, if the binary tree rules
** are followed, the left most child is the minimum value and the right most
** child is the maximum value.
*/

t_btree				*ft_btree_left(t_btree *bt);
t_btree				*ft_btree_right(t_btree *bt);

/*
** Convert a binary tree to ia list, the returned list is automatically sorted.
** Convert a list to a binary tree.
*/

t_list				*ft_btree_tolist(t_btree *bt);
t_btree				*ft_btree_fromlist(t_list *lst);
t_btree				*ft_btree_fromlistf(t_list *lst, t_cmpfunc cmp);

t_btree				*ft_btree_copy(t_btree *bt);

/*
** Swap the values of the two binary tree, the content_size is swapped as the
** content. If childs is TRUE then the childs are swapped too.
*/

void				ft_btree_swap(t_btree *a, t_btree *b, int childs);

/*
** Returns the result of the left/right rotation of a binary tree.
** The rotateF and rotateM functions checks if the binary tree can be rotated
** before rotating it. So if it can't be, the same binary tree is returned.
** Yes, there are cases where a binary tree cant be rotated, it happens when
** same values occur on the right branch, left rotating it could break some
** rules.
*/

t_btree				*ft_btree_leftrotate(t_btree *bt);
t_btree				*ft_btree_rightrotate(t_btree *bt);
t_btree				*ft_btree_leftrotatef(t_btree *bt, t_cmpfunc cmp);
t_btree				*ft_btree_rightrotatef(t_btree *bt, t_cmpfunc cmp);
t_btree				*ft_btree_leftrotatem(t_btree *bt,
										size_t start,
										size_t len);
t_btree				*ft_btree_rightrotatem(t_btree *bt,
										size_t start,
										size_t len);

/*
** Balances the tree in AVL mode, it simply perform rotations until both, left
** and right branches have an equal depth.
*/

t_btree				*ft_btree_balance(t_btree *bt);
t_btree				*ft_btree_balancef(t_btree *bt, t_cmpfunc cmp);
t_btree				*ft_btree_balancem(t_btree *bt, size_t start, size_t len);

/*
** Returns the number of nodes.
** Returns the maximum depth.
** Print a binary tree.
*/

size_t				ft_btree_size(t_btree *bt);
size_t				ft_btree_depth(t_btree *bt);
void				ft_btree_dump(t_btree *bt);
void				ft_btree_dumpf(t_btree *bt, void (*f)(t_btree *));

/*
** Move a node and his childs, this function is used in SPLAY functions.
** Set the given node as an individual node.
*/

t_btree				*ft_btree_move(t_btree *bt, t_btree *elem);
t_btree				*ft_btree_disconnect(t_btree *bt);

#endif
