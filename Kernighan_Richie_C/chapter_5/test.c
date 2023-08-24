#include <stdio.h>

int main()
{
    char *p = "Hello";
    *p = 'h'; // <-- even this can cause error
}