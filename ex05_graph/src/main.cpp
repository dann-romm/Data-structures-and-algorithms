#include "../includes/main.h"

void	fill_stdin(Graph **graph);
// void	fill_variant(Graph **graph);

int		main(void)
{
	int		choice;
	int		temp;
	Graph	*graph;

	graph = nullptr;
	std::cout << "меню\n";
	std::cout << "0 - завершение программы\n";
	std::cout << "1 - вывод графа на экран\n";
	std::cout << "2 - очистка графа\n";
	std::cout << "3 - ввод элементов графа\n";
	std::cout << "4 - найти кратчайшие пути от вершины с помощью алгоритма Беллмана-Форда\n";

	while (1)
	{
		std::cout << "ожидание выбора: ";
		std::cin >> choice;
		switch (choice)
		{
			case (0):
				delete graph;
				return (0);
			case (1):
				if (!graph)
					std::cout << "граф не инициализирован\n";
				else
					graph->print();
				break;
			case (2):
				delete graph;
				graph = nullptr;
				break;
			case (3):
				fill_stdin(&graph);
				break;
			case (4):
				if (!graph)
				{
					std::cout << "граф не инициализирован\n";
					break ;
				}
				std::cout << "введите начальную вершину для отсчёта: ";
				std::cin >> temp;
				graph->Bellman_Ford(temp);
			default:
				break;
		}
	}
}

void	fill_stdin(Graph **graph)
{
	int	a, b, c;
	int	temp;

	delete *graph;
	temp = 0;
	while (temp < 1)
	{
		std::cout << "введите кол-во вершин графа: ";
		std::cin >> temp;
	}
	*graph = new Graph(temp);
	temp = 2;
	while (temp != 0 && temp != 1)
	{
		std::cout << "выберите тип графа:\n";
		std::cout << "0 - ориентированный\n1 - неориентированный\n";
		std::cin >> temp;
	}
	std::cout << "ввод ребёр в формате: (вершина1) (вершина2) (вес)\n";
	std::cout << "завершится при вводе 0 0 0\n";
	while (1)
	{
		std::cin >> a >> b >> c;
		if (!a && !b && !c)
			break ;
		(*graph)->add(a, b, c);
		if (temp)
			(*graph)->add(b, a, c);
	}
}

// void	fill_variant(Graph **graph)
// {
// 	(*graph)->add(0, 1, 23);
// 	(*graph)->add(1, 0, 23);

// 	(*graph)->add(0, 2, 12);
// 	(*graph)->add(2, 0, 12);

// 	(*graph)->add(1, 2, 25);
// 	(*graph)->add(2, 1, 25);

// 	(*graph)->add(3, 2, 18);
// 	(*graph)->add(2, 3, 18);

// 	(*graph)->add(3, 5, 20);
// 	(*graph)->add(5, 3, 20);

// 	(*graph)->add(1, 4, 22);
// 	(*graph)->add(4, 1, 22);

// 	(*graph)->add(5, 4, 23);
// 	(*graph)->add(4, 5, 23);

// 	(*graph)->add(6, 4, 14);
// 	(*graph)->add(4, 6, 14);

// 	(*graph)->add(5, 6, 24);
// 	(*graph)->add(6, 5, 24);

// 	(*graph)->add(1, 7, 35);
// 	(*graph)->add(7, 1, 35);

// 	(*graph)->add(6, 7, 16);
// 	(*graph)->add(7, 6, 16);
// }
