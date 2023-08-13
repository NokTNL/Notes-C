#include <stdio.h>
#define LOWER 0   /* lower limit of temperature scale */
#define UPPER 300 /* upper limit */
#define STEP 20   /* step size */

int main()
{
    float fahr, celsius;

    printf("     F\t     C\n");
    for (fahr = UPPER; fahr >= LOWER; fahr -= STEP)
    {
        celsius = 5 * (fahr - 32) / 9;
        printf("%6.1f\t%6.1f\n", fahr, celsius);
    }
}