#include "../includes/Substr.h"

Substr::Substr(std::string str)
{
	this->count = 0;
	this->str = str;
}

std::string	Substr::get_key(void)
{
	return (this->str);
}

std::string	Substr::to_print(void)
{
	return (this->str + "(" + std::to_string(this->count) + ")");
}