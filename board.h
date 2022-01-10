#ifndef __board_h__
#define __board_h__

void genBoard(int * board1, int * board2);
bool placeShip(int * board, int * ship, int size, int pos1Y, int pos1X);
void showBoard(int * board);

#endif