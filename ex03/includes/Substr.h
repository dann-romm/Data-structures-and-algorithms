#ifndef SUBSTR_H
#define SUBSTR_H

#include <string>

class Substr
{
private:
	unsigned int count;
	std::string str;
public:
	Substr(std::string str);
	std::string get_key(void);
	std::string to_print(void);
};

#endif //SUBSTR_H
