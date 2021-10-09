#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>

#include "../includes/Substr.h"

class List
{
public:
	List *next;
	Substr *data;
	List(void);
	static void push_front(List **head, Substr *data);
	static void remove(List **head, std::string key);
	List *find(std::string key);
};

class Hash_table
{
private:
	static const double load_ratio_limit = 0.75;
	double load_ratio;

	List **table;

	unsigned int hash(std::string key);
	void rehashing(void);
	static void clear_table(List **table, unsigned int size);
public:
	unsigned int size;
	Hash_table(unsigned int size);
	~Hash_table(void);
	void insert(Substr *data);
	void remove(std::string key);
	Substr *find(std::string key);
	void print(void);
	void clear(void);
};

#endif //HASH_TABLE_H
