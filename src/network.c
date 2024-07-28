#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <termios.h>

#include "../include/crypto.h"



int sock;
struct sockaddr_in server_addr, client_addr;

void initialize_network(const char *client_ip, int port) {
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("\x1b[31m\nSocket creation failed\x1b[0m\n");
        exit(EXIT_FAILURE);
    }


    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port); 
    server_addr.sin_addr.s_addr = INADDR_ANY;

    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, client_ip, &client_addr.sin_addr) <= 0) {
        printf("\x1b[31m\nInvalid client IP address\x1b[0m\n");
        exit(EXIT_FAILURE);
    }

    if (bind(sock, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("\x1b[31m\nBind failed\x1b[0m\n");
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
    char encrypted_message[256];
    while (1) {
        printf("\x1b[32mYou: ");
        fgets(message, sizeof(message), stdin);
        
        EncryptMessage(message, encrypted_message);
        send_message(encrypted_message);
    }
    return NULL;
}



void* receive_thread(void* arg) {
    char message[256];
    char encrypted_message[256];
    while (1) {
        receive_message(encrypted_message);
        DecryptMessage(encrypted_message, message);
        if (strlen(message) > 0) {
            printf("\33[2K");
            printf("\033[A");
            printf("\n\x1b[34mReceived: %s", message);
            printf("\x1b[32mYou: ");
            fflush(stdout);
        }
    }
    return NULL;
}