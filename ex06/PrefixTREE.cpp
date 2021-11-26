#include "PrefixTREE.hpp"

void	PrefixTREE::print(std::ostream &out, int indent) const
{
	for (int i = 0; i < indent; i++)
		out << "\t";
	out << this->data << std::endl;

	if (this->left)
		this->left->print(out, indent + 1);
	if (this->right)
		this->right->print(out, indent + 1);
}

void	PrefixTREE::build_dict(std::map<char, std::string> *dict, std::string code)
{
	if (this->data)
		dict->insert(std::pair<char, std::string>(this->data, code));

	if (this->left)
		this->left->build_dict(dict, code + "0");
	if (this->right)
		this->right->build_dict(dict, code + "1");
}

