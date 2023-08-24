#include <ctype.h>
#include "buffer.c"

#define NOT_NUMBER 0
#define IS_NUMBER 1

/* Return NOT_NUMBER when it is not a number, return IS_NUMBER when a number is found, return EOF when reaches EOF */

int getint(int *number_pos)
{
    char c;
    signed char sign = 1;
    char has_sign_char = 0;

    /* Pre-processing */
    {
        while (isspace((c = getch()))) /* Skip all white space */
            ;

        if (c == EOF)
        {
            return EOF;
        }
        /* Dealing with signs */
        if (c == '-')
        {
            sign = -1;
        }
        if (c == '-' || c == '+')
        {
            has_sign_char = 1;
            ungetch(c);    /* buffer it first */
            c = getchar(); /* skip to next char */
        }
        /* After the sign character (if any) */
        if (!isdigit(c))
        {
            ungetch(c);
            return NOT_NUMBER;
        }
        /* Now it will be a digit */
        if (has_sign_char)
        {
            getch(); /* Dump the sign char from the buffer stack */
        }
    }

    /* Digit processing */
    {
        *number_pos = 0;
        do
        {
            *number_pos = *number_pos * 10 + (c - '0');
        } while (isdigit((c = getch())));

        if (c != EOF)
        {
            ungetch(c);
        }
        return IS_NUMBER;
    }
}