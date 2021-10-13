#include "main.h"

List::List() {
	this->next = nullptr;
	this->data = nullptr;
}

void List::push_front(List **head, Bank_account *data) {
	List *node = new List();
	node->next = *head;
	node->data = data;
	*head = node;
}

void List::remove(List **head, unsigned int key) {
	List *node;
	List *prev;

	if (head == nullptr || *head == nullptr)
		return ;
	node = (*head)->next;
	if ((*head)->data->get_key() == key) {
		delete (*head)->data;
		delete *head;
		*head = node;
		return ;
	}
	prev = *head;
	while (node != nullptr) {
		if (node->data->get_key() == key) {
			prev->next = node->next;
			delete node->data;
			delete node;
			return ;
		}
		prev = node;
		node = node->next;
	}
}

List *List::find(unsigned int key) {
	List *node = this;
	while (node != nullptr) {
		if (node->data->get_key() == key)
			return (node);
		node = node->next;
	}
	return (nullptr);
}

template<class Data, class List>
Hash_table<Data, List>::Hash_table(unsigned int size) {
	this->load_ratio = 0.0;
	this->size = size;
	this->table = new List *[size];
}

template<class Data, class List>
unsigned int Hash_table<Data, List>::hash(unsigned int key) {
	unsigned int hash = this->size * 113;
	while (key > 0) {
		hash = (hash * 157 + key % 10 * 3571) % this->size;
		key = key / 10;
	}
	return (hash);
}

template<class Data, class List>
void Hash_table<Data, List>::insert(Data *data) {
	unsigned int index = this->hash(data->get_key());
	if (this->table[index] == nullptr)
		this->load_ratio += (double)1.0 / this->size;
	List::push_front(&(this->table[index]), data);
	if (this->load_ratio > Hash_table::load_ratio_limit)
		this->rehashing();
}

template<class Data, class List>
void Hash_table<Data, List>::remove(unsigned int key) {
	unsigned int index = this->hash(key);
	List::remove(&((this->table)[index]), key);
	if ((this->table)[index] == nullptr)
		this->load_ratio -= (double)1.0 / this->size;
}

template<class Data, class List>
Data *Hash_table<Data, List>::find(unsigned int key) {
	unsigned int index = this->hash(key);
	List *node = ((this->table)[index])->find(key);
	if (node != nullptr)
		return (node->data);
	return (nullptr);
}

template<class Data, class List>
void Hash_table<Data, List>::print() {
	List *node;

	cout << "load ratio = " << this->load_ratio << "\n";

	for (int i = 0; i < this->size; i++) {
		cout << "table[" << i << "]";
		node = this->table[i];
		while (node != nullptr) {
			cout << " -> " << node->data->get_key();
			node = node->next;
		}
		cout << "\n";
	}
}

template<class Data, class List>
void Hash_table<Data, List>::clear_table(List **table, unsigned int size) {
	for (unsigned int i = 0; i < size; i++) {
		while (table[i] != nullptr) {
			List::remove(&table[i], table[i]->data->get_key());
		}
	}
}

template<class Data, class List>
void Hash_table<Data, List>::clear() {
	Hash_table<Data, List>::clear_table(this->table, this->size);
	this->load_ratio = 0.0;
}

template<class Data, class List>
void Hash_table<Data, List>::rehashing() {
	List *node;
	List *prev;
	Data *data;
	unsigned int new_index;
	unsigned int old_size = this->size;
	this->size *= 2;
	double new_load_ratio = 0.0;

	List **new_table = new List *[this->size];
	for (unsigned int index = 0; index < old_size; index++) {
		node = this->table[index];
		while (node != nullptr) {
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

int main()
{
	Hash_table<Bank_account, List> *table;
	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;
	double duration;

	cout << "Test 2\n";
	table = new Hash_table<Bank_account, List>(7);
	start = std::chrono::system_clock::now();
	srand(time(0));
	for (int i = 0; i < 5; i++) {
		table->insert(new Bank_account((abs((rand()) * 1000 + abs(rand()) * 100 + abs(rand()) * 10 + abs(rand())) % 10000000),"name1", "address1"));
	}
	table->insert(new Bank_account(1231231, "test_fio", "test_address"));
	cout << "хеш-таблица до удаления\n";
	table->print();
	table->remove(1231231);
	cout << "хеш-таблица после удаления\n";
	table->print();
	table->clear();
	delete table;
	end = std::chrono::system_clock::now();
	duration = std::chrono::duration<double>(end - start).count();
	cout << "Время выполнения: " << duration << "s\n";
}
