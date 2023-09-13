#include <stdio.h>
#include <string.h>
#include "qsort.c"

void sort_and_assert_str_arrays(char *strs_target[], char *strs_expected[], int len);

int main()
{
    char *test_strs_1[10] = {"b", "a"};
    char *expect_strs_1[10] = {"a", "b"};
    sort_and_assert_str_arrays(test_strs_1, expect_strs_1, 2);

    char *test_strs_2[10] = {"a", "b"};
    char *expect_strs_2[10] = {"a", "b"};
    sort_and_assert_str_arrays(test_strs_2, expect_strs_2, 2);

    char *test_strs_3[10] = {"c", "a", "b"};
    char *expect_strs_3[10] = {"a", "b", "c"};
    sort_and_assert_str_arrays(test_strs_3, expect_strs_3, 3);
}

void sort_and_assert_str_arrays(char *strs_target[], char *strs_expected[], int len)
{
    int i;
    char is_equal = 1;

    for (i = 0; i < len; ++i)
    {
        printf("%s ", strs_target[i]);
    }
    printf("--> ");

    qsort_str(strs_target, 0, len - 1);

    for (i = 0; i < len; ++i)
    {
        printf("%s ", strs_target[i]);
    }
    printf(", expected: ");

    for (i = 0; i < len; ++i)
    {
        printf("%s ", strs_expected[i]);
        if (strcmp(strs_target[i], strs_expected[i]) != 0)
        {
            is_equal = 0;
        }
    }

    if (!is_equal)
    {
        printf("\t!! FAILED");
    }
    printf("\n");
}