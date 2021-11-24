#include "main.hpp"

int main(void)
{
	std::ifstream input("input.txt");
	std::ofstream output("output.txt", std::ios::binary);
	std::stringstream buffer;
	PrefixTREE	tree;

	buffer << input.rdbuf();
	std::string str = buffer.str();

	std::string	encoded = huffman_encode(str, &tree);
	std::cout << encoded << std::endl;

	int c;

	for (int i = 0; i < (int) encoded.length() / 8; i++)
	{
		c = 0;
		for (int j = 0; j < 8; j++)
			c += (encoded[i * 8 + j] == '1') << (7 - j);
		output.write((char *) &c, 8);
	}

	std::string	decoded = huffman_decode(encoded, &tree);

	// std::cout << str << std::endl << decoded << std::endl;
}
