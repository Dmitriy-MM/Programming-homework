#include "list_tasks.h"

int list08 (List_node * head)
{
	int length_non_const = 0, left_length_const = 1, right_length_const = 0;
	int max_length = 1;
	List_node * cur_el = head, *next_el;
	enum states {CONSTANTLY = 0, RISING, DIMISH} status = CONSTANTLY;
	if (head == nullptr)
	{
		return 0;
	}
	next_el = head->get_next ();
	
	while (next_el != nullptr)
	{
		if (max_length < left_length_const + length_non_const + right_length_const)
		{
			max_length = left_length_const + length_non_const + right_length_const;
			if (status == CONSTANTLY)
			{
				left_length_const = right_length_const + 1;
				right_length_const = 0;
			}
		}
		if (*next_el > *cur_el)
		{
			if (status == DIMISH)
				length_non_const = 0;
			length_non_const++;
			status = RISING;
			cur_el = next_el;
			next_el = next_el->get_next ();
			while ((next_el != nullptr) && (*next_el > *cur_el))
			{
				length_non_const++;
				cur_el = next_el;
				next_el = next_el->get_next ();
			}
		}
		else if (*next_el < *cur_el)
		{
			if (status == RISING)
				length_non_const = 0;
			length_non_const++;
			status = DIMISH;
			cur_el = next_el;
			next_el = next_el->get_next ();
			while ((next_el != nullptr) && (*next_el < *cur_el))
			{
				length_non_const++;
				cur_el = next_el;
				next_el = next_el->get_next ();
			}
		}
		else
		{
			status = CONSTANTLY;
			length_non_const = 0;
			right_length_const++;
			cur_el = next_el;
			next_el = next_el->get_next ();
			while ((next_el != nullptr) && (*next_el == *cur_el))
			{
				right_length_const++;
				cur_el = next_el;
				next_el = next_el->get_next ();
			}
		}
	}
	
	if (max_length < left_length_const + length_non_const + right_length_const)
		max_length = left_length_const + length_non_const + right_length_const;
	
	return max_length;
}