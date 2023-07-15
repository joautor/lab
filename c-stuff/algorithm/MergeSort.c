#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>


#define EMPTY -1


void printItems(int* array, int size)
{
    for (int i = 0;i < size; ++i) {
        printf("%d ", *(array + i));
    }
    printf("\n");
}

void replace(int* dest, int index, int* source, int dataSize)
{
    for (int i = 0; i < dataSize; ++i) {
        *(dest + index + i) = source[i];
    }
}

void merge(int* array, int startA, int endA, int startB, int endB)
{
    int startOrg = startA;
    int N = endB - startA + 1 ;
    int tempArr[N];
    int index = 0;

    while (index < N) {
        int min = 0;
        if (array[startA] != EMPTY && array[startB] != EMPTY) {
            if (array[startA] < array[startB]) {
                min = array[startA];
                if (startA < endA) {
                    ++startA;
                } else {
                    array[startA] = EMPTY;
                }
            } else {
                min = array[startB];
                if (startB  < endB) {
                    ++startB;
                } else {
                    array[startB] = EMPTY;
                }
            }
        } else {
            if(array[startA] == EMPTY) {
                min = array[startB];
                ++startB;
            } else if (array[startB] == EMPTY) {
                min = array[startA];
                ++startA;
            }
        }
        tempArr[index] = min;
        ++index;
    } // end of while loop

    replace(array, startOrg, tempArr, N);
}

void mergeSort(int* array, int start, int end)
{
    if (start == end) {
        return;
    }

    int mid =  (end + start)  / 2;
    mergeSort(array, start, mid);
    mergeSort(array, mid + 1, end);

    merge(array, start, mid, mid + 1, end);
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int* array, int N)
{
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (array[i] > array[j]) {
                swap(&array[i], &array[j]);
                // or swap(array + i, array + j);
            }
        }
    }
}

void bubbleSort(int* array, int N)
{
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N - 1; ++ j) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void generateItems(int* outArray, int N)
{
    time_t t;
    srand((unsigned) time(&t)); // Initializes random number generator

    for (int i = 0; i < N; ++i) {
        outArray[i] = (rand() % N);
    }
}

void printContents(int* array, int N, int numRows = 0)
{
    if (numRows <= 0) numRows = N;
    printf("-------------------------------------------");
    for (int i = 0; i < N; ++i) {
        if ((i % numRows) == 0) {
            printf("\n");
        }
        printf("%3d ", array[i]);
    }
    printf("\n------------------------------------------\n");
}

bool TestSort(int* array, int N)
{
    for (int i = 0; i < (N - 1); ++i) {
        if (array[i] > array[i+1]) {
            printf("Test failed!\n");
            return false;
        }
    }
    printf("Test passed!\n");
    return true;
}

int main()
{
    clock_t time_start;
    clock_t time_end;
    clock_t t;
    // int N= 100000;
    int N;
    int algo;
    printf("\nEnter number of elements: ");
    scanf("%d", &N);
    printf("\t(1) MergeSort\n\t(2) BubbleSort\n\t(3) InsertionSort\n\t(4) All\n\nEnter Algorithm to used: ");
    scanf("%d", &algo);

    if ((algo == 1) || (algo == 4)) {
        int inputArr[N];
        generateItems(inputArr, N);
        // printContents(inputArr, N);
        time_start = clock();
        mergeSort(inputArr, 0, N-1);
        time_end = clock();
        //printContents(inputArr, N);
        double time_taken = ((double)(time_end - time_start)) / ((double)CLOCKS_PER_SEC); // in seconds
        printf("MergeSort: %lf seconds\n", time_taken);
        TestSort(inputArr, N);
    }

    if ((algo == 2) || (algo == 4)) {
        int inputArr2[N];
        generateItems(inputArr2, N);
        //printContents(inputArr2, N);
        t = clock();
        bubbleSort(inputArr2, N);
        t = clock() - t;
        //printContents(inputArr2, N);
        double time_taken2 = ((double)t) / CLOCKS_PER_SEC;
        printf("BubbleSort: %f seconds\n", time_taken2);
        TestSort(inputArr2, N);
    }

    if ((algo == 3) || (algo == 4)) {
        int inputArr3[N];
        generateItems(inputArr3, N);
        //printContents(inputArr3, N);
        t = clock();
        bubbleSort(inputArr3, N);
        t = clock() - t;
        //printContents(inputArr3, N);
        double time_taken3 = ((double)t) / CLOCKS_PER_SEC;
        printf("InsertionSort: %f seonds\n", time_taken3);
        TestSort(inputArr3, N);
    }

    printf("\nDummy test failed:\n");
    int temp[10] = {1, 2, 3, 5, 6, 7, 4, 8, 9, 0};
    TestSort(temp, 10);

    /*int test[10] = {3, 1, 5, 2, 4, 10, 7, 8, 6, 9};
    printf("RAW: ");
    printItems(test, 10);
    mergeSort(test, 0, 9);
    printf("SORTED: ");
    printItems(test, 10);

    printf("\n");

    int test2[5] = { 99, 97, 96, 95, 94 };
    printf("RAW: ");
    printItems(test2, 5);
    mergeSort(test2, 0, 4);
    printf("SORTED: ");
    printItems(test2, 5);
    //free(test);

    printf("\n");

    printf("Using insertion sort: \n");
    int test3[10] = {3, 1, 1, 2, 4, 10, 7, 8, 6, 1};
    printf("RAW: ");
    printItems(test3, 10);
    insertionSort(test3, 10);
    printf("SORTED: ");
    printItems(test3, 10);

    printf("\n");

    printf("Using bubble sort: \n");
    int test4[10] = {69, 1, 1, 2, 4, 10, 7, 8, 6, 1};
    printf("RAW: ");
    printItems(test4, 10);
    bubbleSort(test4, 10);
    printf("SORTED: ");
    printItems(test4, 10);
    */

    return 0;
}
