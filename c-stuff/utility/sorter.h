#ifndef utility_sorter_h
#define utility_sorter_h

#include <stdlib.h>

void bubbleSort(void* array, int arrSize, int (*compareFunc)(void* item1, void* item2), void (*swapFunc)(void* item1, void* item2), size_t itemSize);

void MergeSort(void* array, int arrSize, int (*compareFunc)(void* item1, void* item2), void (*swapFunc)(void* item1, void* item2), size_t itemSize);


#endif // utility_sorter_h
