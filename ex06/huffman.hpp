#ifndef HUFFMAN_HPP
# define HUFFMAN_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <vector>
# include <map>

# include "debug.hpp"

class PrefixTREE
{
public:
	PrefixTREE	*left;
	PrefixTREE	*right;
	char		data;

	PrefixTREE() : left(nullptr), right(nullptr), data(0) {};
	PrefixTREE(char data) : left(nullptr), right(nullptr), data(data) {};
	PrefixTREE(PrefixTREE *left, PrefixTREE *right) : left(left), right(right), data(0) {};
	PrefixTREE(PrefixTREE *left, PrefixTREE *right, char data): left(left), right(right), data(data) {};

	void	print(std::ostream &out = std::cout, int indent=0) const;

	static PrefixTREE			*build_huffman_tree(std::map<char, int>	count);
	static PrefixTREE			*build_shennonfano_tree(std::map<char, int>	count);
	void						build_dict(
		std::map<char, std::string>	*dict,
		std::string					code=""
	);

	friend std::ostream&	operator<< (std::ostream &out, const PrefixTREE &tree) { tree.print(out); return (out); }
	bool					operator<(const PrefixTREE& tree) const { return (this->data < tree.data); }
	bool					operator>(const PrefixTREE& tree) const { return (this->data > tree.data); }
};

void	huffman_encode(std::string file_in, std::string file_out, PrefixTREE *tree);
void	huffman_decode(std::string file_in, std::string file_out, PrefixTREE *tree);

#endif // HUFFMAN_HPP