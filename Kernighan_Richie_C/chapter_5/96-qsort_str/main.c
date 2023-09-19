#include <stdio.h>
#include <string.h>
#include "qsort.c"
#include "assertion.c"

void sort_and_assert_str_arrays(char *strs_target[], char *strs_expected[], int len);

int main()
{
    char *test_strs_1[10] = {"b", "a"};
    char *expect_strs_1[10] = {"a", "b"};
    sort_and_assert_str_arrays(test_strs_1, expect_strs_1, 2);

    char *test_strs_2[10] = {"a", "b"};
    char *expect_strs_2[10] = {"a", "b"};
    sort_and_assert_str_arrays(test_strs_2, expect_strs_2, 2);

    char *test_strs_3[10] = {"b", "c", "a"};
    char *expect_strs_3[10] = {"a", "b", "c"};
    sort_and_assert_str_arrays(test_strs_3, expect_strs_3, 3);

    char *test_strs_4[10] = {"a", "c", "b"};
    char *expect_strs_4[10] = {"a", "b", "c"};
    sort_and_assert_str_arrays(test_strs_4, expect_strs_4, 3);

    char *test_strs_5[10] = {"c", "b", "a"};
    char *expect_strs_5[10] = {"a", "b", "c"};
    sort_and_assert_str_arrays(test_strs_5, expect_strs_5, 3);

    char *test_strs_6[10] = {"c", "a", "b"};
    char *expect_strs_6[10] = {"a", "b", "c"};
    sort_and_assert_str_arrays(test_strs_6, expect_strs_5, 3);

    char *test_strs_7[10] = {"a", "b", "c"};
    char *expect_strs_7[10] = {"a", "b", "c"};
    sort_and_assert_str_arrays(test_strs_7, expect_strs_7, 3);

    char *test_strs_8[10] = {"b", "a", "c"};
    char *expect_strs_8[10] = {"a", "b", "c"};
    sort_and_assert_str_arrays(test_strs_8, expect_strs_8, 3);
}

void sort_and_assert_str_arrays(char *strs_target[], char *strs_expected[], int len)
{
    print_before(strs_target, len);

    qsort_str(strs_target, 0, len - 1);

    print_after(strs_target, len);

    print_expectation(strs_target, strs_expected, len);
}