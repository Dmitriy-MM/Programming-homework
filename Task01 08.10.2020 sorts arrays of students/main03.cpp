#include <stdio.h>
#include <ctime>
#include "student.h"
#include "sorts.h"
#include "in_out_array.h"


int main (int argc, char * argv[])
{
	int length, formula, print_num, student_value;
	int ret_code, result;
	Student *arr, *input_student;
	const char * name = nullptr, *student_name = nullptr;
	clock_t time;
	
	if (!(
		((argc == 6) || (argc == 7)) && 
		(sscanf (argv[1], "%d", &length) == 1) &&
		(sscanf (argv[2], "%d", &print_num) == 1) &&
		(sscanf (argv[3], "%d", &formula) == 1) &&
		(
			((argc == 7) && (sscanf (argv[6], "%d", &student_value) == 1)) ||
			((argc == 6) && (sscanf (argv[5], "%d", &student_value) == 1))
		) &&
		(	
			((argc == 6) && (formula != 0)) || ((argc == 7) && (formula == 0))
		)
	))
	{
		printf ("Usage: %s length num_to_print formula_index [filename (formula_index = 0)] student_name student_value\n", argv[0]);
		return INPUT_ERROR;
	}
	if (argc == 6)
		student_name = argv[4];
	else
		student_name = argv[5];
	
	input_student = new Student (student_name, student_value);
	
	if (formula == 0)
		name = argv[4];
	//Выделение памяти под массив студентов.
	arr = new Student[length];
	
	//Открытие файла и считывание стундетов.
	ret_code = input_arr (arr, length, formula, name);
	if (ret_code != Student::SUCCESS)
	{
		delete [] arr, delete input_student;
		return ret_code;
	}
	
	//Печать массива.
	printf ("Inputted student:\n");
	print_arr (stdout, input_student, 1, 1);
	printf ("Array:\n");
	print_arr (stdout, arr, length, print_num);
	
	//Запуск поиска позиции студента.
	time = clock ();
	result = sort03 (arr, length, input_student);
	time = clock () - time;
	
	//Печать массива после сортировки.
	printf ("Sorted:\n");
	print_arr (stdout, arr, length, print_num);
	
	printf ("------------------\nPosition is %d\n", result);
	printf ("Elapsed: %.2lfs\n", (double) time/CLOCKS_PER_SEC);
	
	delete [] arr, delete input_student;
	return SUCCESS;
}
