#include <string>
#include <cmath>

#include "../includes/Hash_table.h"

List::List(void)
{
	this->next = nullptr;
	this->data = nullptr;
}

void List::push_front(List **head, Substr *data)
{
	List *node = new List();
	node->next = *head;
	node->data = data;
	*head = node;
}

void List::remove(List **head, std::string key)
{
	List *node;
	List *prev;

	if (head == nullptr || *head == nullptr)
		return ;
	node = (*head)->next;
	if ((*head)->data->get_key() == key)
	{
		delete (*head)->data;
		delete *head;
		*head = node;
		return ;
	}
	prev = *head;
	while (node != nullptr)
	{
		if (node->data->get_key() == key)
		{
			prev->next = node->next;
			delete node->data;
			delete node;
			return ;
		}
		prev = node;
		node = node->next;
	}
}

List *List::find(std::string key)
{
	List *node = this;
	while (node != nullptr)
	{
		if (node->data->get_key() == key)
			return (node);
		node = node->next;
	}
	return (nullptr);
}

Hash_table::Hash_table(unsigned int size)
{
	this->load_ratio = 0.0;
	this->size = size;
	this->table = new List *[size];
}

Hash_table::~Hash_table(void)
{
	this->clear();
}

unsigned int Hash_table::hash(std::string key)
{
	unsigned int	hash;
	int				len;
	int				b;

	b = 2;
	hash = 0;
	len = key.length();
	for (int i = 0; i < len; i++)
		hash = (hash + key[i] * (unsigned int) std::pow(b, len - i - 1)) % this->size;
	return (hash);
}

void Hash_table::insert(Substr *data)
{
	unsigned int index = this->hash(data->get_key());
	if (this->table[index] == nullptr)
		this->load_ratio += (double)1.0 / this->size;
	List::push_front(&(this->table[index]), data);
	if (this->load_ratio > Hash_table::load_ratio_limit)
		this->rehashing();
}

void Hash_table::remove(std::string key)
{
	unsigned int index = this->hash(key);
	List::remove(&((this->table)[index]), key);
	if ((this->table)[index] == nullptr)
		this->load_ratio -= (double)1.0 / this->size;
}

Substr *Hash_table::find(std::string key)
{
	unsigned int index = this->hash(key);
	List *node = ((this->table)[index])->find(key);
	if (node != nullptr)
		return (node->data);
	return (nullptr);
}

void Hash_table::print(void)
{
	List *node;

	std::cout << "load ratio = " << this->load_ratio << "\n";

	for (int i = 0; i < this->size; i++)
	{
		std::cout << "table[" << i << "]";
		node = this->table[i];
		while (node != nullptr)
		{
			std::cout << " -> " << node->data->to_print();
			node = node->next;
		}
		std::cout << "\n";
	}
}

void Hash_table::clear_table(List **table, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++) {
		while (table[i] != nullptr) {
			List::remove(&table[i], table[i]->data->get_key());
		}
	}
}

void Hash_table::clear(void)
{
	Hash_table::clear_table(this->table, this->size);
	this->load_ratio = 0.0;
}

void Hash_table::rehashing(void)
{
	List *node;
	List *prev;
	Substr *data;
	unsigned int new_index;
	unsigned int old_size = this->size;
	this->size *= 2;
	double new_load_ratio = 0.0;

	List **new_table = new List *[this->size];
	for (unsigned int index = 0; index < old_size; index++)
	{
		node = this->table[index];
		while (node != nullptr)
		{
			new_index = this->hash(node->data->get_key());
			if (new_table[new_index] == nullptr)
				new_load_ratio += (double)1.0 / this->size;
			List::push_front(&(new_table[new_index]), node->data);
			prev = node;
			node = node->next;
			delete prev;
		}
	}
	delete this->table;
	this->table = new_table;
	this->load_ratio = new_load_ratio;
}
