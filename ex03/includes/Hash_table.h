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
	const double load_ratio_limit = 0.75;
	double load_ratio;
	unsigned int hash(std::string key);
	void rehashing(void);
	static void clear_table(List **table, unsigned int size);
public:
	List **table;
	unsigned int size;
	Hash_table(unsigned int size);
	~Hash_table(void);
	static unsigned int str_hash(std::string key, unsigned int size);
	static unsigned int str_hash(unsigned int old_hash, char old_c, char new_c, unsigned int size, int len);
	void insert(Substr *data);
	void remove(std::string key);
	Substr *find(std::string key);
	void print(void);
	void clear(void);
};

#endif //HASH_TABLE_H
