#include <stdio.h>
#include <ctime>

#include "student.h"
#include "list_2.h"
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



int List_2::m = 1;
int List_2::r = 0;
int main (int argc, char * argv[])
{
	int max_print_level, m, ret_code, result;
	char * filename = nullptr;
	clock_t time;
	Tree<Student> * input_tree_student = nullptr;
	Tree<List_2> * input_tree_list2 = nullptr;
	
	if (!(
		(argc == 4) &&
		(sscanf (argv[1], "%d", &max_print_level) == 1) &&
		(sscanf (argv[3], "%d", &m) == 1)
	))
	{
		printf ("Usage: %s max_print_level filename m\n", argv[0]);
		return WRONG_INPUT;
	}
	filename = argv[2];
	
	List_2::set_m (m);
	List_2::set_r (max_print_level);
	
	printf ("STUDENTS\n------------------------------\n");
	
	input_tree_student = new Tree<Student>;
	ret_code = input_tree_student->read (filename);
	if (ret_code != Tree<Student>::SUCCESS)
	{
		Tree<Student>::error_handler (ret_code);
		delete input_tree_student;
		return ret_code;
	}
	
	
	input_tree_student->print (max_print_level);
#if TASK1
	time = clock ();
	result = input_tree_student->task01 ();
	time = clock () - time;
	printf ("%s : Task = %d Result = %d Elapsed = %.2lf\n", argv[0], 1, result, (double) time/CLOCKS_PER_SEC);
#endif	
#if TASK2
	time = clock ();
	result = input_tree_student->task02 ();
	time = clock () - time;
	printf ("%s : Task = %d Result = %d Elapsed = %.2lf\n", argv[0], 2, result, (double) time/CLOCKS_PER_SEC);
#endif	
#if TASK3
	time = clock ();
	result = input_tree_student->task03 ();
	time = clock () - time;
	printf ("%s : Task = %d Result = %d Elapsed = %.2lf\n", argv[0], 3, result, (double) time/CLOCKS_PER_SEC);
#endif	
#if TASK4
	time = clock ();
	result = input_tree_student->task04 ();
	time = clock () - time;
	printf ("%s : Task = %d Result = %d Elapsed = %.2lf\n", argv[0], 4, result, (double) time/CLOCKS_PER_SEC);
#endif	
#if TASK5
	time = clock ();
	result = input_tree_student->task05 ();
	time = clock () - time;
	printf ("%s : Task = %d Result = %d Elapsed = %.2lf\n", argv[0], 5, result, (double) time/CLOCKS_PER_SEC);
#endif
	delete input_tree_student;
	
	
	printf ("LIST_2\n------------------------------\n");
	input_tree_list2 = new Tree<List_2>;
	ret_code = input_tree_list2->read (filename);
	if (ret_code != Tree<List_2>::SUCCESS)
	{
		Tree<List_2>::error_handler (ret_code);
		delete input_tree_list2;
		return ret_code;
	}
	
	input_tree_list2->print (max_print_level);
#if TASK1
	time = clock ();
	result = input_tree_list2->task01 ();
	time = clock () - time;
	printf ("%s : Task = %d Result = %d Elapsed = %.2lf\n", argv[0], 1, result, (double) time/CLOCKS_PER_SEC);
#endif	
#if TASK2
	time = clock ();
	result = input_tree_list2->task02 ();
	time = clock () - time;
	printf ("%s : Task = %d Result = %d Elapsed = %.2lf\n", argv[0], 2, result, (double) time/CLOCKS_PER_SEC);
#endif	
#if TASK3
	time = clock ();
	result = input_tree_list2->task03 ();
	time = clock () - time;
	printf ("%s : Task = %d Result = %d Elapsed = %.2lf\n", argv[0], 3, result, (double) time/CLOCKS_PER_SEC);
#endif	
#if TASK4
	time = clock ();
	result = input_tree_list2->task04 ();
	time = clock () - time;
	printf ("%s : Task = %d Result = %d Elapsed = %.2lf\n", argv[0], 4, result, (double) time/CLOCKS_PER_SEC);
#endif	
#if TASK5
	time = clock ();
	result = input_tree_list2->task05 ();
	time = clock () - time;
	printf ("%s : Task = %d Result = %d Elapsed = %.2lf\n", argv[0], 5, result, (double) time/CLOCKS_PER_SEC);
#endif
	delete input_tree_list2;
	return SUCCESS;
}
