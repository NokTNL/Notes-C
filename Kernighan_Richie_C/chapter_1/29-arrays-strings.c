#include <stdio.h>
#define MAXCHAR 1000

// In function declaration/definitions, array arguments need NOT the length defined. This is determined by the caller (where the arrays would have been initialised)
void copy_str(char from[], char to[]);
int gettext(char s[], int limit);

int main()
{
    char from[MAXCHAR];
    char to[MAXCHAR];

    gettext(from, MAXCHAR);

    copy_str(from, to);
    printf("from: %s", from);
    printf("to: %s", to);
}

// In C, all arguments passed to functions are passed BY VALUE by default, i.e. the function has no access to the original variable and cannot mutate its argument.
// A big exception is ARRAYS - it is never passed by value, but the address of the beginning of the array (by REFERENCE).
int gettext(char s[], int limit)
{
    int i, c;
    for (i = 0; (c = getchar()) != EOF && i < limit - 1; ++i)
    {
        // Here you are MUTATING `from` because it is passed by reference
        s[i] = c;
    }
    // We declared the char array to be of length MAXCHAR, but how do we know where the useful values end? We need to attach a special character, '\0' (the NULL character)
    // This is the approach used by STRING CONSTANTS in C:
    //      "hello\n"
    //  --> this is a string constant, which essentially means the array
    //      'h', 'e', 'l', 'l', 'o', '\n', '\0'
    // In printf, if you print a string placeholder (%s), you MUST end the value somewhere with '\0' to make it work
    s[i] = '\0';
    return i;
}

void copy_str(char from[], char to[])
{
    int i;
    for (i = 0; (to[i] = from[i]) != '\0'; ++i)
        ;
}
