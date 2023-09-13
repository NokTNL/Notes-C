#include <string.h>
#include <stdlib.h>

void qsort_str(char *str_pointers[], int left_index, int right_index);
void swap(char *arr[], int a_index, int b_index);

void qsort_str(char *str_pointers[], int left_index, int right_index)
{
    if (strcmp(str_pointers[left_index], str_pointers[right_index]) > 0)
    {
        swap(str_pointers, left_index, right_index);
    }
}

void swap(char *arr[], int a_index, int b_index)
{
    char *temp;

    temp = arr[a_index];
    arr[a_index] = arr[b_index];
    arr[b_index] = temp;
}