#include <stdio.h>

int main()
{

    /**
     * getchar()
     */
    // getchar() (from stdio.h) does the following: (https://stackoverflow.com/questions/57582732/using-getchar-in-c)
    // - It reads from the KEYBOARD by default in most OS
    // - The input stream is BUFFERED in most OS. When called, the OS will PAUSE the programme, then wait for the user to input a stream of characters until the user input `\n`, i.e. hitting the ENTER key
    // - Then getchar() will get the FIRST character of the stream and return it
    // - Each later call of getchar() will read the next character from the stream, and so on
    // - In most OS, if all the characters are exhausted (incl. the `\n`), it will PAUSE the programme again and wait for input until it sees `\n` again, then repeat the process
    //
    // *** About Ctrl-D *** (https://stackoverflow.com/questions/11944314/ctrl-d-didnt-stop-the-whilegetchar-eof-loop)
    // - If you are done and press Ctrl-D on an EMPTY LINE:
    //      - The OS will append EOF to the stream, and eject the buffer. Therefore it quits the while loop below.
    //      - If you attempt to read from a closed stdin, it will keep returning EOF as there's nothing to read
    // - If the line is NOT empty before pressing CTRL-D, e.g. `abc[CTRL-D]`:
    //      - This will NOT close the stream, but simply ejecting the buffer without creating a new line
    //      - When all the characters have exhausted, the OS will again PAUSE the programme at the next getchar()

    /**
     * putchar()
     */
    // putchar() prints a value in character format according to ASCII. Similar to printf() except it only prints one character at a time.

    int c; // To prevent the value of EOF to overflow in char thus clashing with possible printable characters, we use `int`. (https://c-faq.com/stdio/getcharc.html)
    c = getchar();
    while (c != EOF)
    {
        putchar(c);
        c = getchar(); // Get next character
    }
}

// NOTE: In C, the assignment operator `=` in an expression returns the left operand after the assignment. We can take advantage of that and make our programme more succinct:
int main_better()
{
    int c;
    while ((c = getchar()) != EOF) // (c = getchar()) returns the assigned new character
        putchar(c);
}