#ifndef GRAPH_H
# define GRAPH_H

# include <iostream>
# include <vector>
# include <deque>
# include <set>

class Graph
{
private:
	size_t				size;
	std::vector<int>	e[3];

public:
	Graph(size_t size = 0);
	~Graph(void);

	void	add(int src, int dst, int weight);
	void	Bellman_Ford(int start = 0);
	void	BFS_traversar(void (*f)(int), int start = 0);
	void	print(void);
	void	clear(void);
};

#endif // GRAPH_H
