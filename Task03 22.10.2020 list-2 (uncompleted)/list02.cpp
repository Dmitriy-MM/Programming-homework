#include "list.h"

void List::list02 (int k)
{
	List_node *curr = head, *temp, *temp_prev;
	int i, j, length;
	int is_deleted;
	
	if (head == nullptr)
		return;
	
	length = this->get_length ();
	
	while (curr->next)
		curr = curr->next;
	for (i = k; i < length; i++)
	{ 
		temp = curr->prev;
		is_deleted = 0;
		for (j = 0; j < k; j++)
		{
			temp_prev = curr->prev;
			if (*curr > *temp)
			{
				if (curr->next == nullptr)
					curr->prev->next = curr->next;
				else
				{
					curr->prev->next = curr->next;
					curr->next->prev = curr->prev;
				}
				delete curr;
				is_deleted = 1;
				break;
			}
			temp = temp->prev;
		}
		if (is_deleted)
			curr = temp_prev;
		else
			curr = curr->prev;
	}
}









