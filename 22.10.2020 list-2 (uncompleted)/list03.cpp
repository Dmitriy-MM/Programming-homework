#include "list.h"

void List::list03 (int k)
{
	List_node *curr = head, *temp, *temp_next;
	int i, j, length;
	int is_deleted;
	
	if (head == nullptr)
		return;
	
	length = this->get_length ();
	
	
	
	for (i = k; curr && (i < length); i++)
	{ 
		temp = curr->next;
		is_deleted = 0;
		for (j = 0; temp && (j < k); j++)
		{
			temp_next = curr->next;
			if (*curr > *temp)
			{
				if (curr->prev == nullptr)
				{
					curr->next->prev = curr->prev;
					this->head = curr->next;
				}
				else
				{
					curr->next->prev = curr->prev;
					curr->prev->next = curr->next;
				}
				delete curr;
				is_deleted = 1;
				break;
			}
			temp = temp->next;
		}
		if (is_deleted)
			curr = temp_next;
		else
			curr = curr->next;
	}
}
