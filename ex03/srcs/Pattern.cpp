#include "../includes/Pattern.h"

Pattern::Pattern(std::string str)
{
	this->count = 0;
	this->str = str;
}

std::string	Pattern::get_key(void)
{
	return (this->str);
}

std::string	Pattern::to_print(void)
{
	return (this->str + "(" + std::to_string(this->count) + ")");
}