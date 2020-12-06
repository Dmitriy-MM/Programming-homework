#include "list.h"

void List::list06 (int k)
{
	List_node *curr = this->head, *next_node = nullptr, *tmp = nullptr;
	int i, j, count, length;
	int is_dimish, condition, is_head_deleted;

	if ((head == nullptr) || (head->next == nullptr))
		return;
	length = this->get_length ();

	next_node = curr->next;	
	is_dimish = (*next_node <= *curr);
	if (is_dimish)
		count = 2;
	else
		count = 0;	
	curr = curr->next;
	for (i = 2; (curr != nullptr) && (curr->next != nullptr) && (i < length); i++)
	{
		is_head_deleted = 0;
		condition = (*curr >= *curr->next);
		if (is_dimish)
		{
			if (condition) 
				count++;
			else
			{
				is_dimish = 0;
				if (count >= k) 
					for (j = 0; j < count; j++)
					{
						tmp = curr;
						if (curr->prev == nullptr)
						{
							this->head = curr->next;
							curr->next->prev = nullptr;
							is_head_deleted = 1;
							delete tmp; break;
						}
						else
						{
							curr->prev->next = curr->next;
							curr->next->prev = curr->prev;
							curr = curr->prev;
						}
						delete tmp;
					}
				count = 0;
			}
		}
		else
		{
			if (condition)
			{
				count = 2;
				is_dimish = 1;
			}
		}
		if (is_head_deleted)
			curr = this->head;
		else
			curr = curr->next;
	}
	
	if (count >= k) 
		for (j = 0; j < count; j++)
		{
			tmp = curr;
			if (curr->prev == nullptr)
			{
				this->head = curr->next;
			}
			else
			{
				curr->prev->next = curr->next;
			}
			curr = curr->prev;
			delete tmp;
		}
}
