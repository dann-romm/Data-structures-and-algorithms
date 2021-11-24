#include "main.hpp"

int main(void)
{
	std::ifstream input("input.txt");
	std::ofstream output("output.txt");
	std::stringstream buffer;
	PrefixTREE	tree;

	buffer << input.rdbuf();
	std::string str = buffer.str();

	std::string	encoded = huffman_encode(str, &tree);
	std::string	decoded = huffman_decode(encoded, &tree);

	output << decoded;
	// std::cout << str << std::endl << decoded << std::endl;
}
