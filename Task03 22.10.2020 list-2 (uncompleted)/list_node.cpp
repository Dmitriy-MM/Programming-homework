#include "list_node.h"

List_node& List_node::operator = (const List_node& x)
{
	*(Student *) (this) = x;
	return *this;
}

List_node& List_node::operator = (List_node&& x)
{
	*(Student *) (this) = x; 
	next = x.next;
	x.next = nullptr;
	return *this;
}