#include "list.h"

//Нахождение минимума.
void List::sort02 (void)
{
	List_node * curr = this->head, * min = this->head, *new_head = nullptr, *prev_min = nullptr, * prev = nullptr;

	while (curr != nullptr)
	{
		while (curr != nullptr)
		{
			if (*curr > *min)
			{
				prev_min = prev;
				min = curr;
			}
			
			prev = curr;
			curr = curr->next;
		}
		if (prev_min != nullptr)
			prev_min->next = min->next;
		else 
			this->head = min->next;
		
		min->next = new_head;
		new_head = min;
		
		prev_min = prev = nullptr;
		min = curr = this->head;
	}
	this->head = new_head;
}
