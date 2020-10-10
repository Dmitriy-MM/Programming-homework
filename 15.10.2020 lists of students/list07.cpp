#include "list_tasks.h"

int list07 (List_node * head)
{
	int length = 0, max_length = 0;
	List_node * cur_el = head, *next_el;
	enum states {START = 0, IN, OUT} status = START;
	if (head == nullptr)
	{
		return 0;
	}
	next_el = head->get_next ();
	
	while (next_el != nullptr)
	{
		if ((*cur_el > *next_el) || (*cur_el < *next_el))
		{
			if (status == IN)
			{
				if (length > max_length)
					max_length = length;
				length = 0;
				status = OUT;
			}
			else if (status == OUT)
				length++;
		}
		else
		{
			status = IN;
		}
		cur_el = next_el;
		next_el = next_el->get_next ();
	}
	if ((status == IN) && (length > max_length))
		max_length = length;
	
	return max_length;
}