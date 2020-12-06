#include "list.h"

void List::list05 (int k)
{
	List_node *curr = this->head, *next_node = nullptr, *tmp = nullptr;
	int i, j, count, length;
	int is_constantly, condition, is_head_deleted;
	//is_constantly - вошел ли итератор в участок постоянства.
	//condition - проверка текущего равенства *curr == *curr->next.

	if ((head == nullptr) || (head->next == nullptr))
		return;
	length = this->get_length ();

	next_node = curr->next;	
	is_constantly = (*next_node == *curr);
	if (is_constantly)
		count = 2;
	else
		count = 0;	
	curr = curr->next;
	for (i = 2; (curr != nullptr) && (curr->next != nullptr) && (i < length); i++)
	{
		is_head_deleted = 0;
		condition = (*curr == *curr->next);
		//printf ("is constantly %d condition %d\n", is_constantly, condition);
		//curr->print (stdout);
		if (is_constantly)
		{
			if (condition) //Продолжение участка постоянства.
				count++;
			else
			{
				//Участок постоянства закончился.
				is_constantly = 0;
				//printf ("i %d count %d\n", i, count);
				if (count >= k) //Удаляем участок целиком, если в нем не меньше k узлов.
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
			if (condition) //Входим в участок постоянства.
			{
				count = 2;
				is_constantly = 1;
			}
		}
		if (is_head_deleted)
			curr = this->head;
		else
			curr = curr->next;
	}
	
	if (count >= k) //Удаляем участок целиком, если в нем не меньше k узлов.
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
				//curr->next->prev = curr->prev;
			}
			curr = curr->prev;
			delete tmp;
		}
	//Обработка случая когда участок постоянства в конце.
}
