#include <stdio.h>
#include <stdlib.h>

//command to use:
// valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./program

int main()
{
    int* ptr = (int*)malloc(sizeof(int));
    //free(ptr);
    return 0;
}



