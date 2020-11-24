#ifndef LIST_2
#define LIST_2

#include <stdio.h>
#include "list_2_node.h"


class List_2
{
	private:
		List_2_node * head = nullptr;
		static int m;
		static int r;
		
		void clear_list (void);
	public:
	
	int read (FILE *fp);
	void print (FILE *fp = stdout);
	int get_length (void) const;
	static void set_m (int new_m) {
		m = new_m;
	}
	static void set_r (int new_r) {
		r = new_r;
	}
	enum RET_CODES {
		SUCCESS = 0,
		INPUT_NON_ZERO_PTR_ERROR,
		OPEN_FILE_ERROR,
		READ_HEAD_ERROR,
		NO_REACH_EOF_ERROR,
		BAD_FORMAT_ERROR
	};
	static void error_handler (int er);
	
	int operator < (const List_2&);
	
	List_2 () = default;
	~List_2 ()
	{
		clear_list ();
	}
	
	//Конструктор перемещения.
	List_2 (List_2 && list)
	{
		this->head = list.head;
		list.head = nullptr;
	}
};
#endif //LIST2