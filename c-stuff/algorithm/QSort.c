#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
    return *((int*)a) - *((int*)b); // Cast to int pointer, get reference, and compute difference between two ints
}

int main()
{
    int arr[10] = {97, 1, 5, 2, 69, 45, 21, 13, 17, 88};

    qsort(arr, 10, sizeof(int), compare);

    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
