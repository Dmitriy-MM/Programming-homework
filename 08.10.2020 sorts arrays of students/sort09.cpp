#include "sorts.h"

void sort09(Student arr[], int n)
{
    int i = 0, j = n-1;
	Student x;
	
    while (n > 1)
    {
		x = arr[n / 2];
        while (i <= j)
        {
            while (x > arr[i])
                i++;
            while (arr[j] > x)
                j--;
            if (i <= j)
            {
                arr[i].swap (arr[j]);
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