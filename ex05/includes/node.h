#ifndef NODE_H
# define NODE_H

# include <vector>

class	Node
{
public:
	Node(size_t key);

	std::vector<size_t>		*v;
	size_t					key;
};

#endif // NODE_H
