#include "list_tasks.h"

int list02 (List_node * head)
{
	int amount = 0;
	List_node * prev_el;
	
	if (head == nullptr)
	{
		return 0;
	}
	
	prev_el = head;
	head = head->get_next ();
	while (head != nullptr)
	{
		if ( (*head) > (*prev_el))
			amount++;
		prev_el = head;
		head = head->get_next ();
	}
	
	return amount;
}