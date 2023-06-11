#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>    // multithreading
#include <unistd.h>     // write

#define SERVER_PORT 1234

// Compile: gcc mt_server.c -o mt_server -lpthread

void *connection_handler(void *socket_desc) {

    // Getting socket descriptor
    int sock = *(int *)socket_desc;
    int read_size;
    char *message, client_message[2000];

    //Greeting client
    message = "\nHi! I am your connection handler\n";
    write(sock, message, strlen(message));

    message = "\nPlease, send me a text: \n";
    write(sock, message, strlen(message));

    // Read client message
    while ( (read_size = recv(sock, client_message, 2000,0)) > 0) {
        client_message[read_size] = '\0';
        printf("\nGot from client: %s", client_message);
        write(sock, client_message, strlen(client_message));
        memset(client_message, 0, 2000); //Clear buffer
        }

    if (read_size == 0) {
        printf("\nClient is disconnected\n");
        fflush(stdout);
    }
    else if (read_size == -1) {
        perror("\nError while doing recv\n");
    }

    return 0;
}


int main() {

    int socket_desc, client_sock, c;
    struct sockaddr_in server, client;

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("\nError creating socket");
    }
    printf("\nCreated socket");

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(SERVER_PORT);

    // Bind
    if ( bind(socket_desc, (struct sockaddr *)&server, sizeof(server) )  < 0) {
        printf("\nSocket bind failed. Error.");
        return 1;
    }
    printf("\nCompleted bind");

    listen(socket_desc, 3);

    printf("\nWaiting for new connections...");
    c = sizeof(struct sockaddr_in);
    pthread_t thread_id;

    while ( (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c ) )) {

        printf("\nEstablished connection");

        if  (pthread_create(&thread_id,
                            NULL,
                            connection_handler,
                            (void *)&client_sock ) < 0) {
            printf("\nError while creating a thread.");
            exit(1);
        }
        printf("\nConnection handler is set in a separate thread");
    }

    if (client_sock < 0) {
        perror("\nAccept failed\n");
        return 1;
    }

    return 0;
}


