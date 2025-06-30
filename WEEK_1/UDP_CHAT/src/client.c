#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "client.h"

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(1);
    }

    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[BUF_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
        error("Socket creation failed");

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);

    socklen_t len = sizeof(servaddr);

    while (1) {
        printf("Client: ");
        fgets(buffer, BUF_SIZE, stdin);

        // Send message to server
        sendto(sockfd, buffer, strlen(buffer), 0,
               (struct sockaddr *)&servaddr, len);

        // Receive response from server
        int n = recvfrom(sockfd, buffer, BUF_SIZE, 0,
                         (struct sockaddr *)&servaddr, &len);
        buffer[n] = '\0';
        printf("Server: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}
