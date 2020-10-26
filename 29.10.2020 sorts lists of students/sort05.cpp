#include "list.h"

//"Быстрая" сортировка.
List_node * List::join (List_node * a, List_node * b)
{
	List_node * curr = a;
	while ((curr != nullptr) && (curr->next != nullptr))
		curr = curr->next;
	if (a != nullptr)
		curr->next = b;
	else if (b != nullptr)
		curr = b;
	else
	{
		printf ("Attention! 2 nullptrs in join\n");
		return nullptr;
	}	
	while ((curr != nullptr) && (curr->next != nullptr))
		curr = curr->next;
	return curr;
}

void List::sort05 (void)
{
	List_node * lower = nullptr, * upper = nullptr;
	List_node * l_curr = nullptr, * u_curr = nullptr;
	List_node * mid = nullptr, * prev_mid = nullptr, * m_curr = nullptr;
	List_node * curr = this->head;
	List_node * sorted_upper = nullptr, *sorted_lower = nullptr;
	int l_count = 0, u_count = 0;

	if (this->head == nullptr)
		return;

	//Выбираем примерно "средний" элемент списка.
	while (1)
	{
		curr = this->head;
		lower = upper = l_curr = u_curr = mid = prev_mid = m_curr = nullptr;
		l_count = u_count = 0;
		mid = curr;
		while (curr != nullptr)
		{
			if (mid->next != nullptr)
			{
				prev_mid = mid;
				mid = mid->next;
			}		
			curr = curr->next;
			if (curr != nullptr)
				curr = curr->next;
		}
		//Вырезаем его из списка.
		if (prev_mid != nullptr)
			prev_mid->next = mid->next;
		else
			this->head = mid->next;
		m_curr = mid;
		m_curr->next = nullptr;
			

		//Проходим по списку и разбираем его на три кучи.
		curr = this->head;
		while (curr != nullptr)
		{
			if (*curr < *mid)
			{
				//Еще не было элементов меньше mid.
				if (lower == nullptr)
					l_curr = lower = curr;
				else
				{
					l_curr->next = curr;
					l_curr = l_curr->next;
					l_count++;
				}
			}
			else if (*curr > *mid)
			{
				//Еще не было элементов больше mid.
				if (upper == nullptr)
					u_curr = upper = curr;
				else
				{
					u_curr->next = curr;
					u_curr = u_curr->next; 
					u_count++;
				}
			}
			else
			{
				m_curr->next = curr;
				m_curr = m_curr->next;
			}
			curr = curr->next;
		}
		//На кучи разбили, но могли остаться связи между списками или закольцовывания.
		if (lower != nullptr)
			l_curr->next = nullptr;
		if (upper != nullptr)
			u_curr->next = nullptr;
		m_curr->next = nullptr;

		//Запускаем сортировку для меньшего списка.
		if (u_count < l_count)
		{
			this->head = lower;
			this->sort05 ();
			lower = this->head;
			join (join (sorted_lower, lower), mid); //Склеить (sorted_lower + lower) + mid.
			if (sorted_lower == nullptr)
			{
				if (lower != nullptr)
					sorted_lower = lower;
				else
					sorted_lower = mid;
			}
			if (upper != nullptr)//Вернутся к началу.
				this->head = upper;
			else
			{
				this->head = sorted_lower;
				return;
			}

		}
		else
		{
			curr = this->head = mid;
			//Если верхняя куча не пуста.
			if (upper != nullptr)
			{
				//Пытаемся её отсортировать.
				this->head = upper;
				this->sort05 ();
				upper = this->head;
				join (join (mid, upper), sorted_upper);
			}
			else 
				join (mid, sorted_upper);

			sorted_upper = mid;

			if (lower != nullptr)//Вернутся к началу.
				this->head = lower;
			else
			{
				join (sorted_lower, sorted_upper);
				if (sorted_lower != nullptr)
					this->head = sorted_lower;
				else
					this->head = mid;
				return;
			}
		}
	}
}
