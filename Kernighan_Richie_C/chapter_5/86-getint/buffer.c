#include <stdio.h>
#define MAX_BUFFER 10

char buffer[MAX_BUFFER];
char buffer_position = 0; /* next empty position in the buffer array */

/* get one character from the buffer, or from stdin if buffer is empty */
char getch(void)
{
    int i;
    char c;
    if (buffer_position > 0)
    {
        c = buffer[0];
        /* Shifting the stack */
        for (i = 0; i < buffer_position; ++i)
        {
            buffer[i] = buffer[i + 1];
        }
        --buffer_position; /* Not cleaning up the buffer; consider those as junk info and only rely on buffer_position */
        return c;
    }
    return getchar();
}

/* Push one character into the buffer stack */
void ungetch(char c)
{
    if (buffer_position >= MAX_BUFFER)
    {
        printf("Buffer size exceeded MAX_BUFFER (%d)\n", MAX_BUFFER);
        return;
    }
    buffer[buffer_position++] = c;
}