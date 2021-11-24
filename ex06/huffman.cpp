#include "huffman.hpp"
#include "debug.hpp"
#include <string>

void	HuffmanTREE::print(std::ostream &out, int indent) const
{
	for (int i = 0; i < indent; i++)
		out << "\t";
	out << this->data << std::endl;

	if (this->left)
		this->left->print(out, indent + 1);
	if (this->right)
		this->right->print(out, indent + 1);
}

HuffmanTREE	*HuffmanTREE::build_tree(std::map<char, int> count)
{
	std::vector<std::pair<HuffmanTREE *, int>>	arr1;
	std::vector<std::pair<HuffmanTREE *, int>>	arr2;
	int	i, j;

	// fill and sort array of one-character nodes
	for (auto it : count)
		arr1.push_back(std::pair<HuffmanTREE *, int>(new HuffmanTREE(it.first), it.second));
	std::sort(arr1.begin(), arr1.end(),
		[](std::pair<HuffmanTREE *, int> a, std::pair<HuffmanTREE *, int> b) { return (a.second < b.second); }
	);

	// the first two inserts should be described separately to avoid segfault
	arr2.push_back(std::pair<HuffmanTREE *, int>(new HuffmanTREE(arr1[0].first, arr1[1].first), arr1[0].second + arr1[1].second));
	i = 2;
	j = 0;
	if (arr1[i + 1].second < arr2[j].second) {
		arr2.push_back(std::pair<HuffmanTREE *, int>(
			new HuffmanTREE(arr1[i].first, arr1[i + 1].first),
			arr1[i].second + arr1[i + 1].second
		));
		i += 2;
	}
	else {
		arr2.push_back(std::pair<HuffmanTREE *, int>(
			new HuffmanTREE(arr1[i].first, arr2[j].first),
			arr1[i].second + arr2[j].second
		));
		i++;
		j++;
	}

	// merge huffman trees in a loop
	for (int k = 2; k < (int) arr1.size() - 1; k++)
	{
		if (i == (int) arr1.size() || arr2[j + 1].second < arr1[i].second) {
			arr2.push_back(std::pair<HuffmanTREE *, int>(
				new HuffmanTREE(arr2[j].first, arr2[j + 1].first),
				arr2[j].second + arr2[j + 1].second
			));
			j += 2;
		}
		else if (i + 1 < (int) arr1.size() && arr1[i + 1].second < arr2[j].second) {
			arr2.push_back(std::pair<HuffmanTREE *, int>(
				new HuffmanTREE(arr1[i].first, arr1[i + 1].first),
				arr1[i].second + arr1[i + 1].second
			));
			i += 2;
		}
		else
		{
			arr2.push_back(std::pair<HuffmanTREE *, int>(
				new HuffmanTREE(arr1[i].first, arr2[j].first),
				arr1[i].second + arr2[j].second
			));
			i++;
			j++;
		}
	}
	return ((*(arr2.rbegin())).first);
}

std::map<char, std::string>	HuffmanTREE::build_dict()
{
	std::map<char, std::string>	dict;

	HuffmanTREE	*tree = this;
	std::string code = "qwe";
	// int i = 0;
	
	while (1)
	{
		if (tree->data)
			dict.insert(std::pair<char, std::string>(tree->data, code));
		tree = tree->left;
	}
	return (dict);
}

void	huffman(std::string str)
{
	std::map<char, int>	count;
	std::map<char, std::string>	dict;
	HuffmanTREE	*tree;

	for (auto c : str)
		count[c]++;
	tree = HuffmanTREE::build_tree(count);
	std::cout << *tree;

	dict = tree->build_dict();
	for (auto it : dict)
		std::cout << it.first << ": " << it.second << std::endl;
}
