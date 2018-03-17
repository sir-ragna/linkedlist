
An example from stack overflow to demonstrate header files.
https://stackoverflow.com/questions/7109964/creating-your-own-header-file-in-c


**foo.h**

    #ifndef FOO_H_   /* Include guard */
    #define FOO_H_

    int foo(int x);  /* An example function declaration */

    #endif // FOO_H_

**foo.c**

    #include "foo.h"  /* Include the header (not strictly necessary here) */

    int foo(int x)    /* Function definition */
    {
        return x + 5;
    }

**main.c**

    #include <stdio.h>
    #include "foo.h"  /* Include the header here, to obtain the function declaration */

    int main(void)
    {
        int y = foo(3);  /* Use the function here */
        printf("%d\n", y);
        return 0;
    }

**Compile with GCC**

    gcc -o my_app main.c foo.c
