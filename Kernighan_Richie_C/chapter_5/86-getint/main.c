#include <stdio.h>
#include "getint.c"

int main()
{
    int num_array[2];
    int status;
    status = getint(&num_array[0]);
    printf("%d\n", status);
}