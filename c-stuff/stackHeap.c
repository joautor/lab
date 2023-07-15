#include <stdlib.h>
#include <stdio.h>

void check(int depth)
{
    char c;
    char *ptr = malloc(1);
    printf("stack at %p, heap at %p\n", &c, ptr);
    if (depth <= 0) return;
    check(depth -1);
}

int main(int argc, char** argv)
{
    int depth = 0;
    if (argc > 1)
    {
        depth = atoi(argv[1]);
    }
    check(depth);
    return 0;
}

