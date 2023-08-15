#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
int get_line(char line[], int lim);
void copy(char to[], char from[]);

/* print the longest input line */
int main()
{
    int line_len;   /* current line length */
    int line_accum; /* For temporarily accumulating length of line for those > MAXLINE */
    int max_len;    /* maximum length seen so far */
    int is_first_part_of_line;
    char first_part_of_line[MAXLINE]; /* Temporary storage for first part of very long line */
    char current_line[MAXLINE];       /* current input line */
    char longest_line[MAXLINE];       /* longest line saved here */
    max_len = line_len = line_accum = 0;
    is_first_part_of_line = 1;
    // This won't stop until it hits a line with zero length (i.e. only EOF)
    while ((line_len = get_line(current_line, MAXLINE)) > 0)
    {
        line_accum += line_len; /* Accumulate char count (especially useful when overflowing) */

        int is_line_overflowing = line_len >= MAXLINE - 1;

        if (is_first_part_of_line)
        {
            copy(first_part_of_line, current_line);
        }
        if (is_line_overflowing)
        {
            is_first_part_of_line = 0; // Next line won't be the first part of line
            continue;                  /* Go straight to next part of the line */
        }
        /* If not overflowing, process the numbers and get ready for the next input */
        if (line_accum > max_len) /* New record made! */
        {
            max_len = line_accum;
            copy(longest_line, first_part_of_line);
        }
        /* Clean up before next input */
        line_accum = 0;
        is_first_part_of_line = 1;
        printf("Longest line so far: %d\n", max_len);
    }
    if (max_len > 0) /* there was a line */
        printf("Longest line is %d characters long: %s", max_len, longest_line);
    return 0;
}
/* get_line: read a line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;
    // This function will return when:
    // - Exceeded the limit - 1 (needs padding '\0' at last)
    // - hits EOF
    // - hits `\n`
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}