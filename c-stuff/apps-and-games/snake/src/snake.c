#include <stdio.h>
#include <stdlib.h>                 // malloc(), srand(), rand()
#include <unistd.h>                 // sleep()
#include <stdbool.h>
#include <pthread.h>
#include <time.h>
// #include <conio.h>                  // getch()   for windows
//#include "curses.h"

// #include "../utility/logger.h"

#define GRID_SIZE           10

// Used for coloring the grid and snake
#define KNRM    "\x1B[0m"
#define KRED    "\x1B[31m"
#define KBLU    "\x1B[34m"


typedef enum {up, right, down, left} Direction;

typedef struct Food {
    int x;
    int y;
    int scoreValue;
} Food;

typedef struct Node{
    int x;
    int y;
    bool isHead;
    bool isTail;
    struct Node* prev;
    struct Node* next;
} Node;


//=================== ** Global Data ** =====================

Direction currentDir = down;
Food food = { 0, 0, 1 };
bool isGameOver = false;
int score = 0;
// pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;


//==========================================================

bool isOppositeDir(Direction d1, Direction d2)
{
    if ((d1 == up) && (d2 == down)) return true;
    if ((d1 == down) && (d2 == up)) return true;
    if ((d1 == left) && (d2 == right)) return true;
    if ((d1 == right) && (d2 == left)) return true;

    return false;
}

void setDirection(Direction dir)
{
    if ((currentDir == dir) || isOppositeDir(currentDir, dir)) return;
    currentDir = dir;
}

bool isPartOfSnake(Node* node, int x, int y)
{
    if (node == NULL) return false;
    while(node != NULL) {
        if ((node->x == x) && (node->y == y)) return true;
        node = node->next;
    }
    return false;
}

void generateNewFood(Node* node)
{
    if (node == NULL) return;
    time_t t;
    srand((unsigned) time(&t)); // Initializes random number generator
    int x = -1;
    int y = -1;
    do {
        x = (rand() % GRID_SIZE);
        y = (rand() % GRID_SIZE);
    } while (isPartOfSnake(node, x, y));

    food.x = x;
    food.y = y;
    food.scoreValue = 1; // Deault is 1 but later on we can increase it we add new stages etc.
}

void printControls()
{
    printf("\n\tMovements: \t\t(a) left\t(w) up\t(d) right\t(s) down\n");
}

void printSnakeWelcome()
{
    printf("\n");
    printf("%s\t\t                           ____\n", KBLU);
    printf("\t\t  ________________________/ O  \\___/\n");
    printf("\t\t<_O_O_O_O_O_O_O_O_O_O_O_O_____/   \\\n");
    printf("\n\n");
    printf("%s\t\t\tWelcome to Snake Game Crazy\n\n", KNRM);
    printf("\t\t\tPress <enter> key to start: \n\t\t\t\t    ");
    char dummy;
    scanf("%c", &dummy);
}

// A thread function used to get user input in a separated thread
void* handleUserInput(void* argv)
{
    while(!isGameOver) {
        char chPress;
        scanf("%c", &chPress);
        switch(chPress) {
            case 'w': setDirection(up); break;
            case 's': setDirection(down); break;
            case 'd': setDirection(right); break;
            case 'a': setDirection(left); break;
        }
    }
    return NULL;
}

Node* generateNode(int x, int y)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->x = x;
        newNode->y = y;
        newNode->isHead = false;
        newNode->isTail = false;
        newNode->prev = NULL;
        newNode->next = NULL;
    }
    return newNode;
}

// For debugging
void dumpNode(Node* node)
{
    if (node != NULL) {
        printf("Node->x:%d, y:%d, h:%d, t:%d, p:%p, n:%p\n", node->x, node->y, node->isHead, node->isTail, node->prev, node->next);
    } else {
        printf("Node-> **** NULL ****\n");
    }
}

// For debugging
void dumpSnake(Node* node)
{
    if (node == NULL) return;
    if (!node->isHead) return;
    while (node != NULL) {
        dumpNode(node);
        node = node->next;
    }
}

void deleteAllNodes(Node* node)
{
    while(node != NULL) {
        Node* temp = node->next;
      //  dumpNode(node);
        free(node);
        node = temp;
    }
}

Node* getTail(Node* node)
{
    if (node == NULL) return NULL;
    if (!node->isHead) return NULL;

    Node* tailTemp = node;
    while ((tailTemp != NULL) && (!tailTemp->isTail)) {
         tailTemp = node->next;
         node = tailTemp;
    }
    return tailTemp;
}

bool isAFood(int x, int y)
{
    return ((food.x == x) && (food.y == y));
}

