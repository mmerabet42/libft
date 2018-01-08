#include "ft_btree.h"

static void	inner_btree_lov(t_btree *bt, void (*f)(t_btree *), int n, int m)
{
	if (!bt)
		return ;
	if (n == m)
		return (f(bt));
	inner_btree_lov(bt->right, f, n + 1, m);
	inner_btree_lov(bt->left, f, n + 1, m);
}

static void	ft_btree_levelorderv(t_btree *bt, void (*f)(t_btree *))
{
	int	n;
	int	i;

	n = ft_btree_depth(bt);
	i = 0;
	while (i < n)
		inner_btree_lov(bt, f, 0, i++);
}

void		ft_btree_itermv(t_btree *bt, void (*f)(t_btree *), t_btmode mode)
{
	if (!bt || !f)
		return ;
	if (mode == BT_LEVELORDER)
		return (ft_btree_levelorderv(bt, f));
	if (mode == BT_PREORDER)
		f(bt);
	ft_btree_itermv(bt->right, f, mode);
	if (mode == BT_INORDER)
		f(bt);
	ft_btree_itermv(bt->left, f, mode);
	if (mode == BT_POSTORDER)
		f(bt);
}

void		ft_btree_iterv(t_btree *bt, void (*f)(t_btree *))
{
	ft_btree_itermv(bt, f, BT_INORDER);
}
