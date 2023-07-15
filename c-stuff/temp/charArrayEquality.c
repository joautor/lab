#include <stdio.h>
#include <string.h>

void printAndGetSize(char* str)
// void printAndGetSize(char str[])
{
    printf("str: %s, ", str);
    printf("size: %lu, ", sizeof(str));
    printf("len: %lu\n", strlen(str)); 
}

int main()
{
    char s1[10] = "helloworld";
    char s2[] = "hello";
    if (s1 == s2) {
        printf("s1 and s2 are equal\n");
    } else {
        printf("s1 and s2 are NOT equal\n");
    }
    // s1++;     // compile error:  lvalue required as increament operand
    printf("after s1++: %s\n", s1);

    char* s3 = "hello";

    char s4[5] = {'a', 'b', 'c', 'd', '\0'};

    printAndGetSize(s1);
    printAndGetSize(s2);
    printAndGetSize(s3);
    printAndGetSize(s4);
    printf("-----------------\n");
    printf("s1: %s, %lu\n", s1, sizeof(s1));
    printf("s2: %s, %lu\n", s2, sizeof(s2));
    printf("s3: %s, %lu\n", s3, sizeof(s3));
    printf("s4: %s, %lu\n", s4, sizeof(s4));
    return 0;
}
