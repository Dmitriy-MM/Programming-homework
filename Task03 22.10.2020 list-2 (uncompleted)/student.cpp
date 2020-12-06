#include <stdio.h>
#include <cstring>
#include "student.h"


int Student::init (char * name, int value)
{
	this->value = value;
	if (name != nullptr)
	{
		size_t len = strlen (name);
		this->name = new char[len+1];
		if (this->name == nullptr)
			return ALLOCATION_ERROR;
		strcpy (this->name, name);
	}
	else
		this->name = nullptr;
	return SUCCESS;
}

void Student::clean ()
{
	if (name != nullptr)
	{
		delete [] name;
		name = nullptr;
	}
	value = 0;
}

int Student::read (FILE * fp) 
{
	const int LEN = 1234;
	char buf[LEN];
	int val;

	if (fscanf(fp, "%s%d", buf, &val) != 2)
		return READ_ERROR;
	clean();
	return init (buf, val);
}

void Student::swap (Student& x)
{
	char *n; int v;
	n = name; v = value;
	name = x.name; value = x.value;
	x.name = n; x.value = v;
}

void Student::print (FILE *fp) const 
{
	if (fp != nullptr)
	{
		if (name != nullptr)
			fprintf (fp, "%s %d", name, value);
		else
			fprintf (fp, "empty object");
	}
}

void Student::set_name (const char * new_name)
{
	if (name != nullptr)
		delete [] name;
	name = new char[strlen(new_name) + 1];
	strcpy (name, new_name);
}

void Student::set_value (int value)
{
	this->value = value;
}

Student::Student () 
{
	name = nullptr;
	value = 0;
}

Student::Student (const char *name  = nullptr, int value = 0) 
{
	if (name != nullptr)
	{
		this->name = new char[strlen (name)+1];
		strcpy (this->name, name);
	}
	this->value = value;
}

//Конструктор копирования.
Student::Student (const Student& x) 
{
	init (x.name, x.value);
}

//Конструктор перемещения.
Student::Student (Student&& x) 
{
	value = x.value;
	name = x.name;
	x.name = nullptr;
	x.value = 0;
}

Student::~Student () {
	clean ();
}

Student& Student::operator = (const Student& x) 
{
	if (this == &x)
		return const_cast <Student&> (x);
	clean ();
	init (x.name, x.value);
	return *this;
}

Student& Student::operator = (Student&& x) 
{
	this->value = x.value;
	this->name = x.name;
	x.name = nullptr;
	x.value = 0;
	return *this;
}


int Student::operator < (const Student &right_operand)
{
	int res;
	res = strcmp (name, right_operand.name);
	if (res == 0)
		return (value - right_operand.value < 0);
	return (res < 0);
}

int Student::operator > (const Student& right_operand)
{
	// return const_cast <Student&> (right_operand) < (*this);
	int res;
	res = strcmp (name, right_operand.name);
	if (res == 0)
		return (value - right_operand.value > 0);
	return (res > 0);
}

int Student::operator <= (const Student &right_operand)
{
	int res;
	res = strcmp (name, right_operand.name);
	if (res == 0)
		return (value - right_operand.value <= 0);
	return (res <= 0);
}

int Student::operator >= (const Student &right_operand)
{
	int res;
	res = strcmp (name, right_operand.name);
	if (res == 0)
		return (value - right_operand.value >= 0);
	return (res >= 0);
}

int Student::operator != (const Student &right_operand)
{
	int res;
	res = strcmp (name, right_operand.name);
	if (res == 0)
		return (value - right_operand.value != 0);
	return (res != 0); //The same as return 1.
}

int Student::operator == (const Student &right_operand)
{
	int res;
	res = strcmp (name, right_operand.name);
	if (res == 0)
		return (value - right_operand.value == 0);
	return (res == 0); //The same as return 0.
}