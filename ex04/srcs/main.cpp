#include "../includes/main.h"

void	print(void *p)
{
	if (p == nullptr)
		std::cout << "(null)\n";
	else
		std::cout << *((double *) p) << "\n";
}

int		doublecmp(void *a, void *b)
{
	if ((*(double *)a > *(double *)b))
		return (1);
	return (-1);
}

int	main(void)
{
	double	nbr1 = 11.5;
	double	nbr2 = 22.5;
	double	nbr3 = 33.5;
	double	nbr4 = 44.5;
	double	nbr5 = 55.5;
	double	nbr6 = 66.5;
	double	nbr7 = 77.5;
	double	nbr8 = 88.5;
	double	nbr9 = 99.5;

	RBTree	*tree;
	tree = nullptr;

	// tree = new RBTree((void *) &nbr1);
	// tree->left = new RBTree((void *) &nbr2);
	// tree->right = new RBTree((void *) &nbr3);
	// tree->left->left = new RBTree((void *) &nbr4);
	// tree->left->right = new RBTree((void *) &nbr5);
	// tree->right->left = new RBTree((void *) &nbr6);
	// tree->right->right = new RBTree((void *) &nbr7);
	// tree->left->left->left = new RBTree((void *) &nbr8);
	// tree->left->left->right = new RBTree((void *) &nbr9);

	RBTree::insert(&tree, (void *) &nbr6, doublecmp);
	RBTree::insert(&tree, (void *) &nbr4, doublecmp);
	RBTree::insert(&tree, (void *) &nbr2, doublecmp);
	RBTree::insert(&tree, (void *) &nbr5, doublecmp);
	RBTree::insert(&tree, (void *) &nbr1, doublecmp);
	RBTree::insert(&tree, (void *) &nbr3, doublecmp);
	RBTree::insert(&tree, (void *) &nbr8, doublecmp);
	RBTree::insert(&tree, (void *) &nbr7, doublecmp);
	RBTree::insert(&tree, (void *) &nbr9, doublecmp);
	// std::cout << RBTree::height(tree);
	RBTree::print(tree, 0);
}
