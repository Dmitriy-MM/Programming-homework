#include "list_tasks.h"

int list06 (List_node * head)
{
	int amount = 0;
	List_node * cur_el = head, *next_el;
	enum STATES {IN, OUT} state = OUT;

	if (head == nullptr)
	{
		return 0;
	}
	next_el = head->get_next ();
	
	while (next_el != nullptr)
	{
		if (*cur_el == *next_el)
		{
			if (state == OUT)
				amount++;
			state = IN;
		}
		else 
			state = OUT;
		cur_el = next_el;
		next_el = next_el->get_next ();
	}
	
	return amount;
}
