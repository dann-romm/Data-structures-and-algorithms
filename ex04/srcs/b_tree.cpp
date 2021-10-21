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
	this->color = RED;
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

void	RBTree::swap_color(RBTree *root)
{
	if (!root || root == leaf)
		return ;
	if (root->left->color == RED && root->right->color == RED)
	{
		root->left->color = BLACK;
		root->right->color = BLACK;
		root->color = RED;
	}
}

// void	print_node(RBTree *node, int ifchilds = 1)
// {
// 	if (node && node != leaf)
// 	{
// 		std::cout << "data: " << *(double *) (node->data) << "\tparent: ";
// 		if (node->parent)
// 			std::cout << *(double *) (node->parent->data);
// 		else
// 			std::cout << "(null)";
		
// 		if (ifchilds)
// 		{
// 			if (node->left != leaf)
// 			{
// 				std::cout << "\tleft: " << *(double *) (node->left->data);
// 				std::cout << "\tright: " << *(double *) (node->right->data);
// 			}
// 			else
// 				std::cout << "\tleft: (leaf)\tright: (leaf)";
// 		}
// 		std::cout << "\n";
// 	}
// }

void	RBTree::rotation_left(RBTree **root)
{
	RBTree	*node1;
	RBTree	*node2;

	if (!root || !(*root) || (*root)->left == leaf || (*root)->right == leaf)
		return ;
	node1 = (*root);
	node2 = (*root)->right;
	RBTree::swap_color(node1, node2);
	if (!(node1->parent))
		(*root) = node2;
	else
	{
		if (node1->parent->left == node1)
			node1->parent->left = node2;
		else
			node1->parent->right = node2;
	}
	node2->parent = node1->parent;
	node1->parent = node2;
	node1->right = node2->left;
	node2->left->parent = node1;
	node2->left = node1;
}

void	RBTree::rotation_right(RBTree **root)
{
	RBTree	*node1;
	RBTree	*node2;

	if (!root || !(*root) || (*root)->left == leaf || (*root)->right == leaf)
		return ;
	node1 = (*root);
	node2 = (*root)->left;
	RBTree::swap_color(node1, node2);
	if (!(node1->parent))
		(*root) = node2;
	else
	{
		if (node1->parent->left == node1)
			node1->parent->left = node2;
		else
			node1->parent->right = node2;
	}
	node2->parent = node1->parent;
	node1->parent = node2;
	node1->left = node2->right;
	node2->right->parent = node1;
	node2->right = node1;
}

// void	RBTree::rotation(RBTree **root, int direction)
// {
// 	if (direction)
// 		RBTree::rotation_left(root);
// 	else
// 		RBTree::rotation_right(root);
// }

void	RBTree::insert(RBTree **root, void *data, int (*cmp)(void *, void *))
{
	RBTree	*new_node;

	if (!root)
		return ;
	if (!(*root))
	{
		*root = new RBTree(data);
		(*root)->color = BLACK;
		return ;
	}
	
	if ((*cmp)(data, (*root)->data) > 0)
	{
		if ((*root)->left == leaf)
		{
			new_node = new RBTree(data);
			new_node->parent = *root;
		}
		else
			RBTree::insert(&((*root)->left), data, cmp);
	}
	else
	{
		if ((*root)->right == leaf)
		{
			new_node = new RBTree(data);
			new_node->parent = *root;
		}
		else
			RBTree::insert(&((*root)->left), data, cmp);
	}
	
	// RBTree	*new_node;
	// RBTree	*node1;
	// RBTree	*node2;

	// if (!root)
	// 	return ;
	// RBTree	*new_node;
	// new_node = new RBTree(data);
	// if (!(*root))
	// {
	// 	*root = new_node;
	// 	return ;
	// }
	// new_node->color = RED;
	// node1 = *root;
	// while (node1 != leaf)
	// {
	// 	node2 = node1;
	// 	if ((*cmp)(node1->data, data) > 0)
	// 		node1 = node1->left;
	// 	else
	// 		node1 = node1->right;
	// }
	// new_node->parent = node2;
	// if ((*cmp)(node2->data, data) > 0)
	// 	node2->left = new_node;
	// else
	// 	node2->right = new_node;
}