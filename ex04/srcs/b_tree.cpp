#include "../includes/b_tree.h"
#include "../includes/queue.h"

static RBTree	*leaf = new RBTree();

RBTree::RBTree(void)
{
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
	this->color = BLACK;
	this->data = nullptr;
}

RBTree::RBTree(void *data)
{
	this->left = leaf;
	this->right = leaf;
	this->parent = nullptr;
	this->color = BLACK;
	this->data = data;
}

RBTree	*RBTree::grandparent(void)
{
	if (this->parent)
		return (this->parent->parent);
	return (nullptr);
}

RBTree	*RBTree::uncle(void)
{
	RBTree	*gp;

	gp = this->grandparent();
	if (!gp)
		return (nullptr);
	if (gp->left == this)
		return (gp->right);
	return (gp->left);
}

void	RBTree::prefix_traversar(RBTree *root, void (*f)(void *))
{
	if (!root || root == leaf)
		return ;
	(*f)(root->data);
	RBTree::infix_traversar(root->left, f);
	RBTree::infix_traversar(root->right, f);
}

void	RBTree::infix_traversar(RBTree *root, void (*f)(void *))
{
	if (!root || root == leaf)
		return ;
	RBTree::infix_traversar(root->left, f);
	(*f)(root->data);
	RBTree::infix_traversar(root->right, f);
}

void	RBTree::suffix_traversar(RBTree *root, void (*f)(void *))
{
	if (!root || root == leaf)
		return ;
	RBTree::infix_traversar(root->left, f);
	RBTree::infix_traversar(root->right, f);
	(*f)(root->data);
}

void	RBTree::BFS_traversar(RBTree *root, void (*f)(void *))
{
	Queue	*queue;
	RBTree	*node;

	if (!root)
		return ;
	queue = nullptr;
	Queue::push(&queue, root);
	while (queue)
	{
		node = (RBTree *) Queue::pop(&queue);
		(*f)(node->data);
		if (node->left != leaf)
			Queue::push(&queue, (void *)(node->left));
		if (node->right != leaf)
			Queue::push(&queue, (void *)(node->right));
	}
}

void	RBTree::print(RBTree *root, size_t indent)
{
	if (!root || root == leaf)
		return ;
	RBTree::print(root->right, indent + 1);
	for (int i = 0; i < indent; i++)
		std::cout << "\t";
	// std::cout << *(double *)(root->data) << "\n";
	if (root->color == BLACK)
		std::cout << *(double *)(root->data) << "(B)\n";
	else
		std::cout << *(double *)(root->data) << "(R)\n";
	RBTree::print(root->left, indent + 1);
}

size_t	RBTree::height(RBTree *root)
{
	if (!root || root == leaf)
		return (0);
	return (std::max(RBTree::height(root->left), RBTree::height(root->right)) + 1);
}

void	RBTree::insert(RBTree **root, void *data, int (*cmp)(void *, void *))
{
	RBTree	*new_node;
	RBTree	*node;

	if (!root)
		return ;
	new_node = new RBTree(data);
	if (!(*root))
	{
		*root = new_node;
		return ;
	}

	node = *root;
	while (node != leaf && (node->left != leaf || node->right != leaf))
	{
		if ((*cmp)(node->data, data) > 0)
		{
			if (node->left == leaf)
				break ;
			node = node->left;
		}
		else
		{
			if (node->right == leaf)
				break ;
			node = node->right;
		}
	}
	if ((*cmp)(node->data, data) > 0)
		node->left = new_node;
	else
		node->right = new_node;
	new_node->parent = node;

	// TODO: rebalancing
}