#include <stdio.h>

void reverse(char[]);

int main()
{
    char single_line[7] = "abcde\n"; // ! Remember, it is "abcde\n\0", so 7 slots needed!
    reverse(single_line);
    printf("%s", single_line); // edcba\n\0

    char two_lines[12] = "abcde\nfghi\n";
    reverse(two_lines);
    printf("%s", two_lines); // edcba\nihgf\n\0

    char three_lines[16] = "abcde\nfghi\nxyz\n";
    reverse(three_lines);
    printf("%s", three_lines); // edcba\nihgf\nzyx\n\0
}

void reverse(char s[])
{
    int i;
    int start, stop; /* Index of start & end of each line; stop is at \n */
    char temp[1000];

    start = stop = 0;

    while (s[start] != '\0')
    {
        for (i = start; s[i] != '\n'; ++i)
            ;
        stop = i;

        /* Reverse s into temp */
        for (i = start; i < stop; ++i)
        {
            temp[start + stop - i - 1] = s[i];
        }
        /* Copy temp back to s */
        for (i = start; i < stop; ++i)
        {
            s[i] = temp[i];
        }
        start = stop + 1;
    }
}