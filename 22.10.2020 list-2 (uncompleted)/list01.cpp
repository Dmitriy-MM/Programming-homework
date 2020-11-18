#include "list.h"

//Циклический сдвиг на k вправо.
void List::list01 (int k)
{
	List_node * head = this->head;
	List_node * next_node = head;
	List_node * new_head = head;
	int length, i;
	
	length = get_length ();
	if (k < 0)
	{
		k = (-k) % length;
		k = length - k;
	}
	k = k % length;
	//Замыкание списка (связываются голова и конец списка).
	for (i = 1; i < length; i++)
	{
		next_node = next_node->next;
		if (i == k)
			new_head = next_node; //Сразу находим нужную голову, т.к. все равно проходим через весь список.
	}
	next_node->next = head;
	head->prev = next_node;
	// next_node->print (stdout);next_node->next->print (stdout); head->prev->print(stdout);
	// new_head->print (stdout);new_head->next->print (stdout); new_head->prev->print(stdout);
	//Замыкание сделали.
	//Разрываем свзять между новой головой и новым концом.
	new_head->prev->next = nullptr;
	new_head->prev = nullptr;
	this->head = new_head;
}
