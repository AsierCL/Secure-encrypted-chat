#ifndef CRYPTO_H
#define CRYPTO_H


/**
 * Encrypts a given message.
 *
 * @param message The message to be encrypted.
 * @param encrypted_message Pointer to the buffer where the encrypted message will be stored.
 */
void EncryptMessage(char *message, char *encrypted_message);

/**
 * Decrypts a given encrypted message.
 *
 * @param encrypted_message The encrypted message to be decrypted.
 * @param decrypted_message Pointer to the buffer where the decrypted message will be stored.
 */
void DecryptMessage(char *encrypted_message, char *decrypted_message);

#endif // CRYPTO_H