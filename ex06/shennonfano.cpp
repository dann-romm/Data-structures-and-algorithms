#include "shennonfano.hpp"

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
	*tree = *(PrefixTREE::build_huffman_tree(count));

	dict = new std::map<char, std::string>();
	tree->build_dict(dict);

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