#include "huffman.hpp"
#include "debug.hpp"
#include <string>

void	PrefixTREE::print(std::ostream &out, int indent) const
{
	for (int i = 0; i < indent; i++)
		out << "\t";
	out << this->data << std::endl;

	if (this->left)
		this->left->print(out, indent + 1);
	if (this->right)
		this->right->print(out, indent + 1);
}

PrefixTREE	*PrefixTREE::build_huffman_tree(std::map<char, int> count)
{
	std::vector<std::pair<PrefixTREE *, int>>	arr1;
	std::vector<std::pair<PrefixTREE *, int>>	arr2;
	int	i, j;

	// fill and sort array of one-character nodes
	for (auto it : count)
		arr1.push_back(std::pair<PrefixTREE *, int>(new PrefixTREE(it.first), it.second));
	std::sort(arr1.begin(), arr1.end(),
		[](std::pair<PrefixTREE *, int> a, std::pair<PrefixTREE *, int> b) { return (a.second < b.second); }
	);

	// the first two inserts should be described separately to avoid segfault
	arr2.push_back(std::pair<PrefixTREE *, int>(new PrefixTREE(arr1[0].first, arr1[1].first), arr1[0].second + arr1[1].second));
	i = 2;
	j = 0;
	if (arr1[i + 1].second < arr2[j].second) {
		arr2.push_back(std::pair<PrefixTREE *, int>(
			new PrefixTREE(arr1[i].first, arr1[i + 1].first),
			arr1[i].second + arr1[i + 1].second
		));
		i += 2;
	}
	else {
		arr2.push_back(std::pair<PrefixTREE *, int>(
			new PrefixTREE(arr1[i].first, arr2[j].first),
			arr1[i].second + arr2[j].second
		));
		i++;
		j++;
	}

	// merge huffman trees in a loop
	for (int k = 2; k < (int) arr1.size() - 1; k++)
	{
		if (i == (int) arr1.size() || arr2[j + 1].second < arr1[i].second) {
			arr2.push_back(std::pair<PrefixTREE *, int>(
				new PrefixTREE(arr2[j].first, arr2[j + 1].first),
				arr2[j].second + arr2[j + 1].second
			));
			j += 2;
		}
		else if (i + 1 < (int) arr1.size() && arr1[i + 1].second < arr2[j].second) {
			arr2.push_back(std::pair<PrefixTREE *, int>(
				new PrefixTREE(arr1[i].first, arr1[i + 1].first),
				arr1[i].second + arr1[i + 1].second
			));
			i += 2;
		}
		else
		{
			arr2.push_back(std::pair<PrefixTREE *, int>(
				new PrefixTREE(arr1[i].first, arr2[j].first),
				arr1[i].second + arr2[j].second
			));
			i++;
			j++;
		}
	}
	return ((*(arr2.rbegin())).first);
}

void	PrefixTREE::build_dict(std::map<char, std::string> *dict, std::string code)
{
	if (this->data)
		dict->insert(std::pair<char, std::string>(this->data, code));

	if (this->left)
		this->left->build_dict(dict, code + "0");
	if (this->right)
		this->right->build_dict(dict, code + "1");
}

std::string	huffman_encode(std::string str, PrefixTREE *tree)
{
	std::map<char, int>			count;
	std::map<char, std::string>	*dict;
	std::string					encoded = "";

	for (auto c : str)
		count[c]++;
	*tree = *(PrefixTREE::build_huffman_tree(count));

	dict = new std::map<char, std::string>();
	tree->build_dict(dict);

	for (auto c : str)
		encoded += (*dict)[c];
	return (encoded);
}

std::string	huffman_decode(std::string str, PrefixTREE *tree)
{
	std::string	decoded = "";
	PrefixTREE	*node;
	
	node = tree;
	for (auto it : str)
	{
		if (it == '0')
			node = node->left;
		else
			node = node->right;

		if (node->data)
		{
			decoded += node->data;
			node = tree;
		}
	}
	return (decoded);
}
