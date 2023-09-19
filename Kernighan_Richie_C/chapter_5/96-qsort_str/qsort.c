#include <string.h>
#include <stdlib.h>

void qsort_str(char *str_pointers[], int left_index, int right_index);
void swap_items(char *arr[], int a_index, int b_index);
void swap_int(int *a, int *b);

void qsort_str(char *str_pointers[], int left_index, int right_index)
{
    if (right_index - left_index < 1) // Array of length < 1
        return;

    if (right_index - left_index == 1) // Array of length 2
    {
        if (strcmp(str_pointers[left_index], str_pointers[right_index]) > 0)
        {
            swap_items(str_pointers, left_index, right_index);
        }
        return;
    }

    // Initialisation
    int pivot = left_index;
    ++left_index;
    char is_left_bigger = 0;
    char is_right_smaller = 0;

    // Go through from left & from right
    if (strcmp(str_pointers[left_index], str_pointers[pivot]) > 0)
    {
        is_left_bigger = 1;
    }
    if (strcmp(str_pointers[right_index], str_pointers[pivot]) < 0)
    {
        is_right_smaller = 1;
    }

    if (is_left_bigger && is_right_smaller)
    {
        swap_items(str_pointers, left_index, right_index);
        // Move pivot to middle
        swap_items(str_pointers, pivot, left_index);
        swap_int(&pivot, &left_index);
    }
    else if (!is_left_bigger && is_right_smaller)
    {
        // Move pivot to end
        swap_items(str_pointers, pivot, right_index);
        swap_int(&pivot, &right_index);
        swap_int(&left_index, &right_index); // Because in the last step, right_index becomes < left_index
    }
    else if (!is_left_bigger && !is_right_smaller)
    {
        // Move pivot to middle
        swap_items(str_pointers, pivot, left_index);
        swap_int(&pivot, &left_index);
    }
    else
    {
        // Do nothing
    }

    qsort_str(str_pointers, left_index, pivot - 1);
    qsort_str(str_pointers, pivot + 1, right_index);
}

void swap_items(char *arr[], int a_index, int b_index)
{
    char *temp;

    temp = arr[a_index];
    arr[a_index] = arr[b_index];
    arr[b_index] = temp;
}

void swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}