#ifndef LZ77_HPP
# define LZ77_HPP

# include <iostream>
# include <vector>
# include <list>

# include "debug.hpp"

struct	Buffer
{
	Buffer(std::string s, int size, unsigned int offset) :
		s(s), size(size), offset(offset) {}
	std::string		s;
	int				size;
	unsigned int	offset;
};

struct		Node
{
	Node(int offset, int length, char next) :
		offset(offset), length(length), next(next) {}
	int		offset;
	int		length;
	char	next;
};

std::vector<Node> encodeLZ77(std::string s);
Node	*findMatching(std::string s, std::list<char> *buffer, unsigned int pos);
void	shiftBuffer(std::string s, std::list<char> *buffer, int shift, int pos);

#endif // LZ77_HPP
