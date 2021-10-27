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

void	RBTree::prefix_traversar(void (*f)(void *))
{
	if (this == leaf)
		return ;
	(*f)(this->data);
	this->left->prefix_traversar(f);
	this->right->prefix_traversar(f);
}

void	RBTree::infix_traversar(void (*f)(void *))
{
	if (this == leaf)
		return ;
	this->left->infix_traversar(f);
	(*f)(this->data);
	this->right->infix_traversar(f);
}

void	RBTree::suffix_traversar(void (*f)(void *))
{
	if (this == leaf)
		return ;
	this->left->suffix_traversar(f);
	this->right->suffix_traversar(f);
	(*f)(this->data);
}

void	RBTree::BFS_traversar(void (*f)(void *))
{
	Queue	*queue;
	RBTree	*node;

	queue = nullptr;
	Queue::push(&queue, this);
	while (queue)
	{
		node = (RBTree *) Queue::pop(&queue);
		(*f)(node->data);
		if (node->left != leaf)
			Queue::push(&queue, (void *)(node->left));
		if (node->right != leaf)
			Queue::push(&queue, (void *)(node->right));
	}
	delete queue;
}

double	RBTree::sum_data(void)
{
	if (this == leaf)
		return (0);
	return (*(double *)(this->data) +
		this->left->sum_data() + this->right->sum_data());
}

unsigned int	RBTree::count(void)
{
	if (this == leaf)
		return (0);
	return (this->left->count() + this->right->count() + 1);
}

// double	RBTree::avg_data(void)
// {
// 	static unsigned int	count = 0;
// 	static double		sum = 0;

// 	if (this == leaf)
// 		return (0);
// 	if (!(this->parent))
// 	{
// 		count = 0;
// 		sum = 0;
// 	}
// 	sum += this->left->avg_data();
// 	sum += this->right->avg_data();
// 	count++;
// 	if (!(this->parent))
// 		return ((*(double *)(this->data) + sum) / count);
// 	return (*(double *)(this->data));
// }

double	RBTree::avg_data(void)
{
	return (this->sum_data() / this->count());
}

void	RBTree::print(size_t indent)
{
	if (this == leaf)
		return ;
	this->right->print(indent + 1);
	for (int i = 0; i < indent * 2; i++)
		std::cout << "\t";
	if (this->color == BLACK)
		std::cout << *(double *)(this->data) << "(B)";
	else
		std::cout << *(double *)(this->data) << "(R)";
	// if (this->parent)
	// 	std::cout << "(" << *(double *)(this->parent->data) << ")";
	// else
	// 	std::cout << "(null)";
	std::cout << "\n";
	this->left->print(indent + 1);
}

unsigned short int	RBTree::height(void)
{
	if (this == leaf)
		return (0);
	return (1 +
		std::max( this->left->height(), this->right->height() ));
}

unsigned short int	RBTree::height_black(void)
{
	if (this == leaf)
		return (0);
	return ((this->color == BLACK) + this->left->height_black());
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
	root->left->color = BLACK;
	root->right->color = BLACK;
	root->color = RED;
}

void	RBTree::rotation_left(RBTree **root)
{
	RBTree	*node1;
	RBTree	*node2;

	if (!root || !(*root))
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

	if (!root || !(*root))
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
		if ((*root)->right == leaf)
		{
			new_node = new RBTree(data);
			new_node->parent = *root;
			(*root)->right = new_node;
		}
		else
			RBTree::insert(&((*root)->right), data, cmp);
	}
	else
	{
		if ((*root)->left == leaf)
		{
			new_node = new RBTree(data);
			new_node->parent = *root;
			(*root)->left = new_node;
		}
		else
			RBTree::insert(&((*root)->left), data, cmp);
	}

	if ((*root)->right->color == RED && (*root)->left->color == BLACK)
		RBTree::rotation_left(root);
	if ((*root)->left->color == RED && (*root)->left->left->color == RED)
		RBTree::rotation_right(root);
	if ((*root)->right->color == RED && (*root)->left->color == RED)
		RBTree::swap_color(*root);

	if (!((*root)->parent))
		(*root)->color = BLACK;
}

void	RBTree::clear(RBTree **root)
{
	if (!root || !(*root) || (*root) == leaf)
		return ;
	RBTree::clear(&((*root)->left));
	RBTree::clear(&((*root)->right));
	delete (*root);
	if (!((*root)->parent))
		(*root) = nullptr;
}
