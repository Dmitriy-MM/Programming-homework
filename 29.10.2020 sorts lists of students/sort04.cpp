#include "list.h"


void List::swap (List * second_list)
{
	List_node * tmp = second_list->head;
	second_list->head = this->head;
	this->head = tmp;
}

void List::merge_with (List_node * head_A, List_node * head_B)
{
	List_node * curr_A = head_A, * curr_B = head_B, *curr = nullptr;

	//Выбор головы такой объемный, потому что рассмотреть случаи, когда:
	//изначальный список (this) не пуст,
	//оба (A и B) не пусты - т.е. нужно сравнить головы и выбрать меньшую,
	//хотя бы один не пуст и взять голову из него,
	//оба пусты тогда не важно откуда брать.
	//Причем если голова взята, то нужно сдвинуть итератор по тому списку,
	//откуда она.
	if (this->head == nullptr)
	{
		//Выбор головы для списка из А и Б.
		if ((head_A != nullptr) && (head_B != nullptr))
		{
			if (*head_A < *head_B)
			{
				this->head = head_A;
				if (curr_A != nullptr)
					curr_A = head_A->next;
			}			
			else
			{
				this->head = head_B, curr_B = head_B->next;
				if (curr_B != nullptr)
					curr_B = head_B->next;
			}
		}
		else if (head_A != nullptr)
		{
			this->head = head_A;
			if (curr_A != nullptr)
			curr_A = head_A->next;
		}
		else
		{
			this->head = head_B, curr_B = head_B->next;
			if (curr_B != nullptr)
				curr_B = head_B->next;
		}
		curr = this->head;
	}
	else
	{
		//Список изначально не пуст.
		curr = this->head;
		while ((curr != nullptr) && (curr->next != nullptr))
			curr = curr->next;	
	}
	
	//Само слияние.
	while ((curr_A != nullptr) && (curr_B != nullptr))
	{
		if (*curr_A < *curr_B)
		{
			curr->next = curr_A;
			curr_A = curr_A->next;
		}
		else
		{
			curr->next = curr_B;
			curr_B = curr_B->next;
		}
		curr = curr->next;
	}
	while (curr_A != nullptr)
	{
		curr->next = curr_A;
		curr_A = curr_A->next;
		curr = curr->next;
	}
	while (curr_B != nullptr)
	{
		curr->next = curr_B;
		curr_B = curr_B->next;
		curr = curr->next;
	}
	curr->next = nullptr;
}

//Сортировка слиянием.
void List::sort04 (void)
{
	List * second_list = new List;
	List_node * head_list_A = nullptr, * head_list_B = nullptr, *curr = nullptr, *curr_A, *curr_B;
	int length, block_size = 1, i, shift;
	
	length = this->get_length ();
	
	while (block_size < length)
	{
		curr = this->head;
		shift = 1;
		while (shift < length)
		{
			//Отрезаем два куска размера block_size от списка.
			head_list_A = curr_A = curr;
			if (curr != nullptr)
				curr = curr->next, shift++;

			for (i = 1; (i < block_size) && (curr != nullptr); i++)
			{
				curr_A->next = curr;
				curr_A = curr;
				curr = curr->next, shift++;
			}
			if (curr_A != nullptr)
				curr_A->next = nullptr;
			
			head_list_B = curr_B = curr;
			if (curr != nullptr)
				curr = curr->next, shift++;
			for (i = 1; (i < block_size) && (curr != nullptr); i++)
			{
				curr_B->next = curr;
				curr_B = curr;
				curr = curr->next, shift++;
			}
			if (curr_B != nullptr)
				curr_B->next = nullptr;
			this->head = curr;
			
			second_list->merge_with (head_list_A, head_list_B);
		}
		this->swap (second_list);
		second_list->head = nullptr;
		block_size *= 2;
	}
	delete second_list;
}
