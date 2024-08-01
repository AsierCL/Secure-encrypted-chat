# Secure encrypted chat

This is a simple live chat application implemented in C. It allows two users to communicate over a network using UDP sockets. The messages are encrypted using a basic XOR encryption for demonstration purposes. This may be updated and improved in the future.

#### **Disclaimer**
Please note again that the encryption method (XOR) is for demonstration purposes only. __It is not a secure encryption__, and should not be used in production due to its weak security.

## Files Description

- **main.c**: The main program file. It initializes the network, creates threads for sending and receiving messages, and handles user input.
- **include/crypto.h**: Header file for the encryption functions.
- **include/network.h**: Header file for the network functions.
- **src/crypto.c**: Source file for the encryption functions.
- **src/network.c**: Source file for the network functions.
- **Makefile**: Makefile to compile the program.

## Compilation

To compile the application, use the provided Makefile. Run the following command in the terminal:

```sh
make
```

This will generate an executable named main.

## Usage

Run the executable and follow the prompts to enter the IP address and port number of the other user you want to chat with. <br>



```sh
./main
```

You will be prompted to enter the IP address and the port number:

```sh
Enter the IP you want to chat with:
Enter the network port:
```

#### Recommendation
Any port from 0 to 65535 can be used, but to avoid conflicts, it is recommended to use a port higher than 1023 to avoid "well-known ports", and if possible also higher than 49152 to avoid "registered ports".

## Cleaning Up

To remove the compiled files, run:

```sh
make clean
```

To remove all generated files including the executable, run:

```sh
make cleanall
```