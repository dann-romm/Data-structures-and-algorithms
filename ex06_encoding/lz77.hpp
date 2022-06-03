#ifndef LZ77_HPP
# define LZ77_HPP

# include <iostream>
# include <vector>
# include <utility>
# include <list>

# include "debug.hpp"

# define MAX(a, b) (((a) > (b)) ? (a) : (b))

struct	Buffer
{
	Buffer(std::string s, int size, int offset) :
		s(s), size(size), offset(offset) {}
	std::string	s;
	int			size;
	int			offset;
};

struct		Node_LZ77
{
	Node_LZ77(int offset, int length, char next) :
		offset(offset), length(length), next(next) {}
	int		offset;
	int		length;
	char	next;

	void	print()
	{
		std::cout << "<" << offset << ", "
			<< length << ", " << next << ">" << std::endl;
	}
};

std::vector<Node_LZ77>	encodeLZ77(std::string s, int buffer_size);
std::string			decodeLZ77(std::vector<Node_LZ77> encoded);
std::pair<int, int>	findMatching(Buffer *buffer, int pos);

#endif // LZ77_HPP
