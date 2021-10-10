#include "../includes/b_tree.h"

RBTree::RBTree(void *data)
{
	this->left = this->empty_node();
	this->right = this->empty_node();
	this->left->parent = this;
	this->right->parent = this;
	this->parent = nullptr;
	this->color = 0; // black
	this->data = data;
}

RBTree	*RBTree::empty_node(void)
{
	RBTree	*node = (RBTree *) malloc(sizeof(RBTree));
	if (!node)
		return (nullptr);
	node->left = nullptr;
	node->right = nullptr;
	node->parent = nullptr;
	node->data = nullptr; // or 0.0
	node->color = 0; // black
	return (node);
}

void	RBTree::prefix_traversar(RBTree *root, void (*f)(void *))
{
	if (!root)
		return ;
	(*f)(root->data);
	RBTree::infix_traversar(root->right, f);
	RBTree::infix_traversar(root->left, f);
}

void	RBTree::infix_traversar(RBTree *root, void (*f)(void *))
{
	if (!root)
		return ;
	RBTree::infix_traversar(root->right, f);
	(*f)(root->data);
	RBTree::infix_traversar(root->left, f);
}

void	RBTree::suffix_traversar(RBTree *root, void (*f)(void *))
{
	if (!root)
		return ;
	RBTree::infix_traversar(root->right, f);
	RBTree::infix_traversar(root->left, f);
	(*f)(root->data);
}
