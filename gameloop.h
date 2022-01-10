#ifndef __gameloop_h__
#define __gameloop_h__

void shoot(int * board, int posX, int posY, int * hits);
void checkHit(int * board, int posY, int posX, int hits);
void showHit();
bool checkWin(int hits);

#endif