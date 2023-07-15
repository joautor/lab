#include <stdio.h>
#include <stdlib.h>


void foo(int* num)
{
    printf("inside foo->value: %d, %p\n", *num, num);
    int* temp;
    temp = (int*) malloc(sizeof(int) * 1);
    *temp = 69;

    num = temp;
    printf("inside foo->nvalue: %d, %p\n", *num, num);
}
int main()
{
    int test = 97;
    int* temp = &test;

    foo(temp);
    printf("outside foo ->value: %d, %p\n", *temp, temp);


    /*volatile int arr[1000];

    for (int i = 0; i < 1000; ++i)
    {
        arr[i] = i * 2;
    }

    volatile int x = 0;
    printf("x: %d\n", x);
    */

    return 0;
}
