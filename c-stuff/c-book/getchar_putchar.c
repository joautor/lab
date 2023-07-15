#include <stdio.h>

int main()
{
    char a, b = 'b';
    printf("using getchar(): \n");
    a = getchar();

    printf("using putchar(): \n");
    putchar(b); // prints a character each time it is called

    printf("\nresult: a = %c, b = %c\n, EOF = %d\n", a, b, EOF);


    int c;
    while ((c = getchar()) != EOF) // infinite loop?
    {
        putchar(c);
    }

    return 0;
}
