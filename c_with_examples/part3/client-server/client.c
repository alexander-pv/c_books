#include <stdio.h>
#include <netdb.h>
#include <memory.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>


#define SERVER_HOST "localhost"
#define SERVER_PORT 1234
#define CLIENT_PORT 1235
#define MSG "Client v0.1\n"
#define BUF_SIZE 64


int main() {
    int sock;
    int ans_len;
    char buffer[BUF_SIZE];
    struct hostent *h;
    struct sockaddr_in client, server;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    memset((char *) &client, '\0', sizeof(client));
    client.sin_family = AF_INET;
    client.sin_addr.s_addr = INADDR_ANY;
    client.sin_port = CLIENT_PORT;

    bind(sock, (struct sockaddr *) &client, sizeof(client));
    memset((char *) &client, '\0', sizeof(server));

    // Resolve server name and get IP address
    h = gethostbyname(SERVER_HOST);

    // Connect to server
    server.sin_family = AF_INET;
    memcpy((char *) &server.sin_addr, h->h_addr, h->h_length);
    server.sin_port = SERVER_PORT;
    connect(sock, &server, sizeof(server));

    // Receive server message
    ans_len = recv(sock, buffer, BUF_SIZE, 0);
    write(1, buffer, ans_len);
    send(sock, MSG, sizeof(MSG), 0);

    close(sock);

    return 0;
}