#include <stdio.h>
#include "getint.c"

int main()
{
    int num_array[2];
    int status;
    status = getint(num_array); // Or `&num_array[0]`, but they point to the same value really.
    printf("Status: %d\n", status);
    printf("%d\n", num_array[1]);
}