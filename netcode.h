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

void sending(int serverPort, char targetAddress[], char buffer[], int sizeofBuffer);
void testreceive(int serverPort, char ownAddress[], char buffer[], int sizeofBuffer);

#endif