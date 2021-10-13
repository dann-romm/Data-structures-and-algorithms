#include "Bank_account.h"

Bank_account::Bank_account(unsigned int account_number, string name, string address) {
	this->account_number = account_number;
	this->name = name;
	this->address = address;
}

unsigned int Bank_account::get_key() {
	return (this->account_number);
}
