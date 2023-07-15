#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define AR_SIZE 10

typedef enum Direction{left, right} Dir;

void dumpContent(int* array, int N)
{
    printf("\n");
    for (int i = 0; i < N; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void shift(int* array, int N, Dir dir, int steps)
{
    int multiplier = (dir == right) ? 1 : -1;
    int stepsWithDir = steps * multiplier;
    int temp[N];
    for (int i = 0; i < N; ++i) {
        int newLocation = (i + stepsWithDir) % N;
        newLocation = (newLocation < 0) ? N + newLocation : newLocation;
        temp[newLocation] = array[i];
    }
    memcpy(array, temp, (N * sizeof(int)));
}

int main()
{
    int array[AR_SIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    while (true) {
        dumpContent(array, AR_SIZE);
        printf("0 - Exit\n1 - Shift Right\n2 - Shift Left\nSelect action: ");
        int selectedAction;
        int steps = 0;
        scanf("%d", &selectedAction);

        if ((selectedAction == 0) || (selectedAction > 2)) {
            printf("Exiting...\n");
            break;
        }
        printf("Enter steps: ");
        scanf("%d", &steps);
        shift(array, AR_SIZE, ((selectedAction == 1) ? right : left), steps);
    }
}
