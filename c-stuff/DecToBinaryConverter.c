#include <stdio.h>

#define BIT_16      16
#define BIT_8       8
#define BIT_4       4
#define BIT_32      32

void printInBinary(int value, int bits)
{
    int x = value;
    char binary[bits+1];
    binary[bits--] = '\0';
    
    while (bits >= 0) {
        binary[bits] =  (x & 1) ? '1' : '0';
        x = x >> 1;
        --bits;
    }
    printf("binary value of %3d is %s\n", value, binary);
}

int main()
{
    char* result = NULL;
    for (int i = 0; i < 16; ++i) {
        printInBinary(i, BIT_4);
    }
    return 0;
}