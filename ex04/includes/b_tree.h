#ifndef B_TREE_H
# define B_TREE_H

#include <cstdlib>
#include <iostream>

typedef enum {
	RED,
	BLACK
}	t_color;

class RBTree
{
public:
	t_color	color;
	void	*data;
	RBTree	*left;
	RBTree	*right;
	RBTree	*parent;

	RBTree(void);
	RBTree(void *data);
	RBTree			*uncle(void);
	RBTree			*grandparent(void);

	static void		print(RBTree *root, size_t indent = 0);
	static size_t	height(RBTree *root);

	static void		swap_color(RBTree *node1, RBTree *node2);
	static void		swap_color(RBTree *root);
	static void		insert(RBTree **root, void *data, int (*cmp)(void *, void *));
	static void		rotation_left(RBTree **root);
	static void		rotation_right(RBTree **root);

	static void		prefix_traversar(RBTree *root, void (*f)(void *)); // прямой обход дерева
	static void		infix_traversar(RBTree *root, void (*f)(void *)); // симметричный обход дерева
	static void		suffix_traversar(RBTree *root, void (*f)(void *)); // обратный обход дерева
	static void		BFS_traversar(RBTree *root, void (*f)(void *)); // обратный обход дерева
};

#endif // B_TREE_H
