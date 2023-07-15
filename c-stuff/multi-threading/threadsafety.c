#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

#define BIG_ 1000000000UL
#define BIG 1000UL

uint32_t counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; 


void* count_to_big(void* arg)
{
    for (uint32_t i = 0; i < BIG; i++) {
        pthread_mutex_lock(&lock);
        printf("Counter = %u\n", counter);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main()
{
    pthread_t thread_0;
    pthread_create(&thread_0, NULL, count_to_big, NULL);
    count_to_big(NULL); 
    pthread_join(thread_0, NULL);
    printf("Done. Counter = %u\n", counter);
    return 0;

}

// Notes: Race condition
// Happens when threads trying to write on memory/resource at the same time.
// Threads are basically racing on which one will be the first or last to modefy the shared data or access shared memory
// This would cause undefined behavior and incorrect calculation results
