#ifndef LIST
#define LIST

#include <stdio.h>
#include "list_node.h"

class List
{
	private:
		List_node * head = nullptr;
		void clear_list (void);

		void swap (List * second_list);
		List_node * merge_with (List_node * head_A, List_node * head_B, List_node * last);
		List_node * join (List_node *, List_node *);
	public:
		int read (const char * name);
		void print (int, FILE *fp = stdout);
		int get_length (void) const;
		enum RET_CODES {
			SUCCESS = 0,
			INPUT_NON_ZERO_PTR_ERROR,
			OPEN_FILE_ERROR,
			READ_HEAD_ERROR,
			NO_REACH_EOF_ERROR,
			BAD_FORMAT_ERROR
		};
		static void error_handler (int er);
		~List ()
		{
			clear_list ();
		}

		int get_less_than_prev (void);
		//Пузырек.
		void sort01 (void);
		//Нахождение минимума
		void sort02 (void);
		//Линейная вставка.
		void sort03 (void);
		//Слияние.
		void sort04 (void);
		//"Быстрая" сортировка.
		void sort05 (void);
};
#endif //LIST
