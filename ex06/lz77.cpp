#include "lz77.hpp"

std::pair<int, int>	findMatching(Buffer *buffer, int pos)
{
	std::pair<int, int> pair = std::make_pair(0, 0);

	int	i = MAX(0, buffer->offset - buffer->size);
	int	j;
	int	current_i;
	int	current_len;

	while (i < pos)
	{
		j = pos;
		current_i = i;
		current_len = 0;
		while (buffer->s[i] == buffer->s[j] && j < (int) buffer->s.length())
		{
			current_len++;
			j++;
			i++;
		}
		if (current_len > pair.second)
		{
			pair.first = pos - current_i;
			pair.second = current_len;
		}
		i++;
	}
	return (pair);
}

std::vector<Node_LZ77>	encodeLZ77(std::string s, int buffer_size)
{
	Buffer				*buffer = new Buffer(s, buffer_size, 0);
	std::vector<Node>	ans;
	std::pair<int, int>	pair;
	unsigned int		pos;

	pos = 0;
	while (pos < s.length())
	{
		pair = findMatching(buffer, pos);
		buffer->offset += pair.second + 1;
		pos += pair.second + 1;

		ans.push_back(
			Node_LZ77(pair.first, pair.second, s[pos - 1])
		);
	}
	return ans;
}

std::string	decodeLZ77(std::vector<Node_LZ77> encoded)
{
	std::string ans = "";
	int	start;

	for (std::vector<Node_LZ77>::iterator it = encoded.begin(); it != encoded.end(); it++)
	{
		if (it->length > 0)
		{
			start = ans.length() - it->offset;
			for (int i = 0; i < it->length; i++)
				ans += ans[start + i];
		}
		ans += it->next;
	}
	
	return (ans);
}
