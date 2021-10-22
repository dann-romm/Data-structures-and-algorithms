#ifndef GRAPH_H
# define GRAPH_H

# include <vector>

# include "../includes/node.h"

class Graph
{
public:
	vector<vector<int>>	*e;
	size_t				vertex;
	size_t				edges;

	Graph(void);
	void		add(size_t src, size_t dst, int weight);
	vector<int>	*Bellman_Ford();
};

#endif // GRAPH_H
