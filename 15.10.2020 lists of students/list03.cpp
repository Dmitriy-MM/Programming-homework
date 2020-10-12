#include "list_tasks.h"

int list03 (List_node * head)
{
	int amount = 0;
	List_node *prev_el,*cur_el, *next_el;
	
	if (head == nullptr)
		return 0;
	prev_el = head;
	cur_el = head->get_next ();
	if (cur_el == nullptr)
		return 1;
	next_el = cur_el->get_next ();
	
	if (*prev_el >= *cur_el)
		amount++;
	while (next_el != nullptr)
	{
		if ((*prev_el <= *cur_el) && (*cur_el >= *next_el))
		{
			amount++;
		}
		prev_el = cur_el;
		cur_el = next_el;
		next_el = next_el->get_next ();
	}
	if (*cur_el >= *prev_el)
		amount++;
	
	return amount;
}
