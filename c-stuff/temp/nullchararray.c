#include <stdio.h>
#include <string.h>


int main()
{
    char* test1 = "Hello World";
    char* test2 = NULL;//"Hello World";

    printf("start\n");

    if (strcmp(test1, test2) == 0) printf("match!\n");
    else printf("not match!\n");

    printf("end\n");

    return 0;
}
