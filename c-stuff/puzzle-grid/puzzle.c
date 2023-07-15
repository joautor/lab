#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define COL_MAX          4
#define ROW_MAX          4
#define COL_MIN          0
#define ROW_MIN          0

#define INVALID_INDEX    -1
#define GRID_SIZE        5
#define NUM_CHARS        25

typedef struct {
    int col;
    int row;
} Coordinate;

typedef enum {LEFT, UP, RIGHT, DOWN} Direction;

int getIndexFromCoordinate(int col, const int row)
{
    if ((col > COL_MAX) || (col < COL_MIN) || (row > ROW_MAX) || (row < ROW_MIN)) {
        return INVALID_INDEX;
    }
    return ((GRID_SIZE * col) + row);
}

void printGrid(const char* sequence)
{
    for (int i = ROW_MIN; i <= ROW_MAX; ++i) {
        for (int j = COL_MIN; j <= COL_MAX; ++j) {
            int index = getIndexFromCoordinate(j, i);
            if (index == INVALID_INDEX) continue;
            printf("%c ", sequence[index]);
        }
        printf("\n");
    }
}

Coordinate getAdjustcentCoordinate(const Coordinate* coord, Direction dir)
{
    Coordinate adjCoord = (*coord);
    switch(dir) {
        case LEFT: --adjCoord.col; break;
        case UP: --adjCoord.row; break;
        case RIGHT: ++adjCoord.col; break;
        case DOWN: ++adjCoord.row; break;
    }
    return adjCoord;
}

char* getStringValue(char ch)
{
    static char ex[10] = "Exit";
    static char sel[10] = "Self";
    static char pat[10] = "Path Block";
    static char tre[10] = "Treasure";
    static char inv[10] = "Invalid";
    switch(ch) {
        case '0': return ex;
        case '1': return sel;
        case '*': return pat;
        case '+': return tre;
        default: return inv;
    }
}

void analyzeCoordinate(int col, int row, const char* sequence)
{
    Coordinate orgCoord = {col, row};
    Coordinate adjCoords[4];
    adjCoords[0] = getAdjustcentCoordinate(&orgCoord, LEFT);
    adjCoords[1] = getAdjustcentCoordinate(&orgCoord, UP);
    adjCoords[2] = getAdjustcentCoordinate(&orgCoord, RIGHT);
    adjCoords[4] = getAdjustcentCoordinate(&orgCoord, DOWN);

    char* adjNames[4] = {"LEFT", "UP", "RIGHT", "DOWN"};

    for (int i = 0; i < 4; ++i) {
        int index = getIndexFromCoordinate(down.col, down.row);
        printf("%s: %s\n", adjNames[i], (index != INVALID_INDEX) ? getStringValue(sequence[index]) : "None");
    }
}

void removeWhiteSpaces(char* output, char* input)
{
    int N = (int)strlen(input);
    int outputIndex = 0, inputIndex = 0;

    while (inputIndex < N) {
        char c = input[inputIndex];
        while (c == ' ' || c == '\n') { // Skip white spaces
            if ((++inputIndex) >= N) break;
            c = input[inputIndex];
        }
        output[outputIndex++] = c;
        ++inputIndex;
    }
    output[outputIndex] = '\0';
}

int main()
{
    // Sample input: "1 0 * * 1 0 0 0 0 0 + + * * 1 0 + + + * * * 0 1 0"
    char sequenceRaw[60], sequenceTrimed[60];
    printf("Enter a sequence: ");
    scanf ("%[^\n]%*c", sequenceRaw);                  
    removeWhiteSpaces(sequenceTrimed, sequenceRaw);

    if (strlen(sequenceTrimed) != NUM_CHARS) {
        printf("Please provide 25 characters. You entered: %d.\n", (int)strlen(sequenceTrimed));
        exit(-1);
    }

    printGrid(sequenceTrimed);

    int colInput, rowInput;
    printf("Enter a coordinate to analyze: ");
    scanf("%d %d", &colInput, &rowInput);
    analyzeCoordinate(colInput, rowInput, sequenceTrimed);

    return 0;
}
