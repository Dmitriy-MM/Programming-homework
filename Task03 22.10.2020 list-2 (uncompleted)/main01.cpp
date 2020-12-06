#include <stdio.h>
#include <ctime>

#include "list.h"

enum RETURN_CODES {
	SUCCESS = 0,
	INPUT_ERROR,
	READ_ERROR
};

int main (int argc, char * argv[])
{
	int max_print, k;
	const char * filename;
	List * input_list = nullptr;
	int ret_code;
	clock_t time;
	
	if (!(
		(argc == 4) && 
		(sscanf (argv[1], "%d", &max_print) == 1) &&
		(sscanf (argv[3], "%d", &k) == 1)
	))
	{
		printf ("Usage: %s max_print filename k\n", argv[0]);
		return INPUT_ERROR;
	}
	filename = argv[2];
	
	input_list = new List;
	ret_code = input_list->read (filename);
	if (ret_code != List::SUCCESS)
	{
		List::error_handler (ret_code);
		return ret_code;
	}
	printf ("List length %d:\n", input_list->get_length ());
	input_list->print (max_print);
	
	time = clock ();
	input_list->list01 (k);
	time = clock () - time;
	
	printf ("---------------------------\nAfter shifting:\n");
	printf ("List length %d:\n", input_list->get_length ());
	input_list->print (max_print);
	printf ("Elapsed %.2lfs\n", (double) time/CLOCKS_PER_SEC);
	delete input_list;
	return SUCCESS;
}
