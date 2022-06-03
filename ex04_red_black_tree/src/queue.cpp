#include "../includes/queue.h"

Queue::Queue(void) {
	this->next = nullptr;
	this->prev = nullptr;
	this->data = nullptr;
}

void	Queue::push(Queue **head, void *data)
{
	Queue	*node;

	if (!head)
		return ;
	node = new Queue();
	node->next = *head;
	if (*head)
	{
		node->prev = (*head)->prev;
		(*head)->prev = node;
	}
	else
		node->prev = node;
	node->data = data;
	*head = node;
}

void	*Queue::pop(Queue **head)
{
	Queue	*node;
	void	*data;
	
	if (!head || !(*head))
		return (nullptr);
	node = *head;
	if (!((*head)->next))
	{
		*head = nullptr;
		return (node->data);
	}
	while (node->next->next)
		node = node->next;
	data = node->next->data;
	node->next = nullptr;
	return (data);
}

void	Queue::right_traversar(void (*f)(void *))
{
	Queue	*node;

	node = this;
	while (node)
	{
		(*f)(node->data);
		node = node->next;
	}
}

void	Queue::reverse_traversar(void (*f)(void *))
{
	Queue	*node;

	node = this->prev;
	while (node != this)
	{
		(*f)(node->data);
		node = node->prev;
	}
	(*f)(this->data);
}
