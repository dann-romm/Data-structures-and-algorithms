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
	double	nbr01 = 11.5;
	double	nbr02 = 22.5;
	double	nbr03 = 33.5;
	double	nbr04 = 44.5;
	double	nbr05 = 55.5;
	double	nbr06 = 66.5;
	double	nbr07 = 77.5;
	double	nbr08 = 88.5;
	double	nbr09 = 99.5;
	double	nbr10 = 100.5;
	double	nbr11 = 110.5;
	double	nbr12 = 120.5;
	double	nbr13 = 130.5;
	double	nbr14 = 140.5;
	double	nbr15 = 150.5;
	double	nbr16 = 160.5;

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

	// RBTree::insert(&tree, (void *) &nbr08, doublecmp);
	// RBTree::insert(&tree, (void *) &nbr04, doublecmp);
	// RBTree::insert(&tree, (void *) &nbr02, doublecmp);
	// RBTree::insert(&tree, (void *) &nbr01, doublecmp);
	// RBTree::insert(&tree, (void *) &nbr03, doublecmp);
	// RBTree::insert(&tree, (void *) &nbr06, doublecmp);
	// RBTree::insert(&tree, (void *) &nbr05, doublecmp);
	// RBTree::insert(&tree, (void *) &nbr07, doublecmp);
	// RBTree::insert(&tree, (void *) &nbr12, doublecmp);
	// RBTree::insert(&tree, (void *) &nbr10, doublecmp);
	// RBTree::insert(&tree, (void *) &nbr09, doublecmp);
	// RBTree::insert(&tree, (void *) &nbr11, doublecmp);
	// RBTree::insert(&tree, (void *) &nbr14, doublecmp);
	// RBTree::insert(&tree, (void *) &nbr13, doublecmp);
	// RBTree::insert(&tree, (void *) &nbr15, doublecmp);

	RBTree::insert(&tree, (void *) &nbr06, doublecmp);
	RBTree::insert(&(tree->left), (void *) &nbr03, doublecmp);
	// RBTree::insert(&tree, (void *) &nbr01, doublecmp);

	// std::cout << RBTree::height(tree);
	RBTree::print(tree, 0);
	std::cout << "<===========================================>\n";
	// RBTree::rotation_left(&(tree));
	// RBTree::rotation_right(&(tree->right));
	// RBTree::print(tree, 0);
}
