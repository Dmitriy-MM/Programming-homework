#include "list.h"

//Линейная вставка.
void List::sort03 (void)
{
	List_node * curr = this->head, *new_head = nullptr, *new_prev = nullptr, *new_curr = nullptr;
	
	while (this->head != nullptr)
	{
		curr = this->head;
		this->head = this->head->next;
		
		//Находим место, куда можно вставить наш оторванный элемент.
		new_prev = nullptr;
		new_curr = new_head;
		while ((new_curr != nullptr) && (*new_curr < *curr))
		{
			new_prev = new_curr;
			new_curr = new_curr->next;
		}
		
		if (new_prev != nullptr)
			new_prev->next = curr;
		else
			new_head = curr;
		curr->next = new_curr;
	}
	this->head = new_head;
}
