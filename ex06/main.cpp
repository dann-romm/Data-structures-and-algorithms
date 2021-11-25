#include "main.hpp"

int main(void)
{
	PrefixTREE	tree;

	// huffman_encode("input.txt", "encoded.bin", &tree);
	// huffman_decode("encoded.bin", "decoded.txt", &tree);

	// system("cat input.txt");
	// std::cout << std::endl;
	// system("cat decoded.txt");

	shennonfano_encode("input.txt", "encoded.bin", &tree);
}
