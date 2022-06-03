#include "../includes/graph.h"

Graph::Graph(size_t size)
{
	this->size = size;
}

Graph::~Graph(void)
{
	this->clear();
}

void	Graph::add(int src, int dst, int weight)
{
	if (src == dst || src < 0 || dst < 0 || src >= this->size || dst >= this->size)
	{
		std::cout << "error: wrong add vertex\n";
		return ;
	}
	(this->e[0]).push_back(src);
	(this->e[1]).push_back(dst);
	(this->e[2]).push_back(weight);
}

void	Graph::Bellman_Ford(int	start)
{
	int	dist[this->size];

	if (start < 0 || start >= this->size)
	{
		std::cout << "error: wrong start vertex\n";
		return ;
	}
	for (int i = 0; i < this->size; i++)
		dist[i] = INT_MAX;
	dist[start] = 0;
	
	for (int i = 1; i < this->size; i++)
	{
		for (int j = 0; j < this->e[0].size(); j++)
		{
			if (dist[this->e[1][j]] > dist[this->e[0][j]] + this->e[2][j]
				&& dist[this->e[0][j]] != INT_MAX)
				dist[this->e[1][j]] = dist[this->e[0][j]] + this->e[2][j];
		}
	}

	for (int j = 0; j < this->e[0].size(); j++)
	{
		if (dist[this->e[1][j]] > dist[this->e[0][j]] + this->e[2][j]
			&& dist[this->e[0][j]] != INT_MAX)
		{
			std::cout << "error: negative loop in graph\n";
			return ;
		}
	}

	for (int i = 0; i < this->size; i++)
	{
		std::cout << "кратчайшее расстояние от (" << start << ") до (";
		std::cout << i << ") = " << dist[i] << "\n";
	}
}

void	Graph::BFS_traversar(void (*f)(int), int start)
{
	std::deque<int>		queue;
	int					vertex;
	std::set<int>		visited;

	if (start < 0 || start >= this->size)
	{
		std::cout << "error: wrong start vertex\n";
		return ;
	}
	queue.push_front(start);
	visited.insert(start);
	while (!queue.empty())
	{
		vertex = queue.back();
		queue.pop_back();
		(*f)(vertex);
		for (int i = 0; i < (this->e[0]).size(); i++)
		{
			if ((this->e[0])[i] == vertex && !visited.contains((this->e[1])[i]))
			{
				visited.insert((this->e[1])[i]);
				queue.push_front((this->e[1])[i]);
			}
		}
	}
}

void	Graph::print(void)
{
	if (this->size == 0)
	{
		std::cout << "empty graph\n";
		return ;
	}

	auto	print
	{
		[](int a) { std::cout << a << "\n"; }
	};
	this->BFS_traversar(print);
}

void	Graph::clear(void)
{
	(this->e[0]).clear();
	(this->e[1]).clear();
	(this->e[2]).clear();
	this->size = 0;
}