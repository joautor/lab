#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//#define MAX_NUM                 55
#define MAX_NUM                 58
#define MIN_NUM                 1
#define WINNING_COMBO_NUM       6

#define INVALID_NUM             -1

bool isDuplicate(int num, int* arNum, int size)
{
    if (num == INVALID_NUM) return true;
    for (int i = 0; i < size; ++i) {
        if (arNum[i] == num) return true;
    }
    return false;
}

int main()
{
    int arWinningCombo[WINNING_COMBO_NUM];
    for (int i = 0; i < WINNING_COMBO_NUM; ++i) {
        arWinningCombo[i] = INVALID_NUM;
    }

    time_t t;
    srand((unsigned) time(&t));
    int index = 0;
    do {
        if (index >= WINNING_COMBO_NUM) break;

        const int number = rand() % (MAX_NUM + 1);
        if (number < MIN_NUM ) continue;
        if (isDuplicate(number, arWinningCombo, WINNING_COMBO_NUM)) continue;

        arWinningCombo[index++] = number;

    } while (true);

    // Display the result
    for (int i = 0; i < WINNING_COMBO_NUM; ++i) {
        printf("%2d ", arWinningCombo[i]);
    }
    printf("\n");

    return 0;
}
