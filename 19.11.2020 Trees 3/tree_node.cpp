#include "tree_node.h"


Tree_node::~Tree_node (void)
{
	destroy_node ();
}


void Tree_node::destroy_node (void)
{
	down = nullptr;
	level = nullptr;
}

Tree_node::Tree_node (const Tree_node& nd): Student (nd)
{
	//При создании узла через конструктор будет создана
	//копия узла (содержимое Student), но не будут скопированы ссылки.
	down = nullptr;
	level = nullptr;
}

Tree_node::Tree_node (Tree_node&& nd): Student ((Student&&) (nd))
{
	down = nd.down;
	nd.down = nullptr;
	level = nd.level;
	nd.level = nullptr;
}

Tree_node& Tree_node::operator = (const Tree_node& nd)
{
	*(Student *) (this) = nd;
	return *this;
}

Tree_node& Tree_node::operator = (Tree_node&& nd)
{
	*(Student *) (this) = nd;
	down = nd.down;
	nd.down = nullptr;
	level = nd.level;
	nd.level = nullptr;
	return *this;
}

