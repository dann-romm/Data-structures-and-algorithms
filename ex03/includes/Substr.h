#ifndef SUBSTR_H
#define SUBSTR_H

#include <string>

class Substr
{
private:
	std::string str;
public:
	unsigned int count;
	Substr(std::string str);
	std::string get_key(void);
	std::string to_print(void);
};

#endif //SUBSTR_H
