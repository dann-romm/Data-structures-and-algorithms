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

std::pair<PrefixTREE *, int>	build_tree_recursive(
	std::vector<std::pair<PrefixTREE *, int>> arr,
	int i, int j, int sum
);

void	shennonfano_encode(std::string file_in, std::string file_out, PrefixTREE *tree);

#endif