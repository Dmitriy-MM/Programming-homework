#ifndef LIST_2_NODE
#define LIST_2_NODE
#include "student.h"

class List_2_node: public Student
{
	private:
		List_2_node * next = nullptr;
		List_2_node * prev = nullptr;
	public:
		List_2_node * get_next (void) const
		{
			return this->next;
		}
		void set_next (List_2_node * new_next)
		{
			next = new_next;
		}
		List_2_node () = default;
		List_2_node (const char * name, int value): Student (name, value)
		{
			next = nullptr;
			prev = nullptr;
		}
		List_2_node (const List_2_node& x): Student (x)
		{
			next = nullptr;
			prev = nullptr;
		}
		List_2_node (List_2_node&& x): Student (x)
		{
			next = x.next;
			x.next = nullptr;
			x.prev = nullptr;
		}
		~List_2_node ()
		{
			next = nullptr;
			prev = nullptr;
		}
		List_2_node& operator = (const List_2_node&);
		List_2_node& operator = (List_2_node&&);
		friend class List_2;
};
#endif //LIST_2_NODE