#ifndef B_TREE_H
# define B_TREE_H

# include <cstdlib>
# include <iostream>

typedef enum {
	RED,
	BLACK
}	t_color;

class RBTree
{
private:
	t_color	color;
	void	*data;
	RBTree	*left;
	RBTree	*right;
	RBTree	*parent;
	static void		rotation_left(RBTree **root); // малый левый поворот
	static void		rotation_right(RBTree **root); // малый правый поворот
	static void		swap_color(RBTree *node1, RBTree *node2); // обмен цветами между двумя узлами
	static void		swap_color(RBTree *root); // операция изменения цвета при двух красных братьях
public:

	RBTree(void);
	RBTree(void *data);

	void				print(size_t indent = 0); // вывод дерева
	unsigned short int	height(void); // высота дерева
	unsigned short int	height_black(void); // чёрная высота дерева
	unsigned int		count(void); // подсчёт количества узлов дерева
	double				sum_data(void); // сумма значений всех листьев
	double				avg_data(void); // среднее арифметическое значений всех листьев

	static void			insert(RBTree **root, void *data, int (*cmp)(void *, void *)); // вставка элемента
	static void			clear(RBTree **root); // очистка дерева и удаление всех элементов

	void				prefix_traversar(void (*f)(void *)); // прямой обход дерева
	void				infix_traversar(void (*f)(void *)); // симметричный обход дерева
	void				suffix_traversar(void (*f)(void *)); // обратный обход дерева
	void				BFS_traversar(void (*f)(void *)); // обход дерева в ширину
};

#endif // B_TREE_H
