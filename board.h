#ifndef __board_h__
#define __board_h__

void genBoard(int board1[][10], int board2[][10]);
bool placeShip(int board[][10], bool ship[], int size, int pos1Y, int pos1X, int pos2Y, int pos2X);
void showBoard(int board[][10]);
void uiPlaceShips(int board[][10], bool ship[], int size, char shipName[]);

#endif