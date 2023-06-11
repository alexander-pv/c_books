#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h> // See: https://en.wikipedia.org/wiki/C_signal_handling

#define SERVER_PORT 1234
#define BUF_SIZE 64
#define MESSAGE_TO_SEND "Server. Version 0.1\n"

void sigpipe_handler() {
    printf("Got SIGPIPE \n");
    exit(1);
}

int main(void) {
    // sock1 - server socket
    // sock2 - socket for data exchange with a client
    int sock1, sock2;
    // ans_len - client exchange data size
    // total - clients counters
    int ans_len, total = 0;
    // buffer for data exchange
    char buffer[BUF_SIZE];
    struct sockaddr_in sin, client;

    // create server socket
    sock1 = socket(AF_INET, SOCK_STREAM, 0);
    memset((char *)&sin, '\0', sizeof(sin));

    sin.sin_family = AF_INET;           // TCP/IP
    sin.sin_addr.s_addr = INADDR_ANY;   // Can work with any address
    sin.sin_port = SERVER_PORT;

    // Bind created socket with address and server port
    bind(sock1, (struct sockaddr *)&sin, sizeof(sin));
    printf("Server running...\n");
    // We listen  sock1 with maximum number of clients: 3
    listen(sock1, 3);

    // Place here any signal handlers
    signal(SIGPIPE, sigpipe_handler);

    while (1) {

        ans_len = sizeof(client);
        sock2 = accept(sock1, &client, &ans_len);
        write(sock2, MESSAGE_TO_SEND, sizeof(MESSAGE_TO_SEND));

        total += 1;
        ans_len = read(sock2, buffer, BUF_SIZE);
        write(1, buffer, ans_len);
        printf("Client no %d\n", total);

        // End session
        shutdown(sock2, 0);
        close(sock2);

    }

    return 0;
}