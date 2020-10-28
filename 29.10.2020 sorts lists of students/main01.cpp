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
	int max_print;
	const char * filename;
	List * input_list = nullptr;
	int ret_code;
	clock_t time;
	
	if (!(
		(argc == 3) && 
		(sscanf (argv[1], "%d", &max_print) == 1)
	))
	{
		printf ("Usage: %s max_print filename\n", argv[0]);
		return INPUT_ERROR;
	}
	filename = argv[2];
	
	input_list = new List;
	ret_code = input_list->read (filename);
	if (ret_code != List::SUCCESS)
	{
		List::error_handler (ret_code);
		delete input_list;
		return ret_code;
	}
	printf ("Before:\n");
	input_list->print (max_print);
	
	time = clock ();
	input_list->sort01 ();
	time = clock () - time;
	
	printf ("---------------------------\nAfter:\n");
	input_list->print (max_print);
	printf ("Num of lesser than prev: %d\n", input_list->get_less_than_prev ());
	printf ("Elapsed %.2lfs\n", (double) time/CLOCKS_PER_SEC);
	delete input_list;
	return SUCCESS;
}
