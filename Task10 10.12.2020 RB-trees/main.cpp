#include <stdio.h>
#include <ctime>

#include "student.h"
#include "rb_tree.h"


#define TASK1 1
#define TASK2 1
#define TASK3 1
#define TASK4 1
#define TASK5 1

enum RET_CODES {
	SUCCESS = 0,
	WRONG_INPUT
};

int main (int argc, char * argv[])
{
	//m - order of B-tree, k - param of tasks. 
	int k, max_print;
	clock_t time;
	int result;
	int ret = -1;
	
	if (!(
		(argc == 4) &&
		(sscanf (argv[1], "%d", &max_print) == 1) &&
		(sscanf (argv[2], "%d", &k) == 1)
	))
	{
		printf ("Usage: %s max_print k-task_param filename\n", argv[0]);
		return WRONG_INPUT;
	}
	RB_tree<Student> * input_tree = new RB_tree <Student>;
	time = clock ();
	ret = input_tree->read (argv[3]);
	time = clock () - time;
	if (ret != RB_tree<Student>::SUCCESS)
	{
		RB_tree<Student>::error_handler (ret);
		return ret;
	}
//	printf ("tree has been reading %.2lfs\n", (double) time/CLOCKS_PER_SEC);
//	printf ("Is tree good? 1 = good, 0 = bad: %d\n", input_tree->check_tree ());
	if (max_print > 0)
		printf ("H - root(head), R - right, L - left, b - black,  r - red\n");
	input_tree->print (max_print);
#if TASK1
	time = clock ();
	result = input_tree->task01 (k);
	time = clock () - time;
	printf ("%s : Task = %d Result = %d Elapsed = %.2lf\n", argv[0], 1, result, (double) time/CLOCKS_PER_SEC);
#endif	
#if TASK2
	time = clock ();
	result = input_tree->task02 (k);
	time = clock () - time;
	printf ("%s : Task = %d Result = %d Elapsed = %.2lf\n", argv[0], 2, result, (double) time/CLOCKS_PER_SEC);
#endif	
#if TASK3
	time = clock ();
	result = input_tree->task03 (k);
	time = clock () - time;
	printf ("%s : Task = %d Result = %d Elapsed = %.2lf\n", argv[0], 3, result, (double) time/CLOCKS_PER_SEC);
#endif	
#if TASK4
	time = clock ();
	result = input_tree->task04 (k);
	time = clock () - time;
	printf ("%s : Task = %d Result = %d Elapsed = %.2lf\n", argv[0], 4, result, (double) time/CLOCKS_PER_SEC);
#endif	
#if TASK5
	time = clock ();
	result = input_tree->task05 (k);
	time = clock () - time;
	printf ("%s : Task = %d Result = %d Elapsed = %.2lf\n", argv[0], 5, result, (double) time/CLOCKS_PER_SEC);
#endif
	delete input_tree;
	return SUCCESS;
}
