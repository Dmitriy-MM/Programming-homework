#include "list_2_node.h"

List_2_node& List_2_node::operator = (const List_2_node& x)
{
	*(Student *) (this) = x;
	return *this;
}

List_2_node& List_2_node::operator = (List_2_node&& x)
{
	*(Student *) (this) = x; 
	next = x.next;
	x.next = nullptr;
	return *this;
}