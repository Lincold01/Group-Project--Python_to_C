#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_address;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket.");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = inet_addr("192.168.56.103");

    if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_addr>
        perror("Error connecting to server.");
        exit(1);
    }

    printf("Enter message: ");
    scanf("%s", buffer);

    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("Response from server: %s\n", buffer);

    close(sockfd);
    return 0;
}
