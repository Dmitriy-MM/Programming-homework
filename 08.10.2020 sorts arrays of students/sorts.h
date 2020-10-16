#include "student.h"

//Нахождение позиции для "elem" в упорядоченном arr.
int sort01 (Student* arr, int length, Student * elem);
//Из упорядоченных arrA и arrB сделать упорядоченный	arrC.
void sort02 (Student arrA[], int nA, Student arrB[], int nB, Student arrC[]);
//Перестановка элементов неубывающего массива так, чтобы были сначале меньше x, потом больше x.
 int sort03 (Student arr[], int n, Student * x);
//Пузырек.
void sort04 (Student arr[], int n);
//Сортировка нахождением минимума.
void sort05 (Student arr[], int n);
//Сортировка линейной вставкой.
void sort06 (Student arr[], int n);
//Сортировка двоичной вставкой.
void sort07 (Student arr[], int n);
//Сортировка Неймана (merge sort).
void sort08 (Student arrA[], Student arrB[], int n);
//"Быстрая" сортировка.
void sort09 (Student arr[], int n);
//Турнирная сортировка.
void sort10 (Student arr[], int n);