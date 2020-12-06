#ifndef LIST
#define LIST

#include <stdio.h>
#include "list_node.h"

class List
{
	private:
		List_node * head = nullptr;
		void clear_list (void);
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
	
	//Циклический сдвиг на k вправо.
	void list01 (int k);
	//Выбрасывает все элементы большие какого либо из k предыдущих.
	void list02 (int k);
	//Выбрасывает все элементы большие какого либо из k следующих.
	void list03 (int k);
	//
	void list04 (int k);
	//Удаляет все участки постоянства длиной не менее k.
	void list05 (int k);
	//Удаляет все участки нестрогого убывания длиной не менее k.
	void list06 (int k);
};


// void delete_list (List_node *&);
// int read_list (const char * name, List_node *&);
// void print_list (List_node *, int, FILE *fp = stdout);
// void error_handler (int);
#endif //LIST
