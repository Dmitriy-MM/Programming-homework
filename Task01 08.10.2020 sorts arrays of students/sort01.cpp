#include "sorts.h"

int sort01 (Student* arr, int length, Student * elem)
{
    int sup, inf, med;
    //Нижняя и верхняя границы поиска - 0 и длина массива соответственно.
    inf = 0;
    sup = length;

    while (inf != sup)
    {
        med = (inf + sup) / 2;
        if (arr[med] < *elem)
        {
            inf = med + 1;
        }
        else
        {
            sup = med;
        }
    }

    return sup;
}