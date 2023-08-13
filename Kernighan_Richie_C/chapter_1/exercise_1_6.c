#include <stdio.h>
int main()
{
    int is_not_eof = 1;
    while (is_not_eof)
    {
        is_not_eof = getchar() != EOF;
        printf("%i\n", is_not_eof);
    }
}