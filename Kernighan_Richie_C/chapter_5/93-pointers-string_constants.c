int main()
{
    // If you inline declare a string without assigning it to any variables, it will be a STRING CONSTANT.
    printf("Hello World!"); // "Hello World!" is a string constant
    // Declaring a string constant will create a character array somewhere in the memory.
    // When evaluating the string constant, it yields the address of that array
    // So in the printf example above, you are actually passing the address of the {'H', 'e', ..... 'o', '\0'} array to printf. Again, this is DIFFERENT from other constants in that you are passing by reference into the function instead of providing a copy of the value.

    char str[] = "Hello";
    char *p = "Hello"; // <-- You are just passing an address that points to that array of characters

    /**
     * There's another difference between a pointer and an array here:
     */
    // Unlike the array VARIABLES (which will always have the memory reserved for it), C does NOT gurantee the immutability of string constants. If you try to mutate that string constant later on, (again) the behaviour is undefined :(
    // char *p = "Hello";
    // p[0] = 'h'; <-- no it won't always work; it compiles but may result in errors
    // *p = 'h'; <-- same
}