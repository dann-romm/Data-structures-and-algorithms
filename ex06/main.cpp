#include "main.hpp"

int main(void)
{

	// std::ifstream		file("lz77.cpp");
	// std::stringstream	buffer;
	// buffer << file.rdbuf();
	// std::string			str = buffer.str();
	std::string			str = "cabababababm";

	std::vector<Node>	encoded = encodeLZ77(str, 15);
	std::string			decoded = decodeLZ77(encoded);

	for (std::vector<Node>::iterator it = encoded.begin(); it != encoded.end(); it++)
		it->print();

	// std::cout << encoded.size() * (10 + 10 + 8) << std::endl;
	// std::cout << str.length() * (8) << std::endl;
}