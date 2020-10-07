#ifndef IN_OUT_ARRAY_H
#define IN_OUT_ARRAY_H
#include <cstring>
#include "student.h"

enum RET_CODES {
	SUCCESS = 0,
	INPUT_ERROR,
	MALLOC_ERROR,
	OPEN_ERROR,
	READ_ERROR,
	UNKNOWN_ERROR
};

int input_arr (Student *, int, int, const char * filename);
void print_arr (FILE *, Student *, int, int);
#endif //IN_OUT_ARRAY_H
