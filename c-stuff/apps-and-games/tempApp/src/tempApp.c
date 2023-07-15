#include <stdio.h>

#include "../../../utility/sorter.h"
#include "../../../utility/logger.h"
#include "../../../utility/utstring.h" // Note: In order to compile correctly, make sure that include the .c file inside the makefile


// *************** Int *****************

int compareInt(void* item1, void* item2)
{
    if (item1 == NULL) {
        LOG_ERR("item1 is NULL pointer");
        return 0;
    }
    if (item2 == NULL) {
        LOG_ERR("item2 is NULL pointer");
        return 0;
    }

    int* pItem1 = (int*)(item1);
    int* pItem2 = (int*)(item2);
    LOG_DBG("comparing %d and %d", *pItem1, *pItem2);

    if ((*pItem1) > (*pItem2)) return 1;
    if ((*pItem1) < (*pItem2)) return -1;

    return 0;
}

void swapInt(void* item1, void* item2)
{
    if (item1 == NULL) {
        LOG_ERR("item1 is NULL pointer");
        return;
    }
    if (item2 == NULL) {
        LOG_ERR("item2 is NULL pointer");
        return;
    }
    int* pItem1 = (int*)(item1);
    int* pItem2 = (int*)(item2);
    LOG_DBG("swapping %d and %d", *pItem1, *pItem2);

    int temp = *pItem1;
    *pItem1 = *pItem2;
    *pItem2 = temp;
}

void dumpArrayInt(int array[], int N)
{
    printf("\n");
    for (int i = 0; i < N; ++i) {
        printf("%3d ", array[i]);
    }
    printf("\n");
}

// ************* Char ****************

int compareChar(void* item1, void* item2)
{
    if (item1 == NULL) {
        LOG_ERR("item1 is NULL pointer");
        return 0;
    }
    if (item2 == NULL) {
        LOG_ERR("item2 is NULL pointer");
        return 0;
    }

    char* pItem1 = (char*)(item1);
    char* pItem2 = (char*)(item2);

    if ((*pItem1) > (*pItem2)) return 1;
    if ((*pItem1) < (*pItem2)) return -1;

    return 0;
}

void swapChar(void* item1, void* item2)
{
    if (item1 == NULL) {
        LOG_ERR("item1 is NULL pointer");
        return;
    }
    if (item2 == NULL) {
        LOG_ERR("item2 is NULL pointer");
        return;
    }
    char* pItem1 = (char*)(item1);
    char* pItem2 = (char*)(item2);

    int temp = *pItem1;
    *pItem1 = *pItem2;
    *pItem2 = temp;
}


void dumpArrayChar(char array[], int N)
{
    printf("\n");
    for (int i = 0; i < N; ++i) {
        printf("%c ", array[i]);
    }
    printf("\n");
}


int main()
{
    printf("Hello World!\n");
    /*int a = 9;
    int b = 7;
    int c = 5;
    int d = 3;
    int e = 1;
    int f = 0;
    int g = 2;
    int h = 4;
    int i = 6;
    int j = 8;
    */
    int testArr[10] = {9, 7, 5, 3, 1, 0, 2, 4, 6, 8};
    //int* testArr[10] = {&a, &b, &c, &d, &e, &f, &g, &h, &i, &j};
    //int testArr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("Unsorted array: ");
    dumpArrayInt(testArr, 10);

    bubbleSort(testArr, 10, compareInt, swapInt, sizeof(testArr[0]));

    printf("Sorted using bubble sort:");
    dumpArrayInt(testArr, 10);

    char letters[10] = {'a', 'l', 'l', 'y','n', 'm','i','n','e','!'};
    printf("unsorter letters:  ");
    dumpArrayChar(letters, 10);
    bubbleSort(letters, 10, compareChar, swapChar, sizeof(letters[0]));
    printf("sorter using bubble sort:");
    dumpArrayChar(letters, 10);

    LOG_ERR("This is sample error!");
    LOG_WRN("This is sample warning!");
    LOG_INFO();

    // ******* using string functions from utility **********
    char message1[15] = "HelloWorld";
    char message2[15];
    message2[0] = 0;

    LOG_INFO("before copying: \n\t message1: %s\n\t message2: %s\n", message1, message2);
    //ut_strcpy(message1, message2);
    ut_strncpy(message1, message2, 15);
    LOG_INFO("after copying: \n\t message1: %s\n\t message2: %s\n", message1, message2);
    return 0;
}
