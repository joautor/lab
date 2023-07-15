#include <stdio.h>

int main()
{
    unsigned int input;
    printf("Enter a number: ");
    scanf("%d", &input);

    /*do {
        printf("%d\n", input);
        input = input << 1;
    } while (input);
    */

    while (input)
    {
        printf("%d\n", input);
        input = input << 1;
    }
    return 0;
}
