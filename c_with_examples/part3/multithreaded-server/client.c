#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <memory.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>


int main() {

    int socket_desc, val;
    struct sockaddr_in client_addr;
    char buffer[256];
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    printf("Insert port number: ");
    int port;
    scanf("%d", &port);
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = INADDR_ANY;
    client_addr.sin_port = htons(port);

    if (connect(socket_desc, (struct sockaddr *)&client_addr, sizeof(client_addr) ) == 0) {
        printf("\nConnected to server! Port: %d\n", port);
    }
    else {
        printf("\nError while connecting to server using port: %d\n", port);
        exit(1);
    }

    while(1) {
        printf("Message to send: ");
        bzero(buffer, 256);
        scanf("%s", buffer);
        write(socket_desc, buffer, strlen(buffer));
        bzero(buffer, 256);

        read(socket_desc, buffer, 255);
        printf("Message from server: %s\n", buffer);
    }

    close(socket_desc);
    return 0;
}