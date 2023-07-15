#include <stdio.h>
#include <stdlib.h>

//void* malloc(size_t size) ---> size is buffer size in bytes, return's  the address otherwise NULL
//NULL is a macro for 0


/*Memory Allocation Functions

malloc() -> allocates uninitialized storage
calloc() -> allocates and initializes storages -- zeroes or null characters
realloc() -> dynamically resizes an existing buffer
          -> contents of the old buffer are copied to the new
          -> an existing bufer can be resized by specifying its adress both as an argument and as the return value 
          -> doesn't initialize the added storage
free() -> recover memory or starage on an allocated buffer
       -> after using it, set a pointer's valuet to NULL
       -> It's not necessary to free() a buffer before a program exits
       -> always free memory in a function or when a buffer is no longer needed, and the program continues to run.
*/

int main()
{
    int a[5] = { 1, 2, 3, 4, 5};
    int x, *p;

    p = a;
    for(x = 0; x < 5; ++x)
    {
        //printf("%p\n", &a[x]);
        printf("%p\n", p);
        //printf("%d\n", *p);
        printf("%d\n", *(p + x));
       // ++p;
    }

    char * storage;
    int size = 16;

    storage = (char*) malloc(sizeof(char) * size + 1); // +1 is full null character in the end of string
    if (storage == NULL)
    {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    printf("Memory allocated successfully\n");

    int* intPtr;
    int intSize = 5;

    //intPtr = (int*)calloc(size, sizeof(int));
    //intPtr = calloc(size, sizeof(*intPtr));
    intPtr = (int*) malloc(sizeof(int) * 5);
    if (intPtr == NULL)
    {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    fprintf(stderr, "int Memory allocation success!\n");

    for (x = 0; x < 5; x++)
    {
        *(intPtr + x) = x * x;
    }

    intPtr = (int*) realloc(intPtr, sizeof(int) * 7);

    if (intPtr == NULL) {
        exit(1);
    }
    printf("Buffer re-sized, memory reallocated!\n");

    *(intPtr + 5) = 69;
    *(intPtr + 6) = 97;

    for (x = 0; x < 7; x++)
    {
        printf("%d\n", *(intPtr + x));
    }

    //char* charPtr = (char*)calloc(5+1, sizeof(char));
    char* charPtr = (char*) malloc(sizeof(char) * 5 + 1);
    if (charPtr == NULL)
    {
        printf("Error!\n");
        exit(1);
    }
    printf("---%s---\n", charPtr);

    free(charPtr);
    free(intPtr);
    free(storage);
    puts("Memory Freed");

    return 0;
}
