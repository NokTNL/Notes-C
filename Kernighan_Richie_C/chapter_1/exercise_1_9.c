#include <stdio.h>
#define TRUE 1
#define FALSE 0
int main()
{
    int c;
    char has_blank_before = FALSE;

    while ((c = getchar()) != EOF)
    {
        if (c != ' ')
        {
            putchar(c);
            has_blank_before = FALSE;
            continue;
        }
        if (!has_blank_before)
        {
            putchar(c);
            has_blank_before = TRUE;
        }
    }
}