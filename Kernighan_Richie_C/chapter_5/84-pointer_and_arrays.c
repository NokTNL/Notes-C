#include <stdio.h>

// In C, an array variable actually holds the address of the 0th element as the value, essentially functioning as a pointer to that 0th element.

int main()
{
    int *p;
    int arr[5]; // `arr` now holds the address of arr[0], or `&arr[0]`
    arr[0] = 12345;
    arr[1] = 67890;
    p = arr;              // this is legal!
    printf("%d\n", *p);   // 12345
    printf("%d\n", *arr); // 12345 <-- equivalant!

    // Array items are cells that are packed together in the memory. If a pointer p points to arr[0], (p+1) is the next adjacent address so it points to the next element in the array, and so on:
    printf("%d\n", *(p + 1));   // 67890
    printf("%d\n", *(arr + 1)); // 67890
    // In fact, the expression `arr[i]` is internally evaluated to `*(arr + i)` in C.

    /**
     * Differences between a pointer and an array variable
     */
    // 1. Once defined, an array variable always point to the same storage address in the memory. You cannot re-assign anything else to it to try to "mutate" it. Think of it like an immutable pointer with some special syntax for access (e.g. using arr[i] for accessing items)
    //
    // char arr[] = "Hello";
    // arr++; <-- illegal
    // arr = p; <-- illegal
    // arr = "bye"; <-- also illegal; array variables CANNOT be reassigned!
    //
    // - However, you can mutate the elements of the array if needed:
    // char arr[] = "Hello";
    // arr[0] = 'h'; <-- legal; this will become "hello"
    //
    // - Pointers are much freer in this aspect, because you can assign whatever values to it after definition
}

// 2. Pointers are passed around (incl. to functions as arguments) by VALUES! So you can mutate the pointer however you like in the function without worrying that it will affect the original pointer.

/* strcpy: copy t to s; pointer version */
void strcpy(char *s, char *t)
{
    int i;
    i = 0;
    while ((*s = *t) != '\0')
    {
        s++;
        t++;
    }
}

// In general, you shouldn't assign a random integer to a pointer (although it still compiles), EXCEPT 0, which is guranteed to never be a valid address. For convenience, <stdio.h> defines the symbolic constant `NULL` == 0 to be the "undefined" value for pointers.