#ifndef HUFFMAN_HPP
# define HUFFMAN_HPP

# include <iostream>
# include <algorithm>
// # include <list>
# include <vector>
# include <map>

class HuffmanTREE
{
public:
	HuffmanTREE	*left;
	HuffmanTREE	*right;
	char		data;

	HuffmanTREE() : left(nullptr), right(nullptr), data(0) {};
	HuffmanTREE(HuffmanTREE *left, HuffmanTREE *right, char data): left(left), right(right), data(data) {};
	
};

void	huffman(std::string s);

#endif // HUFFMAN_HPP