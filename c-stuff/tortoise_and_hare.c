#include<stdio.h>
#include<stdbool.h>


int findDuplicate(int* arr)
{
    int tortoise = arr[0];
    int hare = arr[0];
    printf("tortoise: %d, hare: %d\n", tortoise, hare);
    while (true)
    {
        tortoise = arr[tortoise];
        hare = arr[arr[hare]];
        printf("tortoise: %d, hare: %d\n", tortoise, hare);
        if (tortoise == hare)
        {
            break;
        }
    }
    int ptr1 = arr[0];
    int ptr2 = tortoise;

    printf("ptr1: %d, ptr2: %d\n", ptr1, ptr2);
    while (ptr1 != ptr2)
    {
        ptr1 = arr[ptr1];
        ptr2 = arr[ptr2];
        printf("ptr1: %d, ptr2: %d\n", ptr1, ptr2);
    }

    return ptr1;
}


int main()
{
    int arr[10] = {9, 1, 3, 8, 7, 3, 6, 4, 5, 2};
    printf("Dumplicate num is: %d\n", findDuplicate(arr));

    return 0;
}
