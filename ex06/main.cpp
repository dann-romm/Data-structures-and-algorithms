#include "main.hpp"

#include <string>

int main(void)
{
	setlocale(LC_ALL, ".1251");
	// SetConsoleCP(866);
	// SetConsoleOutputCP(866);
	std::string str = "Мой котёнок очень странный,\nОн не хочет есть сметану,\nК молоку не прикасался\nИ от рыбки отказался.";
	// std::cout << str;
	huffman(str);
}