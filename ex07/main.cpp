#include "main.hpp"

std::vector<int>	input()
{
	int					n;
	int					coin;
	std::vector<int>	coins;

	std::cout << "Введите кол-во номиналов монет: ";
	std::cin >> n;
	std::cout << "Введите номиналы (" << n << ") монет:\n";
	for (int i = 0; i < n; i++)
	{
		std::cin >> coin;
		coins.push_back(coin);
	}
	return (coins);
}

std::map<int, int>	min_coins(std::vector<int> coins, )
{
	std::map<int, int>	count;

	std::sort(coins.rbegin(), coins.rend());

	for (auto it : coins)
	{

	}

	return (count);
}

int main(void)
{
	min_coins(input());
}
