#include <stdio.h>

#include "ExternVar.h"

extern char autorMessage2[10];
// extern char autorMessage1[10];

// extern int x;

int main()
{
    printf("message is: %s\n", autorMessage1);
    printf("message2 is: %s\n", autorMessage2);
    // printf("x is: %d\n", x);
    return 0;
}
