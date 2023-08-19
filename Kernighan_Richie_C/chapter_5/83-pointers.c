#include <stdio.h>

int main()
{
    // A pointer is a VARIABLE that stores the ADDRESS of another variable (the size of it doesn't matter, handled by the hardware architecture).

    // Declaration:
    int *p; // !! The type is `int *`, which means "a pointer of int"

    // To get the address of a variable, or array element, use `&`
    int n = 0;
    p = &n;

    // To get the variable back from a pointer, use the DEREFERENCING operator, `*`:
    *p = 3;            // *p is equivalent to `n` here; think like "the pointee of p"
    printf("%d\n", n); // 3 <-- the value changed!
}
