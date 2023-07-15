#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char buffer[100] = "hello from the other side";
    char filename[10];
    FILE* fp;
    FILE* log = fopen("mylogs.log", "w");
    if (log == NULL)
    {
        fprintf(stderr, "Cannot open mylogs.log");
        exit(1);
    }
    fprintf(log, "Intialization successful\n");
    fprintf(log, "Getting user input\n");

    printf("Enter the filename: \n");
    scanf("%s", filename);

    //printf("Enter the data: \n");
    //scanf("%s", buffer);

    fprintf(log, "size of buffer is : %zu \n", strlen(buffer));
    fprintf(log, "Opening user defined filename\n");

    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Cannot read file");
        exit(1);
    }
    fwrite(buffer, strlen(buffer) + 1, 1, fp);

    fprintf(log, "writing buffer to file is successful\n");

    fclose(fp);
    fclose(log);

    return 0;
}


