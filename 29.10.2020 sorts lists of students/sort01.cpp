#include "list.h"

static void swap_pointers (List_node *& a, List_node *& b)
{
	List_node * tmp = nullptr;
	tmp = a;
	a = b;
	b = tmp;
}
//Пузырек.
void List::sort01 (void)
{
	List_node * curr = this->head, * new_head = nullptr, *next_node = nullptr, *prev = nullptr;
	int swap_counts;
	
	while (curr != nullptr)
	{
		swap_counts = 0;
		//Всплывание элемента наверх.
		while ((curr != nullptr) && (curr->next != nullptr))
		{
			next_node = curr->next;
			
			if (*next_node < *curr)
			{
				if (prev != nullptr)
					prev->next = next_node;
				else
					this->head = next_node;
				curr->next = next_node->next;
				next_node->next = curr;
				swap_counts++;
				//Поменять указатели.
				swap_pointers (curr, next_node);
			}
			
			prev = curr;
			curr = curr->next;
		}
		//Отрываем последний кусок от конца списка и вставляем в новый.
		if (prev != nullptr)
			prev->next = nullptr;
		curr->next = new_head;
		new_head = curr;
		//Свапов не было = список упорядочен.
		if (swap_counts == 0)
		{
			if (prev != nullptr)
			{
				prev->next = new_head;
				new_head = this->head;
			}
			break;
		}
		
		curr = this->head;
		prev = nullptr;
	}
	this->head = new_head;
}
