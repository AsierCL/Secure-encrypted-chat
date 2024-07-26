#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include "./include/crypto.h"
#include "./include/network.h"



int main(int argc, char** argv) {
    initialize_network("192.168.0.251");

    pthread_t send_tid, receive_tid;

    // Create threads to send and receive messages simultaneously
    pthread_create(&send_tid, NULL, send_thread, NULL);
    pthread_create(&receive_tid, NULL, receive_thread, NULL);

    // Wait for them to finish. Is this necessary?
    // CHECK IT
    pthread_join(send_tid, NULL);
    pthread_join(receive_tid, NULL);

    cleanup_network();
    return 0;
}