#include <stdio.h>
int main()
{
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;   /* lower limit of temperature scale */
    upper = 300; /* upper limit */
    step = 20;   /* step size */
    fahr = lower;

    printf("     F\t     C\n");
    while (fahr <= upper)
    {
        celsius = 5 * (fahr - 32) / 9;
        printf("%6.1f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}