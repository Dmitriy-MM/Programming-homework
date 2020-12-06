#include "in_out_array.h"


static void error_handler (int error_code, int i = -1)
{
	switch (error_code)
	{
		case Student::SUCCESS:
			break;
		case Student::READ_ERROR:
			printf ("Read error by i = %d\n", i);
			break;
		case Student::ALLOCATION_ERROR:
			printf ("Memory allocation error for student name; i = %d\n", i);
			break;
		default:
			printf ("Unknown error while reading student; i = %d\n", i);
			break;
	}
}

static int f (int formula, int n, int i)
{
	switch (formula)
	{
		case 1: return i;
		case 2: return n-i;
		case 3: return i/2;
		case 4: return n-i/2;
		default: return 0;
	}
}

int input_arr (Student arr[], int length, int formula, const char * filename = nullptr)
{
	FILE *fp = nullptr;
	int ret_code, i;
	if (formula == 0)
	{	
		if (filename == nullptr)
		{
			printf ("Error by reading from file\n");
			// error_handler (OPEN_ERROR, -1);
			return OPEN_ERROR;
		}
		fp = fopen (filename, "r");
		if (fp == nullptr)
		{
			printf ("Error by reading from file %s\n", filename);
			return OPEN_ERROR;
		}
		for (i = 0; i < length; i++)
		{
			ret_code = arr[i].read (fp);
			if (ret_code != Student::SUCCESS)
			{
				error_handler (ret_code, i);
				fclose (fp);
				return ret_code;
			}
		}
		fclose (fp);
	}
	else
	{
		const char * name = "Student";
		for (i = 0; i < length; i++)
		{
			// arr[i].set_name (name);
			// arr[i].set_value (f (formula, length, i));
			if (arr[i].name != nullptr)
				delete [] arr[i].name;
			arr[i].name = new char[strlen(name) + 1];
			strcpy (arr[i].name, name);
			arr[i].value = f (formula, length, i);
		}
	}
	return Student::SUCCESS;
}

void print_arr (FILE *fp, Student arr[], int len, int max_print)
{
	int i;
	
	len = len > max_print? max_print: len;
	for (i = 0; i < len; i++)
	{
		fprintf (fp, "%d) ", i);
		arr[i].print (fp);
		fprintf (fp,"\n");
	}
}