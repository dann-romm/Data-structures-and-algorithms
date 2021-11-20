#include "main.hpp"

int main(void)
{
	// std::string			str = "cabababababm";
	// std::vector<Node_LZ77>	encoded = encodeLZ77(str, 15);
	// std::string			decoded = decodeLZ77(encoded);
	// for (std::vector<Node_LZ77>::iterator it = encoded.begin(); it != encoded.end(); it++)
	// 	it->print();
	// std::string	str = "abcd";

	Trie	*trie = new Trie();
	trie->insert("a");
	// trie->insert("abce");
	// trie->insert("ql");
	// trie->insert("qh3t");
	// trie->insert("absv");
	// trie->insert("anvb");
	// trie->insert("ansn");
	std::cout << *trie;
	// std::cout << trie->contains("abcd") << std::endl;
}