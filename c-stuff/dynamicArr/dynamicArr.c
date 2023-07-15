#include <stdio.h>
#include <stdlib.h>

void addElem(int* arrPtr, int* N, int elem)
{
    arrPtr = (int*)realloc(arrPtr, sizeof(int) * ( *N + 1));
    *(arrPtr + *N) = elem;
    *N += 1;
}

void addSomething(int** arrPtr, int* N, int elem)
{
    *arrPtr = (int*)realloc(*arrPtr, sizeof(int) * (*N + 1));
    *(*arrPtr + *N) = elem;
    *N += 1;
}

int main()
{
    //int arr[1] = {1};    //stored in stack so realloc won't work
    //int N = 1;
    //int* arr = (int*)malloc(sizeof(int));

    //*(arr) = 1;
    //addElem(arr, &N,  3);

    int N = 0;
    int* arr = (int*)malloc(sizeof(int));

    addElem(arr, &N, 1);
    addElem(arr, &N, 2);
    addElem(arr, &N, 4);
    addElem(arr, &N, 8);
    addElem(arr, &N, 16);

    for (int i = 0; i < N; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int n = 0;
    int* array = NULL;

    addSomething(&array, &n, 69);
    printf("%d \n", array[0]);

    return 0;
}
