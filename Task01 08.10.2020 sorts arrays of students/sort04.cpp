#include "sorts.h"

void sort04 (Student arr[], int n)
{
    int i, j, c = 0;   
    
    j = 0;
    while(n > 1)
    {
        j=0;
        
        while(j < n)
        {
            c = 0;
            for(i = j; i < n-1; i++)
            {
                if (arr[i+1] < arr[i])
                {
                    arr[i].swap (arr[i+1]);
                    c++;
                }
            }
            if (c == 0)
                return;
            if(i == (n-1))
            {
                break;
            }
            
        }
        n--;
    }
}