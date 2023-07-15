#include <stdio.h>
#include <stdlib.h>


int main()
{
    int* intCall = (int*)calloc(1, sizeof(int));
    int* intMall = (int*)malloc(sizeof(int) * 1);

    printf("calloc int %d\n", *intCall);
    printf("malloc int %d\n", *intMall);

    char* charCall = (char*)calloc(8, sizeof(char));
    char* charMall = (char*)malloc(sizeof(char) * 8);

    printf("calloc char* %s\n", charCall);
    printf("malloc char* %s\n", charMall);


    return 0;
}
