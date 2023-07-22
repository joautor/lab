#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define MAX_NUM_PHRASE              5
#define MAX_NUM_WRONG_GUESS         3
#define MAX_LIFE                    3


//============== For Debugging =================
void DisplayFlags(int flags[], int N)
{
    for (int i = 0; i < N; i++) {
        printf("%d", flags[i]);
    }
    printf("\n");
}
//==============================================


bool Evaluate(char input, char* phrase, int flags[], int N)
{
    bool isFoundMatch = false;
    for (int i = 0; i < N; i++) {
        if (flags[i] == 1) continue;
        if (phrase[i] == input) {
            flags[i] = 1;
            isFoundMatch = true;
        }
    }
    return isFoundMatch;
}

void DisplayPhrase(char* phrase, int flags[], int N)
{
    system("clear");
    printf("\n\n");
    for (int i = 0; i < N; i++) {
        if (flags[i] == 0) printf("_");
        else printf("%c", phrase[i]);
    }
    printf("\n\n");
}

void DisplayStatus(int life)
{
    printf("life: ");
    for (int i = 0; i < life; i++) {
        printf("* ");
    }
    printf("\n");
}

int CountHiddenLetters(int flags[], int N)
{
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (flags[i] == 0) count++;
    }
    return count;
}


void InitPhrase(char* magicPhrase[])
{
    int nSize = 0;
    magicPhrase[nSize++] = "HELLO WORLD";
    magicPhrase[nSize++] = "GOOD MORNING BABY";
    magicPhrase[nSize++] = "TODAY MY LIFE BEGINS";
    magicPhrase[nSize++] = "WHAT IS THE MEANING OF LIFE";
    magicPhrase[nSize++] = "THE DAY AFTER TOMORROW";
    assert(nSize <= MAX_NUM_PHRASE);
}


int GenerateRandomIndex()
{
    time_t t;
    srand((unsigned) time(&t));
    return (rand() % MAX_NUM_PHRASE);
}

int main()
{
    char* magicPhrase[MAX_NUM_PHRASE];
    InitPhrase(magicPhrase);

    int iMagicIndex = GenerateRandomIndex();

    char* curPhrase = magicPhrase[iMagicIndex];
    int N = (int)strlen(curPhrase);
    int flags[N];
    memset(flags, 0,sizeof(flags));

    int life = MAX_LIFE;

    Evaluate(' ', curPhrase, flags, N);  // Show all blank spaces
    DisplayPhrase(curPhrase, flags, N);
    DisplayStatus(life);


    while (CountHiddenLetters(flags, N) > 0) {
        char input;
        printf("Enter a letter: ");
        scanf(" %c", &input);
        printf("Last input: %c", input);
        if (!Evaluate(input, curPhrase, flags, N)) {
            life--;
        }
        DisplayPhrase(curPhrase, flags, N);
        DisplayStatus(life);
        if (life <= 0) {
            break;
        }
    }
    if (life > 0) printf("You Win!\n");
    else {
        printf("Game over! You lose!\n");
        printf("The phrase was: %s\n", curPhrase);
    }
}
