#include "ft_btree.h"

static void		inner_btree_bf(t_btree *bt, void (*f)(t_btree *), int n, int m)
{
	if (!bt)
		return ;
	if (n == m)
	{
		f(bt);
		return ;
	}
	inner_btree_bf(bt->left, f, n + 1, m);
	inner_btree_bf(bt->right, f, n + 1, m);
}

static void		ft_btree_breadthfirst(t_btree *bt, void (*f)(t_btree *))
{
	int	n;
	int	i;

	n = ft_btree_depth(bt);
	i = 0;
	while (i < n)
		inner_btree_bf(bt, f, 0, i++);
}

void			ft_btree_iter(t_btree *bt, void (*f)(t_btree *), t_btmode mode)
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
