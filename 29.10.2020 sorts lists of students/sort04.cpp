#include "list.h"


void List::swap (List * second_list)
{
	List_node * tmp = second_list->head;
	second_list->head = this->head;
	this->head = tmp;
}

List_node * List::merge_with (List_node * head_A, List_node * head_B, List_node * last)
{
	List_node * curr_A = head_A, * curr_B = head_B, *curr = nullptr;

	int is_not_head_A_nullptr = head_A != nullptr, is_not_head_B_nullptr = head_B != nullptr;
	//Выбор головы такой объемный, потому что рассмотреть случаи, когда:
	//изначальный список (this) не пуст,
	//оба (A и B) не пусты - т.е. нужно сравнить головы и выбрать меньшую,
	//хотя бы один не пуст и взять голову из него,
	//оба пусты тогда не важно откуда брать.
	//Причем если голова взята, то нужно сдвинуть итератор по тому списку,
	//откуда она.
	if (last == nullptr)
	{
		//Выбор головы для списка из А и Б.
		if (is_not_head_A_nullptr && is_not_head_B_nullptr)
		{
			if (*head_A < *head_B)
			{
				this->head = head_A;
				curr_A = head_A->next;
			}			
			else
			{
				this->head = head_B;
				curr_B = head_B->next;
			}
		}
		else if (is_not_head_A_nullptr)
		{
			this->head = head_A;
			curr_A = head_A->next;
		}
		else
		{
			this->head = head_B;
			curr_B = head_B->next;
		}
		curr = this->head;
	}
	else
		//Список изначально не пуст.
		curr = last;
	
	//Само слияние.
	while ((curr_A != nullptr) && (curr_B != nullptr))
	{
		if (*curr_A < *curr_B)
		{
			curr = curr->next = curr_A;
			curr_A = curr_A->next;
		}
		else
		{
			curr = curr->next = curr_B;
			curr_B = curr_B->next;
		}
	}
	while (curr_A != nullptr)
	{
		curr = curr->next = curr_A;
		curr_A = curr_A->next;
	}
	while (curr_B != nullptr)
	{
		curr = curr->next = curr_B;
		curr_B = curr_B->next;
	}
	curr->next = nullptr;
	return curr;
}

//Сортировка слиянием.
void List::sort04 (void)
{
	List * second_list = new List;
	List_node * head_list_A = nullptr, * head_list_B = nullptr, *curr = nullptr, *curr_A, *curr_B;
	List_node * last = nullptr;
	int length, block_size = 1, i;
	
	length = this->get_length ();
	
	while (block_size < length)
	{
		curr = this->head;
		last = nullptr;
		while (curr != nullptr)
		{
			//Отрезаем два куска размера block_size от списка.
			head_list_A = curr_A = curr;
			if (curr != nullptr)
				curr = curr->next;

			for (i = 1; (i < block_size) && (curr != nullptr); i++)
			{
				curr_A = curr_A->next = curr;
				curr = curr->next;
			}
			if (curr_A != nullptr)
				curr_A->next = nullptr;
			
			head_list_B = curr_B = curr;
			if (curr != nullptr)
				curr = curr->next;
			for (i = 1; (i < block_size) && (curr != nullptr); i++)
			{
				curr_B = curr_B->next = curr;
				curr = curr->next;
			}
			if (curr_B != nullptr)
				curr_B->next = nullptr;
			this->head = curr;
			
			last = second_list->merge_with (head_list_A, head_list_B, last);
		}
		this->swap (second_list);
		second_list->head = nullptr;
		block_size *= 2;
	}
	delete second_list;
}
