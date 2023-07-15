#include <stdio.h>

int main()
{
    volatile unsigned char mychar = 250;
    for (int i = 0; i < 256; ++i)
    {
        printf("%d \n", mychar);
        ++mychar;

        if (mychar ==  7)
        {
            break;
        }
    }
    return 0;
}
