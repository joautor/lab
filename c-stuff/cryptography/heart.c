#include <stdio.h>

#define BUFFER_SIZE       100
#define KEY                 4
#define ALPHABET_SIZE      26

int main()
{
    char input[100];
    int key;
    printf("Enter a key: ");
    scanf("%d", &key);
    printf("Enter a message: ");
    scanf("%s", input);

    printf("Encrypted message: ");
    int i = 0;
    while (input[i] != '\0') {
        //char c = input[i] + (KEY % ALPHABET_SIZE);
        char c = input[i] + (key % ALPHABET_SIZE);
        if (c > 'z') c = ((c - 'z') + ('a' - 1));
        printf("%c", c);
        ++i;
    }
    printf("\n");

    return 0;
}
