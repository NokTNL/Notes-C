void print_before(char *strs_target[], int len)
{
    int i;
    for (i = 0; i < len; ++i)
    {
        printf("%s ", strs_target[i]);
    }
    printf("--> ");
}

void print_after(char *strs_target[], int len)
{
    int i;
    for (i = 0; i < len; ++i)
    {
        printf("%s ", strs_target[i]);
    }
    printf(", expected: ");
}

void print_expectation(char *strs_target[], char *strs_expected[], int len)
{
    int i;
    int is_equal = 1;

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