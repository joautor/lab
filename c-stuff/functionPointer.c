#include<stdio.h>
#include<string.h>
/*
typedef struct Object
{
    char name[16]; //= "testing";
    void (*doubleIt) (int num) ;//= twiceNum;

} Object;

void twiceNum (int num)
{
    printf(" double value of %d is %d\n", num, (num * 2));
}
*/


void executeCallback(void (*callback)(int num), int (*cb2)(void))
{
    printf("executing the call back function..\n");
    callback(97);
    cb2();
}


void foo(int num)
{
    printf("from foo(): %d\n", num);
}

void test(int num)
{
    printf("from test() double of %d is %d\n", num, (num * 2));
}

int something()
{
    printf("from something(): What is the meaning of life?\n");
    return 0;
}

void foo1()
{
    printf("foo1\n");
}

void foo2()
{
    printf("foo2\n");
}

void foo3()
{
    printf("foo3\n");
}

int main()
{
    void (*fp)(int num);

    fp = foo;
    fp(69);

    executeCallback(foo, something);
    executeCallback(test, something);

    printf("size of foo() is %zu\n", sizeof(foo));
    printf("size of test() is %zu\n", sizeof(test));
    printf("size of fp is %zu\n", sizeof(fp));

    void (*funcPtr[])() = {foo1, foo2, foo3};

    for (int i = 0; i < 3; ++i)
    {
        funcPtr[i]();
        (*funcPtr[i])();
    }

    return 0;
}
