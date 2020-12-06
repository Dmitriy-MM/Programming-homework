#include "sorts.h"


void sort09(Student arr[], int n)
{
    int i = 0, j = n-1;
	int index_x;

    while (n > 1)
    {
		index_x = n/2;
        while (i <= j)
        {
            while (arr[index_x] > arr[i])
                i++;
            while (arr[j] > arr[index_x])
                j--;
            if (i <= j)
            {
                arr[i].swap (arr[j]);
				if (i == index_x)
					index_x = j;
				else if (j == index_x)
					index_x = i;
				i++;
				j--;
            }
        }
        if (n - i - 1 < j)
        {
            sort09(arr + i, n - i);
            i = 0;
            n = j + 1;
        }
        else
        {
            sort09(arr, j + 1);
            arr += i;
            n -= i;
            i = 0;
            j = n - 1;
        }
    }
}
