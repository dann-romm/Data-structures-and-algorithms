#ifndef SHENNONFANO_HPP
# define SHENNONFANO_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <vector>
# include <map>

# include "debug.hpp"
# include "huffman.hpp"

void	shennonfano_encode(std::string file_in, std::string file_out, PrefixTREE *tree);
void	shennonfano_decode(std::string file_in, std::string file_out, PrefixTREE *tree);

#endif