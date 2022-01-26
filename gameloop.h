#ifndef __gameloop_h__
#define __gameloop_h__
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "netcode.h"

int shoot(char buffer[], int sizeofBuffer, char receieveBuffer[], int sizeofReceieveBuffer, char * ownAddress, int port, char opponentAddress[], int enemyboard[][10], int ownboard[][10], int *hits, int shipFields, char yourName[], char enemyPlayer[]);
int receiveHit(char * ownAddress, int port, char opponentAddress[], int ownBoard[][10], int *hits, int shipFields, char buffer[], int bufferSize, int receiveBufferSize, char receiveBuffer[]);
bool checkWin(int *hits, int shipFields);

#endif