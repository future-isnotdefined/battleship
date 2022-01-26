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

void testreceive(int serverPort, char ownAddress[], char buffer[], int sizeofBuffer)//targetAddress[16]
{

    //IN PEER WE TRUST
    int server_fd = 0,new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int opt = 1;
    char hello[1024] = {0};

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return;
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ownAddress);
    address.sin_port = htons(serverPort);

    if (bind(server_fd, (struct sockaddr *)&address, 
                                 sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                       (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    valread = recv(new_socket , buffer, sizeofBuffer, 0);
    
    close(server_fd);
    close(new_socket);
    return;
}