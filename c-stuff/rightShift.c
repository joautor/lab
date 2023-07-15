#include <stdio.h>

int main()
{
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);


    do {
        printf("%d\n", input);
        input = input >> 1;
    } while (input);

    return 0;
}
