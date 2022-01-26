#ifndef __gameloop_h__
#define __gameloop_h__
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "netcode.h"

bool shoot(char * ownAddress, int port, char opponentAddress[], int enemyboard[][10], int ownboard[][10], int *hits, int shipFields,  char yourName[]);
int checkHit(int board[][10], int posY, int posX);
bool checkWin(int *hits, int shipFields);

#endif