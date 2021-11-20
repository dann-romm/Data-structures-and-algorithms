#include "huffman.hpp"
#include <string>

void	huffman(std::string str)
{
	// setlocale(LC_ALL, "ru_RU.UTF-8");
	std::map<char, int>					count;
	std::vector<std::pair<char, int>>	arr1;
	std::vector<std::pair<char, int>>	arr2;

	for (auto c : str)
		count[c]++;
	for (auto it : count)
		arr1.push_back(it);

	std::sort(arr1.begin(), arr1.end(),
		[](std::pair<char, int> a, std::pair<char, int> b) { return (a.second < b.second); }
	);

	for (auto it : arr1)
		std::cout << it.first << ": " << it.second << std::endl;
	
	// int	i = 0;
	// int	j = 0;

	
}