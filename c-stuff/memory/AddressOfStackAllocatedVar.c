#include <stdio.h>

int main()
{
    int N = 10;
    printf("N=%d : %p\n", N, &N);

    for (int i = 0; i < 10; ++i) {
        int x = i;
        printf("x=%d : %p\n", x, &x);
    }
    int magic = 69;
    printf("magic=%d : %p\n", magic, &magic);
}
