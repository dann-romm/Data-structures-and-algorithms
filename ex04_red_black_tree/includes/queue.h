#ifndef QUEUE_H
# define QUEUE_H

class Queue
{
public:
	Queue	*next;
	Queue	*prev;
	void	*data;

	Queue(void);
	static void	push(Queue **head, void *data);
	static void	*pop(Queue **head);
	void		right_traversar(void (*f)(void *));
	void		reverse_traversar(void (*f)(void *));
};

#endif //QUEUE_H
