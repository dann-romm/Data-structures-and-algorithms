#include "main.hpp"

t_coins	input_coins()
{
	int		n;
	int		coin;
	t_coins	coins;

	std::cout << "Введите требуемую сумму: ";
	std::cin >> coins.sum;
	std::cout << "Введите кол-во номиналов монет: ";
	std::cin >> n;
	std::cout << "Введите номиналы монет a2...a" << n << ": ";
	coins.arr.push_back(1);
	for (int i = 0; i < n - 1; i++)
	{
		std::cin >> coin;
		coins.arr.push_back(coin);
	}
	return (coins);
}

std::map<int, int>	min_coins(t_coins coins)
{
	std::map<int, int>	count;
	int					curr_sum = coins.sum;
	int					n;

	std::sort(coins.arr.rbegin(), coins.arr.rend());

	for (auto it : coins.arr)
	{
		n = curr_sum / it;
		count[it] = n;
		curr_sum -= n * it;
	}

	return (count);
}

void	format_print_ans(std::map<int, int> ans)
{
	std::cout << "Необходимо взять:\n";
	for (auto it = ans.rbegin(); it != ans.rend(); it++)
	{
		if (it->second != 0)
			std::cout << std::setw(5) << it->second << " монет(ы) номиналом " << it->first << "\n";
	}
}

int main(void)
{
	std::map<int, int> ans;

	ans = min_coins(input_coins());
	format_print_ans(ans);
}
