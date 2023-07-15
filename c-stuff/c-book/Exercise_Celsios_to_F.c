#include <stdio.h>

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    printf("Enter lowerbound: ");
    scanf("%d", &lower);
    printf("Enter upperbound: ");
    scanf("%d", &upper);
    printf("Enter stepsize: ");
    scanf("%d", &step);

    celsius = lower;
    printf("\n\ncelsius\tfahrenheit\n");

    while (celsius <= upper) {
        //fahr = ((9.0 / 0.5) *  celsius) + 32.0; //it outputs unexpected results. because of (0.9/0.5).. precision issue and size? i guess
        fahr = (celsius * (0.9 /  0.5)) + 32.0;
        printf("%7.2f\t%7.2f\n", celsius, fahr);
        celsius += step;
    }

    return 0;
}

