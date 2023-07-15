#include <iostream>

int main()
{
    volatile int y = 0;
    int N = 1000000;
    for (int x = 0; x < N; ++x)
    {
        y+=x;
    }
    return 0;
}
