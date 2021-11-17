#include "lz77.hpp"

// void debug_list_char(const std::string& name="(something)", std::list<char> *object=nullptr)
// {
// 	std::cout << name << ": ";
// 	for (std::list<char>::iterator it = object->begin(); it != object->end(); it++)
// 		std::cout << *it;
// 	std::cout << std::endl;
// }

Node	*findMatching(std::string s, Buffer *buffer, unsigned int pos)
{
	Node			*node = new Node(0, 0, 0);
	node->length = 0;
	node->offset = 0;

	for (int i = buffer->offset - buffer->size; i < buffer->s.length(); i++)
	{
		
	}

	return (node);
}

void	shiftBuffer(Buffer *buffer, int shift)
{
	buffer->offset += shift;
}

std::vector<Node> encodeLZ77(std::string s)
{
	std::vector<Node>	ans;
	Node				*node;
	Buffer				*buffer = new Buffer(s, 16, 0);
	unsigned int		pos;

	pos = 0;
	while (pos < s.length())
	{
		node = findMatching(s, buffer, pos);
		// std::cout << "<" << node->offset << ", " << node->length << ", " << node->next << ">\n";

		// debug_list_char("buffer", buffer);
		shiftBuffer(s, buffer, node->length, pos);
		pos += node->length;

		ans.push_back(
			Node(node->offset, node->length, s[pos])
		);
		delete node;
	}
	return ans;
}
