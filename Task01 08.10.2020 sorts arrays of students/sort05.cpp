#include "sorts.h"

void sort05 (Student arr[], int n)
{
    int i, j, min;
    
    for (i = 0; i < n; i++)
    {
        for (j = i+1, min = i; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        arr[i].swap(arr[min]);
    }
}
