#ifndef LIST_NODE
#define LIST_NODE
#include "student.h"

class List_node: public Student
{
	private:
		List_node * next = nullptr;
	public:
		List_node * get_next (void) const
		{
			return this->next;
		}
		void set_next (List_node * new_next)
		{
			next = new_next;
		}
		List_node () = default;
		List_node (const char * name, int value): Student (name, value)
		{
			next = nullptr;
		}
		List_node (const List_node& x): Student (x)
		{
			next = nullptr;
		}
		List_node (List_node&& x): Student (x)
		{
			next = x.next;
			x.next = nullptr;
		}
		~List_node ()
		{
			next = nullptr;
		}
		List_node& operator = (const List_node&);
		List_node& operator = (List_node&&);
};
#endif //LIST_NODE