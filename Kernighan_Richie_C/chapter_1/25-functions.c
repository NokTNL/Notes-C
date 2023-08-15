#include <stdio.h>

// Function DECLARATION (or function prototype) allows you to use a function BEFORE its actual definition. You just need to provide the types of parameters and return type to expect.
// Using a function before declaration will result in compilation error.
int add_two(int, int);

int main()
{
    printf("%d\n", add_two(1, 2)); // <-- this is used before the definition below
}

// Actual function DEFINITION
int add_two(int a, int b)
{
    return a + b;
}