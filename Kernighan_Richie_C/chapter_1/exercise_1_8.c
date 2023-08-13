#include <stdio.h>
int main()
{
    int c;
    long count = 0;

    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
        case ' ':
        case '\n':
        case '\t':
            ++count;
            break;
        }
    }
    printf("%li \n", count);
}