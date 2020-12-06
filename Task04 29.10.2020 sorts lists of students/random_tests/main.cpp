#include <stdio.h>
#include <cstdlib>
#include <ctime>
// #include <stdlib.h>

int main (int argc, char ** argv)
{
	FILE *fp = nullptr;
	int n = 0, i, r, range;
	if (!(
		(argc == 4) &&
		((n = atoi (argv[2])) != 0) &&
		((range = atoi (argv[3])) != 0)
	))
	{
		printf ("Usage: %s filename n range\n", argv[0]);
		return -1;
	}
	 fp = fopen (argv[1], "w");
	//fp = stdout;
	if (fp == nullptr)
	{
		printf ("Не получилось открыть файл %s на запись\n", argv[1]);
		return -2;
	}
	for (i = 0; i < n; i++)
	{
		r = rand() % range;
		fprintf (fp, "a %d\n", r);
	}
	fclose (fp);
	return 0;
}
