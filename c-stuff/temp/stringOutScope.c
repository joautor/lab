#include <stdio.h>

const char* createString()
{
    // char* mystring is stored in  the .rodata of the object file; 
    // the same segment where the .text section of the object file gets dumped, which
    // has Read and Exec permissions, but not Write;
    const char* myString = "HelloWorld"; 
    //const char myString[] = "HelloWorld"; // char arrays are stored in stack, thus myString will be invalid after executing this function
    return myString;
}

int main()
{
    const char* pString = createString();
    if (pString == NULL) printf("pString is NULL\n");
    else {
        printf("pString is not NULL\n");
        printf("string is %s!\n", pString);
    }
    return 0;
}
