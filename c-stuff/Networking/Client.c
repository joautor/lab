#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080

int main(int argc, char const* argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char* message = "Hello from client";
    char buffer[1024] = {0};

    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        fprintf(stderr,"\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    //Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        fprintf(stderr, "\nInvalid address/ Address not supported\n");
        return -1;
    }
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    {
        fprintf(stderr, "\nConnection Failed\n");
        return -1;
    }

    send(sock, message, strlen(message), 0);
    printf("Hello message sent\n");
    valread = read(sock, buffer, 1024);
    printf("%s\n", buffer);

    return 0;
}



