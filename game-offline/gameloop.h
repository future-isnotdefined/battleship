#ifndef __gameloop_h__
#define __gameloop_h__
#include <stdio.h>
#include <stdlib.h>

bool shoot(int ownboard[][10], int board[][10], int *hits, int shipFields, char enemyName[], char yourName[]);
int checkHit(int board[][10], int posY, int posX);
bool checkWin(int *hits, int shipFields);

#endif