#include <stdio.h>
#include <stdlib.h>


int main()
{
    int N, lowestNum, toPrint;

    printf("Enter a number: ");
    scanf("%d", &N);

    for (int i = 0; i <= (N * 2); ++i)
    {
        if (N == i || (N + 1) == i)
            continue;

        lowestNum = abs(N - i);
        for (int j = 0; j <= (N * 2); ++j)
        {
            if (N == j || (N + 1) == j)
                continue;

            toPrint = abs(N - j);
            printf("%d ", (toPrint >= lowestNum) ? toPrint : lowestNum);
        }
        printf("\n");
    }
}
