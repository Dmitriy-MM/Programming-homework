#include <stdio.h>
#include <ctime>
#include <new>
#include "student.h"
#include "sorts.h"
#include "in_out_array.h"


int main (int argc, char * argv[])
{
	int length, formula, print_num;
	int ret_code;
	Student *arr, *second_arr;
	const char * name = nullptr;
	clock_t time;
	
	//Ввод.
	if (!(
		((argc == 4) || (argc == 5)) && 
		(sscanf (argv[1], "%d", &length) == 1) &&
		(sscanf (argv[2], "%d", &print_num) == 1) &&
		(sscanf (argv[3], "%d", &formula) == 1) &&
		(	
			((argc == 4) && (formula != 0)) || ((argc == 5) && (formula == 0))
		)
	))
	{
		printf ("Usage: %s length num_to_print formula_index [filename (formula_index = 0)]\n", argv[0]);
		return INPUT_ERROR;
	}
	if (formula == 0)
		name = argv[4];
	
	//Выделение памяти под массив студентов.
	arr = new Student[length];

	try
	{
		second_arr = new Student[length];
	}
	catch (const std::bad_alloc& e)
	{
		printf ("Memory allocation error for second array\n");
		delete [] arr;
		return MALLOC_ERROR;
	}
	ret_code = input_arr (arr, length, formula, name);
	if (ret_code != Student::SUCCESS)
	{
		delete [] arr, delete [] second_arr;
		return ret_code;
	}
	
	//Печать массива.
	print_arr (stdout, arr, length, print_num);
	
	//Запуск сортировки слиянием.
	time = clock ();
	sort08 (arr, second_arr, length);
	time = clock () - time;

	//Печать массива после сортировки.
	printf ("\n----------------------\nSorted:\n");
	print_arr (stdout, arr, length, print_num);
	printf ("Elapsed: %.2lfs\n", (double) time/CLOCKS_PER_SEC);
	
	delete [] arr, delete [] second_arr;
	return SUCCESS;
}
