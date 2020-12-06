#ifndef STUDENT_H
#define STUDENT_H
#include <stdio.h>

class Student
{
	private: 
		char * name = nullptr;
		int value = 0;
		int init (char *, int);
		void clean ();
	public:
		enum ERRORS {
			SUCCESS = 0,
			READ_ERROR,
			ALLOCATION_ERROR
		};
		int get_value () const {
			return value;
		}
		const char * get_name () const {
			return (const char *)(name);
		}
		int read (FILE *);
		void print (FILE * fp = stdout) const;
		void swap (Student&);
		void set_name (const char *);
		void set_value (int);
		
		Student ();
		Student (const char *, int);
		Student (const Student& x);
		Student (Student&& x);
		~Student ();
		Student& operator = (const Student& x);
		Student& operator = (Student&& x);
		int operator < (const Student&);
		int operator > (const Student&);
		int operator <= (const Student&);
		int operator >= (const Student&);
		int operator != (const Student&);
		int operator == (const Student&);
		friend int input_arr (Student *, int, int, const char *);
};
#endif //STUDENT_H
