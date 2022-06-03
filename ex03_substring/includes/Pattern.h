#ifndef PATTERN_H
#define PATTERN_H

#include <string>

class Pattern
{
private:
	std::string str;
public:
	unsigned int count;
	Pattern(std::string str);
	std::string get_key(void);
	std::string to_print(void);
};

#endif // PATTERN_H
