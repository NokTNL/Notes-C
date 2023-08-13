#include <stdio.h>
int main()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
        case '\t':
            printf("\\t");
            break;
        // '\b' can be typed with Ctrl-H (^H). https://ss64.com/bash/syntax-keyboard.html
        case '\b':
            printf("\\b");
            break;
        case '\\':
            printf("\\\\");
            break;
        default:
            putchar(c);
        }
    }
}