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
	RBTree::prefix_traversar(root->left, f);
	RBTree::prefix_traversar(root->right, f);
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
	RBTree::suffix_traversar(root->left, f);
	RBTree::suffix_traversar(root->right, f);
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
	for (int i = 0; i < indent * 2; i++)
		std::cout << "\t";
	if (root->color == BLACK)
		std::cout << *(double *)(root->data) << "(B)";
	else
		std::cout << *(double *)(root->data) << "(R)";



	if (root->parent)
		std::cout << "(" << *(double *)(root->parent->data) << ")";
	else
		std::cout << "(null)";



	std::cout << "\n";
	RBTree::print(root->left, indent + 1);
}

size_t	RBTree::height(RBTree *root)
{
	if (!root || root == leaf)
		return (0);
	return (std::max(RBTree::height(root->left), RBTree::height(root->right)) + 1);
}

void	RBTree::swap_color(RBTree *node1, RBTree *node2)
{
	t_color color;

	if (!node1 || !node2 || node1 == leaf || node2 == leaf)
		return ;
	color = node1->color;
	node1->color = node2->color;
	node2->color = color;
}

void	RBTree::rotation_left(RBTree **root)
{
	RBTree	*node;

	if (!root || !(*root) || (*root)->left == leaf || (*root)->right == leaf)
		return ;
	RBTree::swap_color((*root), (*root)->right);
	node = (*root)->right;
	(*root)->right = node->left;
	(*root)->right->parent = (*root);
	node->left = (*root);
	if ((*root)->parent && (*root)->parent->left == (*root))
		(*root)->parent->left = node;
	else if ((*root)->parent)
		(*root)->parent->right = node;
	node->parent = (*root)->parent;
	(*root)->parent = node;
	(*root) = node;
}

void	RBTree::rotation_right(RBTree **root)
{
	RBTree	*node;

	if (!root || !(*root) || (*root)->left == leaf || (*root)->right == leaf)
		return ;
	RBTree::swap_color((*root), (*root)->left);
	node = (*root)->left;
	(*root)->left = node->right;
	(*root)->left->parent = (*root);
	node->right = (*root);
	if ((*root)->parent && (*root)->parent->left == (*root))
		(*root)->parent->left = node;
	else if ((*root)->parent)
		(*root)->parent->right = node;
	node->parent = (*root)->parent;
	(*root)->parent = node;
	(*root) = node;
}

void	RBTree::insert(RBTree **root, void *data, int (*cmp)(void *, void *))
{
	RBTree	*new_node;
	RBTree	*node1;
	RBTree	*node2;

	if (!root)
		return ;
	new_node = new RBTree(data);
	if (!(*root))
	{
		*root = new_node;
		return ;
	}
	new_node->color = RED;
	node1 = *root;
	while (node1 != leaf)
	{
		node2 = node1;
		if ((*cmp)(node1->data, data) > 0)
			node1 = node1->left;
		else
			node1 = node1->right;
	}
	new_node->parent = node2;
	if ((*cmp)(node2->data, data) > 0)
		node2->left = new_node;
	else
		node2->right = new_node;

	// TODO: rebalancing
}