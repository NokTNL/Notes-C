#include <stdio.h>

int strend(char *s, char *t);

int main()
{
    printf("%d\n", strend("a", "a"));
    printf("%d\n", !strend("a", "b"));
    printf("%d\n", strend("ab", "b"));
    printf("%d\n", !strend("ab", "c"));
    printf("%d\n", !strend("abc", "b"));
    printf("%d\n", strend("abc", "bc"));
    printf("%d\n", !strend("aac", "bc"));
    printf("%d\n", !strend("abcac", "bc"));
    printf("%d\n", !strend("ac", "aaabc"));
    printf("%d\n", !strend("abcd", "bc"));
    printf("%d\n", !strend("abc", "bcd"));
    printf("%d\n", strend("abcdebcd", "bcd"));
    printf("%d\n", strend("abcdbcd", "bcd"));
    printf("%d\n", !strend("abcde", "abcd"));
    printf("%d\n", !strend("ab", "bcdbcdab"));
    printf("%d\n", !strend("thomas", "marshall thomas"));
    printf("%d\n", strend("thomas robert", "robert"));
}

// Match from the end version
int strend(char *s, char *t)
{
    char *t_initial = t;

    while (*(s + 1))
        ++s;
    while (*(t + 1))
        ++t;

    while (*s == *t)
    {
        if (t == t_initial)
        {
            return 1;
        }
        --s;
        --t;
    }

    return 0;
}

// Match from the start version (By Tom)
int _strend_v2(char *s, char *t)
{
    char *t_initial = t;

    while (*s)
    {
        while (*s == *t)
        {
            if (!*s && !*t)
                return 1;
            ++s;
            ++t;
        }
        if (!*t)
        {
            t = t_initial;
            continue;
        }
        ++s;
    }
    return 0;
}

// Match from the start version (By me)
int _strend(char *s, char *t)
{
    char *t_initial = t;

    while (*s)
    {
        if (*s == *t && !*(s + 1) && !*(t + 1)) // Both *s and *t reaches the end of string next
        {
            return 1;
        }

        if (*s == *t && *(t + 1)) // *(t + 1) means t still has char to match next
        {
            ++s;
            ++t;
            continue;
        }
        else
        {
            ++s;
            t = t_initial;
        }
    }
    return 0;
}