#include "../includes/node.h"

Node::Node(size_t key)
{
	this->key = key;
	this->v = new std::vector<size_t>;
}
