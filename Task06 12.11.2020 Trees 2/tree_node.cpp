#include "tree_node.h"


Tree_node::~Tree_node (void)
{
	destroy_branch ();
}

void Tree_node::destroy_branch (void)
{
	if (left != nullptr)
	{
		delete left;
		left = nullptr;
	}
	if (right != nullptr)
	{
		delete right;
		right = nullptr;
	}
}

Tree_node::Tree_node (const Tree_node& nd): Student (nd)
{
	*left = *nd.left;
	*right = *nd.right;
}

Tree_node::Tree_node (Tree_node&& nd): Student ((Student&&) (nd))
{
	left = nd.left;
	nd.left = nullptr;
	right = nd.right;
	nd.right = nullptr;
}

Tree_node& Tree_node::operator = (const Tree_node& nd)
{
	*(Student *) (this) = nd;
	return *this;
}

Tree_node& Tree_node::operator = (Tree_node&& nd)
{
	*(Student *) (this) = nd;
	left = nd.left;
	nd.left = nullptr;
	right = nd.right;
	nd.right = nullptr;
	return *this;
}

