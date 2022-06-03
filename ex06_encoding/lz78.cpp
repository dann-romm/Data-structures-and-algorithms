#include "lz78.hpp"

void	Trie::insert(std::string s, int pos)
{
	Trie	*node;

	if (pos == (int) s.length())
	{
		this->is_node = true;
		return ;
	}

	std::set<Trie>::iterator it = next->find(s[pos]);
	if (it == next->end())
	{
		node = new Trie(s[pos]);
		this->next->insert(*node);
		node->insert(s, pos + 1);
	}
	else
		((Trie)(*it)).insert(s, pos + 1);
}

bool	Trie::contains(std::string s, int pos)
{
	std::set<Trie>::iterator it = next->find(s[pos]);
	if (it == next->end())
		return (false);
	else if (pos == (int) s.length())
		return (this->is_node);
	else
		return (((Trie)(*it)).contains(s, pos + 1));
}

void	Trie::print(std::ostream &out, int indent) const
{
	if (!indent && !this->data)
		out << "[root]";

	for (int i = 0; i < indent; i++)
		out << "\t";
	out << this->data << "(" << this->is_node << ")" << std::endl;
	
	for (std::set<Trie>::iterator it = this->next->begin(); it != this->next->end(); it++)
		(Trie (*it)).print(out, indent + 1);
}

