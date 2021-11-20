#ifndef LZ78_HPP
# define LZ78_HPP

# include <iostream>
# include <set>

# include "debug.hpp"

class Trie
{
public:
	char				data;
	std::set<Trie>		*next;
	bool				is_node;

	Trie() : data(0), next(new std::set<Trie>()), is_node(false) {}
	Trie(char c) : data(c), next(new std::set<Trie>()), is_node(false) {}

	void	insert(std::string s, int pos=0);
	bool	contains(std::string s, int pos=0);
	void	print(std::ostream &out = std::cout, int indent=0) const;

	friend std::ostream& operator<< (std::ostream &out, const Trie &trie) { trie.print(out); return (out); }
	bool operator<(const Trie& trie) const { return (this->data < trie.data); }
	bool operator>(const Trie& trie) const { return (this->data > trie.data); }
};

#endif // LZ78_HPP