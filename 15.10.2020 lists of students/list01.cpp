#include "list_tasks.h"

int list01 (List_node * head)
{
	int num_maxes = 1;
	List_node * max_el;
	
	if (head == nullptr)
	{
		return 0;
	}
	
	max_el = head;
	head = head->get_next ();
	while (head != nullptr)
	{
		//Реализация с < > имеет более неочевидные побочные эффекты, чем "==" в случае head->name == nullptr.
		if ( (*max_el) < (*head) )
		{
			num_maxes = 1;
			max_el = head;
		}
		else if ( (*max_el) > (*head) )
		{
			;//Nothing to do.
		}
		else 
		{
			num_maxes++;
		}
		head = head->get_next ();
	}
	
	return num_maxes;
}