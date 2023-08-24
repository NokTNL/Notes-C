// An external (i.e. global) variable cannot be used before DEFINITION, EXCEPT when you use the `extern` DECLARATION first.
// - DECLARATION is merely saying "I will have a variable of this type" to the compiler, but no storage is set aside for it yet.
int my_func(int a, int b); // this is declaration (no function body defined yet)
int main()
{
    extern int n; // <-- this is declaration
    n = 4;
}
// - DEFINITION (or initialisation) will set aside stoage for it (and act as declaration at the same time):
int n; // <-- this is definition
int my_func(int a, int b)
{
    // ... function body         <--- this is definition
}