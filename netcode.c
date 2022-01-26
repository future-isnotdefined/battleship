// C program to demonstrate peer to peer chat using Socket Programming
// write "gcc peer.c -o peer -pthread" to compile
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <pthread.h>




int initializePorts(int port, char ownAddress[]){ //ownAddress[15]

    //Initialize server ports start
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int k = 0;

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    // Forcefully attaching socket to the port

    address.sin_family = AF_INET;
    printf("\nEnter your own IP:");
    address.sin_addr.s_addr = inet_addr(ownAddress);
    address.sin_port = htons(port);

    //Printed the server socket addr and port
    printf("IP address is: %s\n", inet_ntoa(address.sin_addr));
    printf("port is: %d\n", (int)ntohs(address.sin_port));

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 5) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    int ch;
    //pthread_t tid;
    //pthread_create(&tid, NULL, &receive_thread, &server_fd); //Creating thread to keep receiving message in real time
    //Finished Server Port creation

    //Close the server when game is over
    //close(server_fd); USE IN MAIN

    return server_fd;
}

//Sending messages to port
void sending(int serverPort, char targetAddress[], char buffer[], int sizeofBuffer)//targetAddress[16]
{

    //IN PEER WE TRUST

    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char hello[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(targetAddress);
    serv_addr.sin_port = htons(serverPort);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return;
    }
    send(sock, buffer, sizeofBuffer, 0);//Need size and buffer
    close(sock);
}

//Calling receiving every 2 seconds
void *receive_thread(void *server_fd)
{
    int s_fd = *((int *)server_fd);
    while (1)
    {
        sleep(2);
        //receiving(s_fd);
    }
}

//Receiving messages on our port
void receiving(int server_fd, char * buffer)
{
    struct sockaddr_in address;
    int valread;
    int addrlen = sizeof(address);
    fd_set current_sockets, ready_sockets;

    //Initialize my current set
    FD_ZERO(&current_sockets);
    FD_SET(server_fd, &current_sockets);
    int k = 0;
    k++;
    ready_sockets = current_sockets;

    if (select(FD_SETSIZE, &ready_sockets, NULL, NULL, NULL) < 0)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < FD_SETSIZE; i++)
    {
        if (FD_ISSET(i, &ready_sockets))
        {

            if (i == server_fd)
            {
                int client_socket;

                if ((client_socket = accept(server_fd, (struct sockaddr *)&address,
                                            (socklen_t *)&addrlen)) < 0)
                {
                    perror("accept");
                    exit(EXIT_FAILURE);
                }
                FD_SET(client_socket, &current_sockets);
            }
            else
            {
                valread = recv(i, buffer, sizeof(buffer), 0);
                FD_CLR(i, &current_sockets);
            }
        }
    }
}