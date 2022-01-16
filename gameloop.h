#ifndef __gameloop_h__
#define __gameloop_h__
#include <stdio.h>
#include <stdlib.h>

bool shoot(int board[][10], int * hits, char enemyName[], char yourName[]);
int checkHit(int board[][10], int posY, int posX);
bool checkWin(int hits);

#endif