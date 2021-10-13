#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>
#include <string.h>
#include "Bank_account.h"

class List
{
public:
	List *next;
	Bank_account *data;
	List();
	static void push_front(List **head, Bank_account *data);
	static void remove(List **head, unsigned int key);
	List *find(unsigned int key);
};

template<class Data, class List>
class Hash_table
{
private:
	const double load_ratio_limit = 0.75;
	double load_ratio;

	List **table;

	unsigned int hash(unsigned int key);
	void rehashing();
	static void clear_table(List **table, unsigned int size);
public:
	unsigned int size;
	Hash_table(unsigned int size);
	void insert(Data *data);
	void remove(unsigned int key);
	Data *find(unsigned int key);
	void print();
	void clear();
};

#endif //HASH_TABLE_H
