#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 12345

int sock;
struct sockaddr_in server_addr, client_addr;

void initialize_network(const char *client_ip) {
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }


    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT); 
    server_addr.sin_addr.s_addr = INADDR_ANY;

    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, client_ip, &client_addr.sin_addr) <= 0) {
        perror("Invalid client IP address");
        exit(EXIT_FAILURE);
    }

    // Enlazar el socket al servidor
    if (bind(sock, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
}


void send_message(const char *message) {
    sendto(sock, message, strlen(message), MSG_CONFIRM,
           (const struct sockaddr *)&client_addr, sizeof(client_addr));
}

void receive_message(char *buffer) {
    socklen_t len = sizeof(client_addr);
    int n = recvfrom(sock, buffer, 256, 0, (struct sockaddr *)&client_addr, &len);
    if (n < 0) {
        buffer[0] = '\0'; // No message received
    } else {
        buffer[n] = '\0';
    }
}

void cleanup_network() {
    close(sock);
}

void* send_thread(void* arg) {
    char message[256];
    while (1) {
        printf("You: ");
        fgets(message, sizeof(message), stdin);
        send_message(message);
    }
    return NULL;
}

void* receive_thread(void* arg) {
    char message[256];
    while (1) {
        receive_message(message);
        if (strlen(message) > 0) {
            printf("\nReceived: %s", message);
            printf("You: ");
            fflush(stdout);
        }
    }
    return NULL;
}