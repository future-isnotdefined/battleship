#ifndef __netcode_h__
#define __netcode_h__
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <pthread.h>

void receiving(int server_fd, char * buffer);
void *receive_thread(void *server_fd);
int initializePorts(int Port, char ownAddress[]);
void sending(int serverPort, char targetAddress[], char buffer[], int sizeofBuffer);

#endif