Node* moveSnake(Node* headNode, int x, int y)
{
    if (headNode == NULL) return NULL;
    if (!(headNode->isHead)) return NULL;

    if (isPartOfSnake(headNode, x, y)) {
        isGameOver = true;
    }

    //If next location is a food, then eat it 
    if (isAFood(x, y)) {
        Node* newNode = generateNode(x,y); // The food becomes a part of the body, generated node is the new head
        if (newNode != NULL) {
            newNode->isHead = true;
            newNode->next = headNode;
            headNode->prev = newNode;
            headNode->isHead = false;

            // Update score and generate new food
            score += food.scoreValue;
            generateNewFood(newNode);

            return newNode;;
        }
    }

    // Normal movement, not eating

    // In the case when snake has only one node, just update node's coordinate
    if (headNode->isHead && headNode->isTail) {
        headNode->x = x;
        headNode->y = y;
        return headNode;
    }
    // Tail node becomes the head node so that we don't need to change the coordinates of all the nodes
    Node* tailNode = getTail(headNode);
    if (tailNode != NULL) {
        tailNode->x = x;
        tailNode->y = y;
        tailNode->prev->isTail = true;
        tailNode->prev->next = NULL;
        tailNode->isTail = false;
        tailNode->isHead = true;
        tailNode->prev = NULL;
        tailNode->next = headNode;
        headNode->isHead = false;
        headNode->prev = tailNode;
        return tailNode;
    }
    // If something went wrong, return the original head node
    return headNode;
}

// Horizontal line
Node* generateDefaultSnake(int numNodes, int startX, int startY)
{
    if (numNodes <= 0) return NULL;
    int x = startX;
    int y = startY;
    Node* headNode = generateNode(x, y);
    if (headNode == NULL) return NULL;

    // First node is both the head and the tail;
    headNode->isHead = true;
    headNode->isTail = true;

    Node* prev = headNode;
    for (x  = 1; x < numNodes; ++x) {
        Node* node = generateNode(x, y); // Put new node as the snake's tail 
        if ((node == NULL) || (prev == NULL)) break;
        prev->isTail = false;
        prev->next = node;
        node->prev = prev;
        node->isTail = true;
        prev = node;
    }
    return headNode;
}

void separatorLine()
{
    printf("\n================================================\n");
}

void borderLine()
{
    printf("\t+------------------------------+\n");
}

void clearScreen()
{
    for (int i = 0; i < 30; ++i) printf("\n");
    //system("clear");
}

bool isCoordANode(Node* head, int x, int y, Node** out)
{
    Node* node = head;
    while(node != NULL) {
        if ((node->x == x) && (node->y == y)) {
            *out = node;
            return true;
        }
        node = node->next;
    }
    *out = NULL;
    return false;
}

void printGrid(Node* head, int size)
{
    if (size < 2) return;
    if (head == NULL) return;

    separatorLine();
    printf("Score: %d\n\n", score);

    borderLine();   // Upper border
    for (int y = 0; y < size; ++y) {
        printf("%s\t|", KNRM);   // Left border
        for (int x = 0; x < size; ++x) {
            Node* out = NULL;
            if (isCoordANode(head, x, y, &out)) {
                if (out != NULL) {
                    if (out->isHead) printf("%s @ ", KBLU);
                    else if (out->isTail) printf("%s + ", KBLU);
                    else printf("%s # ",KBLU);
                } else printf("%s - ", KNRM);

            }
            else if (isAFood(x, y)) printf("%s & ", KRED);
            else printf("%s - ", KNRM);
        }
        printf("%s|\n", KNRM); // Right border
    }
    borderLine(); // Lower border
    separatorLine();
}

void getNextMoveCoord(Node* head, int* outX, int* outY)
{
    if (head == NULL) {
        printf("getNextMoveCoord: head is null\n");
        *outX = 0;
        *outY = 0;
        return;
    }

    switch(currentDir) {
        case up:
            *outX = head->x;
            *outY = (head->y - 1) % GRID_SIZE;
            break;

        case right:
            *outX = (head->x + 1) % GRID_SIZE;
            *outY = head->y;
            break;

        case down:
            *outX = head->x;
            *outY = (head->y + 1) % GRID_SIZE;
            break;

        case left:
            *outX = (head->x - 1) % GRID_SIZE;
            *outY = head->y;
            break;

        default:
            printf("getNextMoveCorrd: snake direction is invalid.\n");
            *outX = 0;
            *outY = 0;
            break;
    }

    if (*outX < 0) *outX += GRID_SIZE;
    if (*outY < 0) *outY += GRID_SIZE;
}

int main()
{
    printSnakeWelcome();

    int numNodes = 3;
    Node* headNode = generateDefaultSnake(numNodes, 0, 0);
    if (headNode == NULL) {
        printf("Unable to generate snake\n");
    }

    pthread_t thread_0;
    pthread_create(&thread_0, NULL, handleUserInput, NULL);

    generateNewFood(headNode);   // Initial food location and score value

    do {
        clearScreen();
        int x;
        int y;
        getNextMoveCoord(headNode, &x, &y);
        headNode = moveSnake(headNode, x, y);
        printGrid(headNode, GRID_SIZE);
        sleep(1);
    } while (!isGameOver);

    pthread_cancel(thread_0); // Kill thread directly because it is already game over
    pthread_join(thread_0, NULL);

    printf("Game Over!\nFinal score: %d\n", score);

    // Free heap allocated nodes
    if (headNode != NULL) {
        deleteAllNodes(headNode);
    }
    return 0;
}
