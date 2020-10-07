#include "sorts.h"

void sort02 (Student arrA[], int nA, Student arrB[], int nB, Student arrC[])
{
    int i, j, k;
   
    i = j = k = 0;
    while ((i < nA) && (j < nB))
    {
        if(arrA[i] < arrB[j])
        {
            arrC[k] = arrA[i];
            i++;
        }
        else
        {
            arrC[k] = arrB[j];
            j++;
        }
        k = i + j;
    }
   
    while(i < nA)
    {
        arrC[k] = arrA[i];
        k++;
        i++;
    }
    while(j < nB)
    {
        arrC[k] = arrB[j];
        k++;
        j++;
    }
}
