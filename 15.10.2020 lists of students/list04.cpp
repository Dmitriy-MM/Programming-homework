#include "list_tasks.h"

int list04 (List_node * head)
{
	//Биты в "condition" будут отвечать условиям задачи.
	//...000*1 - в каком-то месте строго возрастает.
	//...0001* - в каком-то месте строго убывает.
	//Тем самым, если список не убыв. и не возр = постоянен, если возр. и убыв. = не монотонен.
	int condition = 3;
	List_node *cur_el = head, *next_el;
	
	if (head == nullptr)
	{
		return 4;
	}
	next_el = cur_el->get_next ();
	if (next_el == nullptr)
	{
		//Недостаточно данных - значит только один элемент в списке.
		return 4;
	}
	
	while (next_el != nullptr)
	{
		if (*next_el > *cur_el)
			condition &= 1;
		else if (*next_el < *cur_el)
			condition &= 2;
		cur_el = next_el;
		next_el = next_el->get_next ();
	}
	
	return condition;
}