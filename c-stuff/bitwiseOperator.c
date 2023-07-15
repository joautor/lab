#include <stdio.h>
#include <stdlib.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte) \
    (byte & 0x80 ? '1' : '0'), \
    (byte & 0x40 ? '1' : '0'), \
    (byte & 0x20 ? '1' : '0'), \
    (byte & 0x10 ? '1' : '0'), \
    (byte & 0x08 ? '1' : '0'), \
    (byte & 0x04 ? '1' : '0'), \
    (byte & 0x02 ? '1' : '0'), \
    (byte & 0x01 ? '1' : '0')

void printInBinary(char* name, int N)
{
    printf("%s: %d = "BYTE_TO_BINARY_PATTERN" "BYTE_TO_BINARY_PATTERN" "BYTE_TO_BINARY_PATTERN" "BYTE_TO_BINARY_PATTERN"\n",
        name, N, BYTE_TO_BINARY(N >> 24), BYTE_TO_BINARY(N >> 16), BYTE_TO_BINARY(N >> 8), BYTE_TO_BINARY(N));
}

int solution(int N)
{

    int largest = 0;
    int temp = N;
    int shift = 0;
    int i;

    printInBinary("temp", temp);

    for (i = 1; i < 31; ++i)
    {
        int index = (temp & 1);
        printInBinary("index", index);

        temp = (temp >> 1) | (index << 30);
        printInBinary("temp >> 1", (temp >> 1));
        printInBinary("index >> 30", (index << 30));
        printInBinary("temp", temp);

        if (temp > largest)
        {
            largest = temp;
            shift = i;
        }
        if (i == 5)
        {
            break;
        }
        printf("-------------------------------------------\n");
    }
    return shift;
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Hello world! no arguments given :( exiting\n");
        exit(1);
    }

    int input = atoi(argv[1]);

    printf("highest k of %d is %d\n", input, solution(input));

    return 0;
}
