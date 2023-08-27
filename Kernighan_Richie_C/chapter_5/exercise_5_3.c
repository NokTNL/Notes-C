#include <stdio.h>

char *my_strcat_arr(char *s, char *t);
char *my_strcat(char *s, char *t);
void my_strcpy(char *s, char *t);

int main()
{
    char s[100]; // Allocate memory first so we don't have bus error because of overflowing

    my_strcpy(s, "");
    printf("%s\n", my_strcat(s, "a")); // a

    my_strcpy(s, "a");
    printf("%s\n", my_strcat(s, "")); // a

    my_strcpy(s, "a");
    printf("%s\n", my_strcat(s, "b")); // ab

    my_strcpy(s, "abc");
    printf("%s\n", my_strcat(s, "de")); // abcde
}

// Array version
// Returns s for easier usage
// NOTE: There's NO gurantee that `s` won't overflow after concatenating t, resulting in undefined behaviour
char *my_strcat_arr(char *s, char *t)
{
    int i, j;
    i = j = 0;
    while (s[i])
        ++i;
    while ((s[i] = t[j]))
    {
        ++i;
        ++j;
    }
    return s;
}

// Pointer version;
char *my_strcat(char *s, char *t)
{
    char *temp = s; // Temporarily storing the pointer as we will increment s directly
    while (*s)      // You can evaluate if *s = 0 (0 == '\0') as the condition. This will stop at *s = '\0'
        ++s;
    while ((*s = *t)) // This will start at '\0' (and overwrites it) and stop at *t = '\0'
    {
        ++s;
        ++t;
    }
    return temp;
}

// My own utils to copy strings so we can reuse the same array to contain different content
// NOTE: doesn't guarantee that s won't overflow
void my_strcpy(char *s, char *t)
{
    while ((*s = *t))
    {
        ++s;
        ++t;
    }
}