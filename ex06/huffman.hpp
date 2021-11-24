#ifndef HUFFMAN_HPP
# define HUFFMAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <map>

class HuffmanTREE
{
public:
	HuffmanTREE	*left;
	HuffmanTREE	*right;
	char		data;

	HuffmanTREE(char data) : left(nullptr), right(nullptr), data(data) {};
	HuffmanTREE(HuffmanTREE *left, HuffmanTREE *right) : left(left), right(right), data(0) {};
	HuffmanTREE(HuffmanTREE *left, HuffmanTREE *right, char data): left(left), right(right), data(data) {};

	void	print(std::ostream &out = std::cout, int indent=0) const;

	static HuffmanTREE			*build_tree(std::map<char, int>	count);
	std::map<char, std::string>	build_dict();

	friend std::ostream&	operator<< (std::ostream &out, const HuffmanTREE &tree) { tree.print(out); return (out); }
	bool					operator<(const HuffmanTREE& tree) const { return (this->data < tree.data); }
	bool					operator>(const HuffmanTREE& tree) const { return (this->data > tree.data); }
};

void	huffman(std::string s);

#endif // HUFFMAN_HPP