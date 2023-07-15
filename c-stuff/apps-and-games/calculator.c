#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size = 50;
    char inputBuffer[size];
    int bytes_read;
    printf("Enter an expression: e.g. 34 + 35\n\t==> ");
    // scanf("%s", inputBuffer);
    bytes_read = getline(inputBuffer, &size, stdin);
    if (bytes_read == -1) {
        printf("ERROR\n");
        exit(-1);
    }
    printf("\nResult: %s\n", inputBuffer);
    return 0;
}
