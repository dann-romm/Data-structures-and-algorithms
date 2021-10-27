#include "../includes/main.h"

void	print(void *p)
{
	if (p == nullptr)
		std::cout << "(null)\n";
	else
		std::cout << *((double *) p) << "\n";
}

int		cmp_double(void *a, void *b)
{
	return (ceil(*(double *)a - *(double *)b));
}

void	fill_rand(RBTree **root, double arr[], size_t len)
{
	double	temp;
	srand(time(0));

	for (size_t i = 0; i < len; i++)
	{
		temp = ((double) rand() / (RAND_MAX)) * len;
		temp = round( temp * 100.0 ) / 100.0;
		arr[i] = temp;
	}
	for (int i = 0; i < len; i++)
		RBTree::insert(root, (void *) &arr[i], cmp_double);
}

int		main(void)
{
	double			*arr;
	short int		choice;
	short int		count;
	RBTree			*tree;

	tree = nullptr;
	arr = nullptr;

	std::cout << "меню:\n";
	std::cout << "0 - звершение программы\n";
	std::cout << "1 - вывод дерева\n";
	std::cout << "2 - очистка дерева\n";
	std::cout << "3 - ввод элементов с клавиатуры\n";
	std::cout << "4 - заполнение дерева случайными числами\n";
	std::cout << "5 - вычисление суммы всех узлов\n";
	std::cout << "6 - вычисление среднего арифметического\n";
	std::cout << "7 - прямой обход дерева\n";
	std::cout << "8 - симметричный обход дерева\n";
	std::cout << "9 - обратный обход дерева\n";
	std::cout << "10 - обход дерева в ширину\n";

	while (1)
	{
		std::cout << "ожидание выбора: ";
		std::cin >> choice;
		switch (choice)
		{
			case (0):
				if (arr)
				{
					delete arr;
					arr = nullptr;
				}
				return (0);
			case (1):
				if (!tree)
					std::cout << "дерево не инициализировано\n";
				else
					tree->print();
				break;
			case (2):
				if (arr)
				{
					delete arr;
					arr = nullptr;
				}
				RBTree::clear(&tree);
				break;
			case (3):
				count = 0;
				while (count < 1)
				{
					std::cout << "введите кол-во элементов: ";
					std::cin >> count;
				}
				if (arr)
				{
					delete arr;
					arr = nullptr;
				}
				RBTree::clear(&tree);
				arr = new double[count];
				for (short int i = 0; i < count; i++)
				{
					std::cin >> arr[i];
					RBTree::insert(&tree, (void *) &arr[i], cmp_double);
				}
				break;
			case (4):
				count = 0;
				while (count < 1)
				{
					std::cout << "введите кол-во элементов: ";
					std::cin >> count;
				}
				if (arr)
				{
					delete arr;
					arr = nullptr;
				}
				RBTree::clear(&tree);
				arr = new double[count];
				fill_rand(&tree, arr, count);
				break;
			case (5):
				std::cout << tree->sum_data() << "\n";
				break;
			case (6):
				std::cout << tree->avg_data() << "\n";
				break;
			case (7):
				tree->prefix_traversar(print);
				break;
			case (8):
				tree->infix_traversar(print);
				break;
			case (9):
				tree->suffix_traversar(print);
				break;
			case (10):
				tree->BFS_traversar(print);
				break;
			default:
				break;
		}
	}
}
