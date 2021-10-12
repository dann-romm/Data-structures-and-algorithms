#include "../includes/main.h"

int	task01(void)
{
	std::string		text;
	std::string		set;
	unsigned int	len;
	unsigned int	i;
	unsigned int	j;

	set = ".,!?;:\"'";
	std::cout << "Ввод строки: ";
	getline(std::cin, text);
	len = text.length();
	i = 0;
	while (i < len && set.find(text[i]) == std::string::npos)
		i++;
	if (i == len)
	{
		std::cout << text << "\n";
		return (0);
	}
	j = len - 1;
	while (j >= 0 && set.find(text[j]) == std::string::npos)
		j--;
	text = text.substr(j + 1, len - j - 1) + text.substr(i, j - i + 1) + text.substr(0, i);
	std::cout << "Итоговая строка: " << text << "\n";
	return (0);
}

int	substr_hashtable_init(Hash_table *table, unsigned int *substr_len)
{
	int				n;
	std::string		tmp;

	std::cout << "Ввод кол-во образцов: ";
	std::cin >> n;
	*substr_len = 0;
	for (int i = 0; i < n; i++)
	{
		std::cout << "Ввод " << (i + 1) << "-го образца: ";
		std::cin >> tmp;
		if (*substr_len == 0)
			*substr_len = tmp.length();
		else if (*substr_len != tmp.length())
		{
			std::cout << "error: substrings must have same length\n";
			delete table;
			return (1);
		}
		table->insert(new Pattern(tmp));
	}
	return (0);
}

int	task02(void)
{
	std::string		text;
	unsigned int	hash;
	unsigned int	text_len;
	unsigned int	substr_len;
	Hash_table		*table;
	List			*node;
	
	table = new Hash_table(32);

	std::cout << "Ввод текста:\n";
	getline(std::cin, text);
	text_len = text.length(); // считывание текста

	if (substr_hashtable_init(table, &substr_len)) // инициализация и считывание хеш-таблицы образцов
		return (1);

	hash = Hash_table::str_hash(text.substr(0, substr_len), table->size);
	for (int i = 0; (i + substr_len) < (text_len); i++)
	{
		node = table->table[hash];
		while (node != 0)
		{
			if (!text.compare(i, substr_len, node->data->get_key()))
				node->data->count += 1; // при совпадении хеша и совпадении образца, увеличиваем счётчик совпадений
			node = node->next;
		}
		hash = Hash_table::str_hash(hash, text[i], text[i + substr_len], table->size, substr_len); // расчёт нового значения скользящей хеш-функции
	}
	node = table->table[hash];
	while (node != 0)
	{
		if (!text.compare(text_len - substr_len, substr_len, node->data->get_key()))
			node->data->count += 1;
		node = node->next;
	}

	for (int i = 0; i < table->size; i++)
	{
		node = table->table[i];
		while (node != 0)
		{
			std::cout << "образец (" << node->data->get_key() << ") встретился " << node->data->count << " раз\n";
			node = node->next;
		}
	}
	delete table;
	return (0);
}

int main(void)
{
	task01();
	// task02();
	return (0);
}
