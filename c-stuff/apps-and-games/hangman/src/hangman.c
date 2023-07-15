#include "stdio.h"
#include "stdbool.h"
#include "assert.h"

#define MAX_NUM_PHRASE              5
#define MAX_NUM_WRONG_GUESS         3


int main()
{
    char* magicPhrase[MAX_NUM_PHRASE];
    int nSize = 0;
    magicPhrase[nSize++] = "HELLO WORLD";
    magicPhrase[nSize++] = "GOOD MORNING";
    magicPhrase[nSize++] = "TODAY MY LIFE BEGINS";
    magicPhrase[nSize++] = "WHAT IS THE MEANING OF LIFE";
    magicPhrase[nSize++] = "THE DAY AFTER TOMORROW";
    assert(nSize <= MAX_NUM_PHRASE);

    int iMagicIndex = 3; // 3 for now for testing; should be randomized

    while (true) {
        //Print out each char
        char* c = magicPhrase[iMagicIndex];
        while (*c != '\0') {
            printf("%c ", *c);
            c++;
        }
        break;
    }
}
