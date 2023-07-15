#include <stdio.h>

#include<unistd.h>

int main(int argc, char* argv[])
{
    printf("Hello World! \n");
    for (int x = 0; x < argc ; ++x)
    {
        printf("argv[%d] = %s \n", x, argv[x]);
    }
    sleep(10);
    int myArr[] = {1 , 2, 3, 4, 5};
    printf("number of element of myArr (sizeof(array)/sizeof(int)) = %d\n", (int)(sizeof(myArr) / sizeof(int)) );

    sleep(5);
    return 0;
}
