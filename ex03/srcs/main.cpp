#include "../includes/main.h"

std::vector<std::string>	split(std::string str)
{
	std::vector<std::string>	arr;
	std::stringstream			strstream;
	std::string					tmp;

	strstream << str;
	while (!strstream.eof())
	{
		strstream >> tmp;
		arr.push_back(tmp);
	}
	strstream.str("");
	return (arr);
}

std::string	strjoin(std::vector<std::string> strs, std::string sep)
{
	std::string	str;
	int 		len;

	if (strs.empty())
		return (std::string());
	str = strs[0];
	len = strs.size();
	for (int i = 1; i < len; i++)
		str += sep + strs[i];
	return (str);
}

int	task01(void)
{
	std::vector<std::string>	arr;
	std::string					str;
	std::string					tmp;
	int 						len;

	std::cout << "Ввод строки:\n";
	getline(std::cin, str);
	arr = split(str); // разбиение строки на слова
	len = arr.size();
	tmp = arr[0]; // замена местами первое и послднее слова
	arr[0] = arr[len - 1];
	arr[len - 1] = tmp;
	str = strjoin(arr, " "); // содинение слов в одну строку
	std::cout << str << "\n";
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
		table->insert(new Substr(tmp));
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
	text_len = text.length();

	if (substr_hashtable_init(table, &substr_len))
		return (1);

	hash = Hash_table::str_hash(text.substr(0, substr_len), table->size);
	for (int i = 0; (i + substr_len) < (text_len); i++)
	{
		node = table->table[hash];
		while (node != 0)
		{
			if (!text.compare(i, substr_len, node->data->get_key()))
				node->data->count += 1;
			node = node->next;
		}
		hash = Hash_table::str_hash(hash, text[i], text[i + substr_len], table->size, substr_len);
	}
	node = table->table[hash];
	while (node != 0)
	{
		if (!text.compare(text_len - substr_len, substr_len, node->data->get_key()))
			node->data->count += 1;
		node = node->next;
	}

	
	return (0);
}

int main(void)
{
	// task01();
	task02();
	return (0);
}
