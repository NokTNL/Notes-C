#include <stdio.h>
int main()
{
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;   /* lower limit of temperature scale */
    upper = 100; /* upper limit */
    step = 10;   /* step size */
    celsius = lower;

    printf("     C\t     F\n");
    while (celsius <= upper)
    {
        fahr = celsius * 9 / 5 + 32;
        printf("%6.1f\t%6.1f\n", celsius, fahr);
        celsius += step;
    }
}