#include <stdio.h>

int main()
{
    // In C, the SINGLE QUOTE expression 'A' is perceived as a NUMBER
    printf("%d\n", 'A' == 65);  // 1
    printf("%d\n", 'A' >= 'C'); // 0
}