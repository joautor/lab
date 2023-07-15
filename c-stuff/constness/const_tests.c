/*Notes:

Read in backwards (as driven by Clockwise/Spriral Rule):

int*                         pointer to int
int cont *                   pointer to constant int
int * const                  constant pointer to an int
int const * const            constant pointer to a constant int

Now the first const can be on either side of the type so:

const int*  ==  int const*
const int* const == int const * const

*/

#include <stdio.h>

typedef struct {
    int magicnumber;
} MyStruct;


void foo(const MyStruct* const ms)
{
    // ms->magicnumber = 69;     // Not permitted if const Mystruct* ms;
    MyStruct ms2;
    ms2.magicnumber = 143;
    // ms = &ms2;               // Not permitted if MyStruct* const ms;

    printf("magicnumber: %i", ms->magicnumber);
}


void foo2(const int* bar)
{
   //  *bar = 123;
   printf("bar: %i\n", *bar);
}

int main()
{
    printf("Hello World!\n");
    MyStruct ms;
    ms.magicnumber = 777;
    foo(&ms);

    const int test = 97;
    const int* ptr = &test;
    foo2(&test);

    return 0;
}
