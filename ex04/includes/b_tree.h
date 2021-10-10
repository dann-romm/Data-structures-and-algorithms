#ifndef B_TREE_H
# define B_TREE_H

#include <cstdlib>

class RBTree
{
private:
	bool	color; // 0 - black, 1 - red
	void	*data;
	RBTree	*left;
	RBTree	*right;
	RBTree	*parent;

public:
	RBTree(void *data);
	RBTree		*empty_node(void);
	// void		insert(void *data);
	static void	prefix_traversar(RBTree *root, void (*f)(void *)); // прямой обход дерева
	static void	infix_traversar(RBTree *root, void (*f)(void *)); // симметричный обход дерева
	static void	suffix_traversar(RBTree *root, void (*f)(void *)); // обратный обход дерева
};

#endif // B_TREE_H