#include <stdio.h>

int main()
{
    // Whenever there's mismatch of types between two operands of an operator, implicit type conversion (or, casting) happens
    // e.g.
    char a = '5';
    printf("%d\n", a - '0'); // 5; a is a `char` while '0' is an `int`; char is IMPLICITLY CASTED to int
    // The rule of thumb is to convert it to a broader type.
    // There's a whole set of rules for implicit arithmetic conversion; see A.6.5 "Arithmetic Conversions" in the book.

    // ASSIGNMENT operator "="  will cast the right-hand side to the left-hand side type, so there might be info loss if the final type is more narrow! And no, compiler will NOT ERROR (but may warning)
    // Passing arguments to functions, or returning a different type than defined will also cast to that defined at the top of the function, if there's mismatch
    int x;
    x = 3.456; // casting to int (3) happens here; the fractional part is loss!

    // To make your life easier, you can always use EXPLICIT casting:
    printf("%.2f", (float)x); // explicitly casting to double here (3.000...)
}