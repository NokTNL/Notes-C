#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define MAX_LENGTH 20

int main()
{
    int c, i, j, word_character_count;
    char is_last_one_in_word, is_blank_char;
    int character_counts[MAX_LENGTH];
    // Initialise the array, otherwise they can hold random values!
    for (i = 0; i < MAX_LENGTH; ++i)
        character_counts[i] = 0;

    is_last_one_in_word = FALSE;
    word_character_count = 0;

    while ((c = getchar()) != EOF)
    {
        is_blank_char = (c >= 32 && c <= 64) || c == '\t' || c == '\n';

        if (is_blank_char == TRUE && is_last_one_in_word == TRUE)
        {
            ++character_counts[word_character_count - 1];
            word_character_count = 0;
            is_last_one_in_word = FALSE;
        }
        if (is_blank_char)
            continue;
        // Not blanks (i.e. is valid word characters)
        ++word_character_count;
        is_last_one_in_word = TRUE;
    }
    // Print the result
    for (i = 0; i < MAX_LENGTH; ++i)
    {
        printf("%-2d ", i + 1);
        for (j = 0; j < character_counts[i]; ++j)
        {
            printf("*");
        }
        printf("\n");
    }
}