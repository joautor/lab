#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

#define BOARD_SIZE      3

#define PLAYER_X        1
#define PLAYER_O       -1
#define EMPTY           0

#define DEPTH           9 //3

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)

typedef enum {
    player_O = -1,
    tie,
    player_X
} Winner;

int board[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};

void displayBoard()
{
    printf("-------------\n");
    for (int i = 0; i < BOARD_SIZE; ++i) {
        printf("|");
        for(int j = 0; j < BOARD_SIZE; ++j) {
            switch(board[i][j]) {
                case PLAYER_X: printf(" X "); break;
                case PLAYER_O: printf(" O "); break;
                default: printf("   ");
            }
            printf("|");
        }
        printf("\n-------------\n");
    }
}

// For debugging
void dumpBoardData()
{
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for(int j = 0; j < BOARD_SIZE; ++j) {
            printf("%3d", board[i][j]);
        }
        printf("\n");
    }
}

bool markBoard(int row, int col, int player)
{
    if ((row < 0) || (row >= BOARD_SIZE)) return false;
    if ((col < 0) || (col >= BOARD_SIZE)) return false;
    if (board[row][col] != EMPTY) return false;

    board[row][col] = (player == PLAYER_X ? 1 : -1);
    return true;
}

bool isBoardFull()
{
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for(int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == EMPTY) return false;
        }
    }
    return true;
}

int countMark(int markTest, int markA, int markB, int markC)
{
    int counter = 0;
    if (markTest == markA) ++counter;
    if (markTest == markB) ++counter;
    if (markTest == markC) ++counter;
    return counter;
}

bool isWinner(int player)
{
    /*// Horizontal
    if ((board[0][0] == player) && (board[0][1] == player) && (board[0][2] == player)) return true;
    if ((board[1][0] == player) && (board[1][1] == player) && (board[1][2] == player)) return true;
    if ((board[2][0] == player) && (board[2][1] == player) && (board[2][2] == player)) return true;

    // Vertical
    if ((board[0][0] == player) && (board[1][0] == player) && (board[2][0] == player)) return true;
    if ((board[0][1] == player) && (board[1][1] == player) && (board[2][1] == player)) return true;
    if ((board[0][2] == player) && (board[1][2] == player) && (board[2][2] == player)) return true;

    // Diagonal
    if ((board[0][0] == player) && (board[1][1] == player) && (board[2][2] == player)) return true;
    if ((board[0][2] == player) && (board[1][1] == player) && (board[2][0] == player)) return true;

    return false;
	*/
	// Check each row
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (countMark(player, board[i][0], board[i][1], board[i][2]) == 3) return true;
    }
    // Check each column
    for(int j = 0; j < BOARD_SIZE; ++j) {
        if (countMark(player, board[0][j], board[1][j], board[2][j]) == 3) return true;
    }
	// Check each diagonals
    if (countMark(player, board[0][0], board[1][1], board[2][2]) == 3) return true;
    if (countMark(player, board[2][0], board[1][1], board[0][2]) == 3) return true;
	
	return false;
}


bool isCloseToWinning(int player, int markA, int markB, int markC)
{
    // Winning if player has 2 marks and a single empty
	return ((countMark(EMPTY, markA, markB, markC) == 1) && (countMark(player, markA, markB, markC) == 2));
}

int countWinnableNextMoves(int player)
{
	int count = 0;

	// Check each row
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (isCloseToWinning(player, board[i][0], board[i][1], board[i][2])) count++;
    }
    // Check each column
    for(int j = 0; j < BOARD_SIZE; ++j) {
        if (isCloseToWinning(player, board[0][j], board[1][j], board[2][j])) count++;
    }
    // Check each diagonals
    if (isCloseToWinning(player, board[0][0], board[1][1], board[2][2])) count++;
    if (isCloseToWinning(player, board[2][0], board[1][1], board[0][2])) count++;

    return count;
}

int evaluateBoard(bool isMaximizingPlayer)
{
	int player = isMaximizingPlayer ? PLAYER_X : PLAYER_O;
	int multiplier = isMaximizingPlayer ? 10 : -10;
	return (countWinnableNextMoves(player) * multiplier);
	
}

int minimax(/*board, */ bool isMaximizingPlayer, int depth)
{
    if (isWinner(PLAYER_X)) return 50;  // maximizing player
    if (isWinner(PLAYER_O)) return -50; // minimizing player
    if (depth == 0) return evaluateBoard(isMaximizingPlayer);
    if (isBoardFull()) return 0;

    if (isMaximizingPlayer) {
       int maxEval = (int)(-INFINITY);
       //printf("-infinity is %d\n", maxEval);
       for (int i = 0; i < BOARD_SIZE; ++i) {
            for(int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_X; // maximizing player is player x
                    int eval = minimax(false, --depth);
                    maxEval = MAX(maxEval, eval);
                    board[i][j] = EMPTY; // make it empty again
                }
            }
        }
        return maxEval;

    } else { // Minimizing player
        int minEval = (int)(INFINITY);
        //printf("+infinity is %d\n", minEval);
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for(int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_O; // minimizing player is player o
                    int eval = minimax(true, --depth);
                    minEval = MIN(minEval, eval);
                    board[i][j] = EMPTY; // make it empty again
                }
            }
        }
        return minEval;
    }
}

void getBestMove(int* row, int* col)
{
    int bestScore = (int)(INFINITY);
    int tempRow = 0;
    int tempCol = 0;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for(int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == EMPTY) {
                board[i][j] = PLAYER_O;
                int tempScore = minimax(true, DEPTH);
                if (tempScore < bestScore) {
                    tempRow  = i;
                    tempCol = j;
                    bestScore = tempScore;
                }
                board[i][j] = EMPTY;
            }
        }
    }
    *row = tempRow;
    *col = tempCol;
}

int main(int argc, char** argv)
{
    printf("Tic Tac Toe\n\n");
    displayBoard();

    int curPlayer = PLAYER_X; // Default player to start

    if (argc == 2) {
        printf("argc is 2\n");
        if (strcmp(argv[1], "1") == 0) curPlayer = PLAYER_X;
        else if (strcmp(argv[1], "2") == 0) curPlayer = PLAYER_O;
    }

    do {
        int row;
        int col;
        if (curPlayer == PLAYER_O) { // AI
            printf("Computer's turn.\n");
            //sleep(1);
            getBestMove(&row, &col);
        } else { // Human
            // printf("Enter coordinates for player %s:\n", curPlayer == PLAYER_X ? "X" : "O");
            printf("Your turn. Enter coordinates:\n");
            printf("\trow: ");
            scanf("%d", &row);
            printf("\tcol: ");
            scanf("%d", &col);
        }

        if (!markBoard(row, col, curPlayer)) {
            printf("\tInvalid move! Place enter again.\n");
            continue;
        }

        displayBoard();

        if (isWinner(curPlayer)) {
            printf("Player %s wins!!!\n", curPlayer == PLAYER_X ? "X" : "O");
            break;
        }
        if (isBoardFull()) {
            printf("It's a tie!!!\n");
            break;
        }
        curPlayer = (curPlayer == PLAYER_X ? PLAYER_O : PLAYER_X); // Switch to the opposite player

    } while (true);

    return 0;
}
