#include <stdio.h>
#include <ctype.h>

int htoi(char s[]);

int main()
{
    char hex1[] = "164DE";
    int dec1 = htoi(hex1);
    printf("%d\n", dec1); // 91358

    char hex2[] = "1c4a6e";
    int dec2 = htoi(hex2);
    printf("%d\n", dec2); // 1854062

    char hex3[] = "0x1c4a6e";
    int dec3 = htoi(hex3);
    printf("%d\n", dec3); // 1854062

    char hex4[] = "0X1c4a6e";
    int dec4 = htoi(hex4);
    printf("%d\n", dec4); // 1854062
}

int htoi(char s[])
{
    int i = 0;
    int sum = 0;
    char current;

    if (s[0] == '0' && toupper(s[1]) == 'X')
    {
        i = 2; // Skip the hex num marker
    }

    for (i = i; isxdigit((current = s[i])); ++i)
    {
        // 0 - 9
        if (isdigit(current))
        {
            sum = sum * 16 + (current - '0');
        }
        // a - z, A - Z
        if (isalpha(current))
        {

            char upper = toupper(current);
            sum = sum * 16 + (upper - 'A' + 10);
        }
    }
    return sum;
}