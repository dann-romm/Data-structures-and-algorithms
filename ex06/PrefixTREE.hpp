#ifndef PREFIXTREE_HPP
# define PREFIXTREE_HPP

# include <iostream>
# include <map>

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
	void	build_dict(
		std::map<char, std::string>	*dict,
		std::string					code=""
	);

	static PrefixTREE	*build_huffman_tree(std::map<char, int>	count) {};
	static PrefixTREE	*build_shennonfano_tree(std::map<char, int>	count) {};

	friend std::ostream&	operator<< (std::ostream &out, const PrefixTREE &tree) { tree.print(out); return (out); }
	bool					operator<(const PrefixTREE& tree) const { return (this->data < tree.data); }
	bool					operator>(const PrefixTREE& tree) const { return (this->data > tree.data); }
};

#endif