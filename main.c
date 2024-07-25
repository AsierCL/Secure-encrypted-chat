#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./include/crypto.h"



int main(int argc, char** argv){

    char message[256];
    char encrypted_message[256];
    char decrypted_message[256];
    
    
    printf("You: ");
    fgets(message, sizeof(message), stdin);

    EncryptMessage(message, encrypted_message);
    printf("%s\n",encrypted_message);
    fflush(stdout);
    DecryptMessage(encrypted_message, decrypted_message);
    printf("%s\n", decrypted_message);
    fflush(stdout);
    return 0;
}