#include "shennonfano.hpp"

std::pair<PrefixTREE *, int>	build_tree_recursive(
	std::vector<std::pair<PrefixTREE *, int>> arr,
	int i, int j, int sum
)
{
	std::pair<PrefixTREE *, int> node1;
	std::pair<PrefixTREE *, int> node2;

	if (i == j)
		return (arr[i]);
	else if (i + 1 == j)
		return (std::pair<PrefixTREE *, int>(
			new PrefixTREE(arr[i].first, arr[j].first),
			arr[i].second + arr[j].second
		));
	else if (arr[i].second >= sum / 2)
	{
		node2 = build_tree_recursive(arr, i + 1, j, sum - arr[i].second);
		return (std::pair<PrefixTREE *, int>(
			new PrefixTREE(arr[i].first, node2.first),
			arr[i].second + node2.second
		));
	}

	int curr = 0;
	int it = i;
	do {
		curr += arr[it++].second;
	} while (sum / 2 - curr > 0);

	node1 = build_tree_recursive(arr, i, it, curr);
	node2 = build_tree_recursive(arr, it + 1, j, sum - curr);
	return (std::pair<PrefixTREE *, int>(
		new PrefixTREE(node1.first, node2.first),
		node1.second + node2.second
	));
}

PrefixTREE	*PrefixTREE::build_shennonfano_tree(std::map<char, int> count)
{
	std::vector<std::pair<PrefixTREE *, int>>	arr;
	int	sum = 0;

	for (auto it : count)
	{
		arr.push_back(std::pair<PrefixTREE *, int>(new PrefixTREE(it.first), it.second));
		sum += it.second;
	}
	std::sort(arr.begin(), arr.end(),
		[](std::pair<PrefixTREE *, int> a, std::pair<PrefixTREE *, int> b) { return (a.second < b.second); }
	);
	PrefixTREE	*tree = build_tree_recursive(arr, 0, arr.size() - 1, sum).first;
	return (tree);
}

void	shennonfano_encode(std::string file_in, std::string file_out, PrefixTREE *tree)
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

	// for (auto it : count)
	// 	std::cout << it.first << ": " << it.second << "\n";

	*tree = *(PrefixTREE::build_shennonfano_tree(count));
	DEBUG(*tree);

	dict = new std::map<char, std::string>();
	tree->build_dict(dict);

	// for (auto it : *dict)
	// 	std::cout << it.first << ": " << it.second << "\n";

	for (auto c : str)
		encoded += (*dict)[c];
	for (int i = encoded.length(); i % 8 != 0; i++)
		encoded += '0';

	DEBUG(encoded);

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

void	shennonfano_decode(std::string file_in, std::string file_out, PrefixTREE *tree)
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
	DEBUG(str);

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