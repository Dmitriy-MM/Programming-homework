#include "list_tasks.h"

int list05 (List_node * head)
{
	int max_length = 1, length = 1;
	List_node * cur_el = head, *next_el;
	
	if (head == nullptr)
	{
		return 0;
	}
	next_el = head->get_next ();
	
	while (next_el != nullptr)
	{
		if (*next_el > *cur_el)
			length++;
		else
		{
			if (length > max_length)
				max_length = length;
			length = 1;
		}
		cur_el = next_el;
		next_el = next_el->get_next ();
	}
	if (length > max_length)
		max_length = length;
	
	return max_length;
}
