#include "sorts.h"

int sort03 (Student arr[], int n, Student * x)
{
    int i, j;
    
    j = n-1;
    i = 0;
    while(i < j)
    {
        if (arr[i] < (*x))
        {
            i++;
            continue;
        }
        if ((*x) <= arr[j])
        {
            j--;
            continue;
        }
        if (i <= j)
        {
            arr[i].swap (arr[j]);
            j--;
            i++;
        }
    }
    i = (i == n-1)? n: i;
    
    return i;
}
