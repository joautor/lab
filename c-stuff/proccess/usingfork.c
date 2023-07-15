/*
fork()
-creates a child process. Like a clone of itself
-the return value determines if it is a child or parent. Zero for child and non-zero for parent

exec*
- try checking "man execlp"
- exec[l|v]?p
- l -> list
    execl("/path/to/program", "program", "arg2", "arg3", NULL");
- v -> vector
    execv("/path/to/program", array); //not sure haha
- p -> means it will search the program in program enviroment
    execlp("ls", "ls", "-a", NULL);

- exec* replaces the program of the current process, so it is usually called inside a child process (using fork)


*/
#include <stdio.h>
#include <unistd.h>


int main()
{
    if (fork() == 0) {
        printf("I'm the child ..");
        //execlp("ls", "ls", "-al", NULL);
        //printf("after execlp");
        execl("./myprogram", "myprogram", "jemwel", NULL);
        printf("after myprogram\n");   // Not executed if the execlp is successful
    } else {
        printf("I'm the parent ..");
    }

    printf("Hello World! process id: %i\n", getpid());
    return 0;
}
