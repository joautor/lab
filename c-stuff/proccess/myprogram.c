#include <stdio.h>


int main(int argc, char** argv) {
    if (argc != 2) {
        printf("usage: myprogram <name>\n");
    } else {
        printf("Your name is %s\n", argv[1]);
    }
    return 0;
}
