// Note: add -pthread flag during compilation. eg:
// gcc -pthread -o hello hello.c

#include <stdio.h>
#include <pthread.h>        // for thread related functions
#include <unistd.h>         // for sleep() function
#include <stdlib.h>         // for free() function


void* myTurn(void* arg) {
    // while(1) {
    for (int i = 0; i < 8; i++) {
        sleep(1);
        printf("My Turn! %i\n", i);
    }
    int* input = (int*)arg;                         // Cast arg to int pointer
    int* output = (int*)malloc(sizeof(int));        // Allocate heap memory
    *output = (*input) * 2;
    return output;
    // return NULL;
}

void yourTurn() {
    // while(1) {
    for (int i = 0; i < 3; i++) {
        sleep(2);
        printf("Your Turn! %i\n", i);
    }
}

int main()
{
    pthread_t newThread;

    int input = 7;
    pthread_create(&newThread, NULL, myTurn, &input);
    // pthread_create(&newThread, NULL, myTurn, NULL);
    // myTurn();
    yourTurn();

    int* output = NULL;
    // pthread_join(newThread, NULL);
    pthread_join(newThread, (void*)&output);
    if (output != NULL) {
        printf("Input: %i, Output: %i\n", input, *output);
        free(output);
    }

    return 0;
}
