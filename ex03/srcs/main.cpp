#include "../includes/main.h"

vector<string>	split(string str)
{
	vector<string>	arr;
	stringstream	strstream;
	string			tmp;

	strstream << str;
	while (!strstream.eof())
	{
		strstream >> tmp;
		arr.push_back(tmp);
	}
	strstream.str("");
	return (arr);
}

string	strjoin(vector<string> strs, string sep)
{
	string	str;
	int 	len;

	if (strs.empty())
		return (string());
	str = strs[0];
	len = strs.size();
	for (int i = 1; i < len; i++)
		str += sep + strs[i];
	return (str);
}

int	task01(void)
{
	vector<string>	arr;
	string			str;
	string			tmp;
	int 			len;

	cout << "Ввод строки:\n";
	getline(cin, str);
	arr = split(str); // разбиение строки на слова
	len = arr.size();
	tmp = arr[0]; // замена местами первое и послднее слова
	arr[0] = arr[len - 1];
	arr[len - 1] = tmp;
	str = strjoin(arr, " "); // содинение слов в одну строку
	cout << str << "\n";
	return (0);
}

int	task02(void)
{
	int				n;
	string			text;
	string			tmp;
	unsigned int	hash;
	unsigned int	substr_len;
	unsigned int	text_len;
	Hash_table		*table;
	
	table = new Hash_table(31);

	cout << "Ввод текста:\n";
	getline(cin, text);
	cout << "Ввод кол-во образцов: ";
	cin >> n;
	substr_len = 0;
	text_len = text.length();
	for (int i = 0; i < n; i++)
	{
		cout << "Ввод " << (i + 1) << "-го образца: ";
		cin >> tmp;
		if (substr_len == 0)
			substr_len = tmp.length();
		else if (substr_len != tmp.length())
		{
			cout << "error: substrings must have same length\n";
			delete table;
			return (1);
		}
		table->insert(new Substr(tmp));
	}

	hash = 0;
	for (int i = 0; (i + substr_len) < text_len; i++) // TODO: compare and calculate hash
	{
		return (0); // remove
	}

	table->print();
	return (0);
}

int main(void)
{
	// task01();
	task02();
	return (0);
}
