#include "../includes/main.h"

void	print(void *p)
{
	if (p == nullptr)
		return ;
	std::cout << *((double *) p);
}

int	main(void)
{
	RBTree	*tree;
	double	nbr;

	nbr = 0.125;
	tree = new RBTree((void *) &nbr);
	RBTree::infix_traversar(tree, print);
}
