#include <stdio.h>


int main()
{
    char* mystring = "This is a message from me";
    char mystring2[15] = "Another message";
    char mystring3[] = "Testing one two three";

    printf("%s\n%s\n%s\n", mystring, mystring2, mystring3);

    int a;
    int b;
    int c;
    int x;
    a = 1;
    b = 2;
    c = 3;
    x = a + b + c;
    printf("%d", x);

    return 0;
}
