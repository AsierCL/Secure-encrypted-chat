#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include "./include/crypto.h"
#include "./include/network.h"



int main(int argc, char** argv) {
    char ip_addr[32];
    int port = -1;
    printf("Enter the IP you want to chat with: ");
    scanf(" %31s",ip_addr);
    printf("\n");

    printf("Enter the network port: ");
    scanf("%d", &port);
    if(port>65535 || port<1){
        perror("\x1b[31m\nInvalid port\x1b[0m\n");
        return 1;
    }

    initialize_network(ip_addr, port);
    sleep(0.5);

    pthread_t send_tid, receive_tid;

    // Create threads to send and receive messages simultaneously
    pthread_create(&send_tid, NULL, send_thread, NULL);
    pthread_create(&receive_tid, NULL, receive_thread, NULL);
    system("clear");
    printf("\x1b[33mConnection established with address: %s:%d\n\n",ip_addr,port);
    printf("\x1b[32mYou: ");
    fflush(stdout);

    // Wait for them to finish. Is this necessary?
    // CHECK IT
    pthread_join(send_tid, NULL);
    pthread_join(receive_tid, NULL);

    cleanup_network();
    return 0;
}