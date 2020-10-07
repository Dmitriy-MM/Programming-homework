#include "sorts.h"

void sort06 (Student arr[], int n)
{
    int i, j, k;
    
    for (i = 1; i < n; i++)
    {
		//Было <=.
        if (arr[i-1] < arr[i])
            continue;
        
        // buffer = arr[i];
        for(j = 0; j < i; j++)
        {
            if(arr[i] < arr[j])
            {
                for (k = i; k > j; k--)
                {
                    // arr[k] = arr[k-1];
					arr[k].swap (arr[k-1]);
                }
                break;
            }
        }
        // arr[j] = buffer;
    }
}