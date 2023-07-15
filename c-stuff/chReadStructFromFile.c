#include <stdio.h>
#include <stdlib.h>


typedef struct Human {
    char name[32];
    int age;
} Human;


int main()
{
    Human* hum;
    int r;
    FILE* fp;

    printf("size of Human in bytes: %lu\n", (unsigned long) sizeof(Human));

    hum = (Human*) malloc(sizeof(Human));

    if (hum == NULL)
    {
        fprintf(stderr, "struct memory allocation error! Exiting program...\n");
        exit(1);
    }

    printf("Memory allocated!\n");

    char filename[] = "challengeFile.dat";

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        fprintf(stderr, "file open error\n");
        exit(1);
    }

    r = fread(hum, sizeof(Human), 1, fp);
    if (r == 0)
    {
        fprintf(stderr, "Read error\n");
        exit(1);
    }

    printf("After reading\n");

    printf("Hi %s!\n", hum->name);
    printf("Your age is: %d\n", hum->age);

    fclose(fp);

    return 0;
}


