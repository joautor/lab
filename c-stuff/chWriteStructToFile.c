#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Human {
    char name[32]; //char *name;
    int age; //int *age;
} Human;


int main()
{
    Human* hum;
    char *r;
    FILE* fp;

    printf("size of Human in bytes: %lu\n", (unsigned long) sizeof(Human));

    hum = (Human*) malloc(sizeof(Human));

    if (hum == NULL)
    {
        fprintf(stderr, "struct memory allocation error! Exiting program...\n");
        exit(1);
    }
    /*
    hum->name = (char*) malloc(sizeof(char) * 32);
    hum->age = (int*) malloc(sizeof(int));

    if (hum->name == NULL || hum->age == NULL)
    {
        fprintf(stderr, "Memory allocation error in struct data members! Exiting program...\n");
        exit(1);
    }
    */
    printf("Memory allocated!\n");

    printf("Enter your name: ");
    //scanf("%s", hum->name);
    r = fgets(hum->name, 32, stdin);
    if (r == NULL)
    {
        fprintf(stderr, "Input Error\n");
        exit(1);
    }
    hum->name[strcspn(hum->name,"\n")] = 0; //remove newline in the user input

    printf("Enter your age: ");
    scanf("%d", &hum->age);

    printf("Hi %s!\n", hum->name);
    printf("Your age is: %d\n", hum->age);
/*
    printf("size of hum->name: %lu\n", (unsigned long) sizeof(hum->name));
    printf("size of *(hum->name): %lu\n", (unsigned long) sizeof(*(hum->name)));
    printf("size of strlen(hum->name): %lu\n", (unsigned long) strlen(hum->name));

    char* testing = "123456789abc";
    char TESTING[69] = "123456789abc";

    printf("size of testing pointer: %d\n", (unsigned int) sizeof(testing));
    printf("size of testing: %d\n", (unsigned int) sizeof(*testing));
    printf("size of TESTING: %d\n", (unsigned int) sizeof(TESTING));
    printf("size of strlen(TESTING): %d\n", (unsigned int) strlen(TESTING));

    char board[20];
    strcpy(board,"Hello world!");
    printf("%s\n", board);
*/

    char* filename = "challengeFile.dat";

    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        fprintf(stderr, "Unable to create file\n");
        exit(1);
    }
    fwrite(hum, sizeof(Human), 1, fp);
    fclose(fp);


    return 0;
}

