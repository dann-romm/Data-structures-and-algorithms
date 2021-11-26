#ifndef HUFFMAN_HPP
# define HUFFMAN_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <vector>
# include <map>

# include "PrefixTREE.hpp"

void	huffman_encode(std::string file_in, std::string file_out, PrefixTREE *tree);
void	huffman_decode(std::string file_in, std::string file_out, PrefixTREE *tree);

#endif // HUFFMAN_HPP