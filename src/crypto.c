#include <string.h>

// Funciones de encriptación y desencriptación simples (puede ser sustituido por algo más seguro)

void EncryptMessage(const char *message, char *encrypted_message) {
    // Ejemplo de encriptación simple (XOR)
    size_t len = strlen(message);
    for (size_t i = 0; i < len; i++) {
        encrypted_message[i] = message[i] ^ 0xAA; // Usar una clave más segura en producción
    }
    encrypted_message[len] = '\0';
}

void DecryptMessage(const char *encrypted_message, char *decrypted_message) {
    // Ejemplo de desencriptación simple (XOR)
    size_t len = strlen(encrypted_message);
    for (size_t i = 0; i < len; i++) {
        decrypted_message[i] = encrypted_message[i] ^ 0xAA;
    }
    decrypted_message[len] = '\0';
}
