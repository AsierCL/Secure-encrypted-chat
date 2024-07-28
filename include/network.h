#ifndef NETWORK_H
#define NETWORK_H


/**
 * Initializes the network with the given client IP address and port.
 *
 * @param client_ip The IP address of the client.
 * @param port The port number to use for the connection.
 */
void initialize_network(const char *client_ip, int port);

/**
 * Sends a message to the client.
 *
 * @param message The message to be sent.
 */
void send_message(const char *message);

/**
 * Receives a message from the client.
 *
 * @param buffer Pointer to the buffer where the received message will be stored.
 */
void receive_message(char *buffer);

/**
 * Cleans up the network resources.
 */
void cleanup_network();

/**
 * Thread function for sending messages.
 *
 * @param arg Pointer to arguments for the send thread (if any).
 * @return Pointer to the result of the thread execution (if any).
 */
void* send_thread(void* arg);

/**
 * Thread function for receiving messages.
 *
 * @param arg Pointer to arguments for the receive thread (if any).
 * @return Pointer to the result of the thread execution (if any).
 */
void* receive_thread(void* arg);

#endif /// NETWORK_H
