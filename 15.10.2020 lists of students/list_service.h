#ifndef LIST_SERVICE
#define LIST_SERVICE

#include <stdio.h>
#include "list_node.h"

struct LIST_SERVICE_RET_CODES
{
	enum RET_CODES {
		SUCCESS = 0,
		INPUT_NON_ZERO_PTR_ERROR,
		OPEN_FILE_ERROR,
		READ_HEAD_ERROR,
		NO_REACH_EOF_ERROR
	};
	static void error_handler (int er);
};

void delete_list (List_node *);
int read_list (const char * name, List_node *&);
void print_list (List_node *, int, FILE *fp = stdout);
void error_handler (int);
#endif //LIST_NODE