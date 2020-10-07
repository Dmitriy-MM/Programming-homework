#include <stdio.h>
#include <ctime>
#include <new>
#include "student.h"
#include "sorts.h"
#include "in_out_array.h"


int main (int argc, char * argv[])
{
	int lenA, lenB, lenC, ret_code, print_num;
	Student *arrA, *arrB, *arrC;
	const char * name1, *name2;
	clock_t time;
	
	//Ввод.
	if(!( 
		(argc == 6) &&
		(sscanf (argv[1], "%d", &print_num) == 1) &&
		(sscanf(argv[2], "%d", &lenA) == 1) && 
		(sscanf(argv[4], "%d", &lenB) == 1) 
	))
    {
        printf("Usage %s num_to_print len1 file1 len2 file2\n", argv[0]);
        return INPUT_ERROR;
    }
	name1 = argv[3], name2 = argv[5];
	lenC = lenA+lenB;
	
	//Выделение памяти под массив студентов.
	arrA = new Student[lenA];

	try
	{
		arrB = new Student[lenB];
	}
	catch (const std::bad_alloc& e)
	{
		printf ("Error memory allocation for array \"B\"\n");
		delete [] arrA;
		return MALLOC_ERROR;
	}
	try
	{
		arrC = new Student[lenA+lenB];
	}
	catch (const std::bad_alloc& e)
	{
		printf ("Error memory allocation for array \"C\"\n");
		delete [] arrA, delete [] arrB;
		return MALLOC_ERROR;
	}
	
	//Открытие файлов и считывание стундетов.
	ret_code = input_arr (arrA, lenA, 0, name1);
	if (ret_code != Student::SUCCESS)
	{
		delete [] arrA, delete [] arrB, delete [] arrC;
		return ret_code;
	}
	
	ret_code = input_arr (arrB, lenB, 0, name2);
	if (ret_code != Student::SUCCESS)
	{
		delete [] arrA, delete [] arrB, delete [] arrC;
		return ret_code;
	}
	
	//Печать массивов.
	printf ("Array A:\n");
	print_arr (stdout, arrA, lenA, print_num);
	printf ("Array B:\n");
	print_arr (stdout, arrB, lenB, print_num);
	
	//Запуск слияния массивов в arrC.
	time = clock ();
	sort02 (arrA, lenA, arrB, lenB, arrC);
	time = clock () - time;
	printf ("\n------------------\nArray C:\n");
	print_arr (stdout, arrC, lenC, print_num);
	printf ("Elapsed: %.2lfs\n", (double) time/CLOCKS_PER_SEC);
	
	delete [] arrA, delete [] arrB, delete [] arrC;
	return SUCCESS;
}
