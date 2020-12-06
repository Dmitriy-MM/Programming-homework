#include <stdio.h>
#include <stdlib.h>
#include <ctime>

int main (int argc, char **argv)
{
	FILE *fp = nullptr;
	int i, n;
	int rnd;

	if (!(
		(argc == 3) &&
		(sscanf (argv[1], "%d", &n) == 1)
	))
	{
		printf ("Usage: %s num filename\n", argv[0]);	
		return 1;
	}
	fp = fopen (argv[2], "w");
	srand (time(0));
	for (i = 0; i < n; i++)
	{
		rnd = rand () % n;
		fprintf (fp, "Student %d\n", rnd);
	}
	
	fclose (fp);
	return 0;
}
