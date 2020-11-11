#include <stdio.h>
#include <ctime>
#include "tree.h"

enum RET_CODES {
	SUCCESS = 0,
	WRONG_INPUT
};

#define TASK1 1
#define TASK2 1
#define TASK3 1
#define TASK4 1
#define TASK5 1

int main (int argc, char ** argv)
{
	int max_print_level, k, ret_code, result;
	char * filename = nullptr;
	clock_t time;
	Tree input_tree;
	
	if (!(
		(argc == 4) &&
		(sscanf (argv[1], "%d", &max_print_level) == 1) &&
		(sscanf (argv[3], "%d", &k) == 1)
	))
	{
		printf ("Usage: %s max_print_level filename\n", argv[0]);
		return WRONG_INPUT;
	}
	filename = argv[2];
	

	ret_code = input_tree.read (filename);
	if (ret_code != Tree::SUCCESS)
	{
		Tree::error_handler (ret_code);
		return ret_code;
	}
	input_tree.print (max_print_level);
#if TASK1
	time = clock ();
	result = input_tree.task01 (k);
	time = clock () - time;
	printf ("Task = %d Result = %d Elapsed = %.2lf\n", 1, result, (double) time/CLOCKS_PER_SEC);
#endif	
#if TASK2
	time = clock ();
	result = input_tree.task02 (k);
	time = clock () - time;
	printf ("Task = %d Result = %d Elapsed = %.2lf\n", 2, result, (double) time/CLOCKS_PER_SEC);
#endif	
#if TASK3
	time = clock ();
	result = input_tree.task03 (k);
	time = clock () - time;
	printf ("Task = %d Result = %d Elapsed = %.2lf\n", 3, result, (double) time/CLOCKS_PER_SEC);
#endif	
#if TASK4
	time = clock ();
	result = input_tree.task04 (k);
	time = clock () - time;
	printf ("Task = %d Result = %d Elapsed = %.2lf\n", 4, result, (double) time/CLOCKS_PER_SEC);
#endif	
#if TASK5
	time = clock ();
	result = input_tree.task05 (k);
	time = clock () - time;
	printf ("Task = %d Result = %d Elapsed = %.2lf\n", 5, result, (double) time/CLOCKS_PER_SEC);
#endif
	return SUCCESS;
}
