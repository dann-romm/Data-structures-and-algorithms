#include "huffman.hpp"

PrefixTREE	*PrefixTREE::build_huffman_tree(std::map<char, int> count)
{
	std::vector<std::pair<PrefixTREE *, int>>	arr1;
	std::vector<std::pair<PrefixTREE *, int>>	arr2;
	int	i, j;

	for (auto it : count)
		arr1.push_back(std::pair<PrefixTREE *, int>(new PrefixTREE(it.first), it.second));
	std::sort(arr1.begin(), arr1.end(),
		[](std::pair<PrefixTREE *, int> a, std::pair<PrefixTREE *, int> b) { return (a.second < b.second); }
	);

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

void	huffman_encode(std::string file_in, std::string file_out, PrefixTREE *tree)
{
	std::map<char, int>			count;
	std::map<char, std::string>	*dict;
	std::string					encoded = "";
	std::ifstream				input(file_in);
	std::ofstream				output(file_out, std::ios::binary | std::ios::trunc);
	std::stringstream			buffer;

	buffer << input.rdbuf();
	std::string str = buffer.str();

	for (auto c : str)
		count[c]++;
	*tree = *(PrefixTREE::build_huffman_tree(count));

	std::cout << *tree << "\n";

	dict = new std::map<char, std::string>();
	tree->build_dict(dict);

	for (auto it: *dict)
		std::cout << it.first << ": " << it.second << "\n";

	for (auto c : str)
		encoded += (*dict)[c];
	for (int i = encoded.length(); i % 8 != 0; i++)
		encoded += '0';

	char c;
	for (int i = 0; i < (int) encoded.length() / 8; i++)
	{
		c = 0;
		for (int j = 0; j < 8; j++)
			c += (encoded[i * 8 + j] == '1') << (7 - j);
		output.write((char *) &c, 1);
	}
	input.close();
	output.close();
}

void	huffman_decode(std::string file_in, std::string file_out, PrefixTREE *tree)
{
	std::string			str = "";
	std::string			decoded = "";
	std::ifstream		input(file_in, std::ios::binary);
	std::ofstream		output(file_out, std::ios::trunc);
	PrefixTREE			*node;

	char c;
	while (1)
	{
		input >> c;
		if (input.eof()) break;
		for (int i = 0; i < 8; i++)
			str += (((c & (1 << (7 - i))) != 0) + '0');
	}

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
	output << decoded;
	input.close();
	output.close();
}
