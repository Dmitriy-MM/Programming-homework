#include <stdio.h>
#include <ctime>

#include "student.h"
#include "list_node.h"
#include "list_service.h"
#include "list_tasks.h"

enum RETURN_CODES {
	SUCCESS = 0,
	INPUT_ERROR,
	READ_ERROR
};

static void print_character_of_list (int c)
{
	switch (c)
	{
		case 0:
			printf ("The list is not monotonus\n");
			break;
		case 1:
			printf ("List is rising\n");
			break;
		case 2:
			printf ("List is dimish\n");
			break;
		case 3:
			printf ("The list doesn't change\n");
			break;
		case 4:
			printf ("Need more info\n");
			break;
		default:
			printf ("\"c\" must be in range -1<c<5\n");
			break;
	}
}

int main (int argc, char * argv[])
{
	int max_print;
	const char * filename;
	List_node * head = nullptr;
	int result = -1;
	int ret_code;
	clock_t time;
	
	if (!(
		(argc == 3) && (sscanf (argv[1], "%d", &max_print) == 1)
	))
	{
		printf ("Usage: %s max_print filename\n", argv[0]);
		return INPUT_ERROR;
	}
	filename = argv[2];
	
	
	ret_code = read_list (filename, head);
	if (ret_code != LIST_SERVICE_RET_CODES::SUCCESS)
	{
		LIST_SERVICE_RET_CODES::error_handler (ret_code);
		return ret_code;
	}
	print_list (head, max_print);
	
	time = clock ();
	result = list04 (head);
	time = clock () - time;
	
	printf ("---------------------------\nResult = %d\n", result);
	print_character_of_list (result);
	printf ("Elapsed %.2lfs\n", (double) time/CLOCKS_PER_SEC);
	delete_list(head);
	return SUCCESS;
}
