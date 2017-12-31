#include "ft_btree.h"

static t_btree	*btree_atlevel(t_btree *bt, void (*f)(t_btree *), int level)
{
	int	i;

	i = 0;
}

static void		ft_btree_breadthfirst(t_btree *bt, void (*f)(t_btree *))
{
	
}

void			ft_btree_iter(t_btree *bt, void (*f)(t_btree *), int mode)
{
	if (!bt || !f)
		return ;
	if (mode == BT_BREADTHFIRST)
		return (ft_btree_breadthfirst(bt, f));
	if (mode == BT_PREORDER)
		f(bt);
	ft_btree_iter(bt->left, f, mode);
	if (mode == BT_INORDER)
		f(bt);
	ft_btree_iter(bt->right, f, mode);
	if (mode == BT_POSTORDER)
		f(bt);
}
