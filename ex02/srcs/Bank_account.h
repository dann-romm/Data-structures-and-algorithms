#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>
using namespace std;

struct Bank_account
{
private:
	unsigned int account_number;
	string name;
	string address;
public:
	Bank_account(unsigned int account_number, string name, string address);
	unsigned int get_key();
};

#endif //BANK_ACCOUNT_H
