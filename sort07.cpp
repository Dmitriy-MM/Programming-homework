#include "sorts.h"

void sort07 (Student arr[], int n)
{
    int i, j;
    int sup, inf, med;
    
    for (i = 1; i < n; i++)
    {
        if (arr[i-1] <= arr[i])
            continue;
        
        sup = i;
        inf = 0;
        while (inf != sup)
        {
            med = (inf + sup) / 2;
            if (arr[med] < arr[i])
            {
                inf = med + 1;
            }
            else
            {
                sup = med;
			}
		}

        for(j = i; j > sup; j--)
        {
            arr[j].swap (arr [j-1]);
        }
    }
}