#ifndef NETWORK_H
#define NETWORK_H

void initialize_network(const char *client_ip, int port);
void send_message(const char *message);
void receive_message(char *buffer);
void cleanup_network();

void* send_thread(void* arg);
void* receive_thread(void* arg);

#endif // NETWORK_H