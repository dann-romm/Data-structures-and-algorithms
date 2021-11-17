#include "main.hpp"

int main(void)
{
	// std::list<char>	buffer;
	// std::string		str = "abc ab abcdabc";

	// for (int i = 0; i < 16; i++)
	// 	buffer.push_front(str[i]);
	
	// Node	*node = findMatching("abcdefghui", buffer, 0);
	// std::cout << "<" << node->offset << ", " << node->length << ", " << node->next << ">\n";




	std::vector<Node>	ans;

	ans = encodeLZ77("abacabacabadaca");

	for (std::vector<Node>::iterator it = ans.begin(); it != ans.end(); it++)
	{
		std::cout << "<" << it->offset << ", " << it->length << ", " << it->next << ">\n";
	}




	// std::list<char>	buffer;
	// std::string		str = "abc ab abcdabc ";

	// for (int i = 0; i < BUFFER_SIZE; i++)
	// 	buffer.push_front(str[i]);
	
	// int	shift = 4;
	// int	pos = 3;

	// std::string s = "123qwerty678";

	// for (std::list<char>::iterator it = buffer.begin(); it != buffer.end(); it++)
	// 	std::cout << *it;
	// std::cout << '\n';

	// shiftBuffer(s, &buffer, shift, pos);

	// for (std::list<char>::iterator it = buffer.begin(); it != buffer.end(); it++)
	// 	std::cout << *it;
	// std::cout << '\n';
}