#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[BUF_SIZE];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) error("Socket creation failed");

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;  // Listen on all interfaces
    servaddr.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
        error("Bind failed");

    printf("Server listening on port %s...\n", argv[1]);

    socklen_t len = sizeof(cliaddr);

    while (1) {
        int n = recvfrom(sockfd, buffer, BUF_SIZE, 0, (struct sockaddr *)&cliaddr, &len);
        buffer[n] = '\0';
        printf("Client: %s\n", buffer);

        printf("Server: ");
        fgets(buffer, BUF_SIZE, stdin);

        sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&cliaddr, len);
    }

    close(sockfd);
    return 0;
}

