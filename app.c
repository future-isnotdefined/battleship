#include <stdio.h>
#include <stdbool.h>
#include "board.h"
#include "gameloop.h"


int main (void) {

    //Definition of Variables ---------------------------
    char player1[10];
    char player2[10];
    //[y][x]
    int board1[10][10];
    int board2[10][10];
    int posY;
    int posX;
    bool gameoverBool;
    int currentPlayer;

    //Ships player 1
    bool schlachtschiffplayer1[5];
    bool kreuzer1player1[4];
    bool kreuzer2player1[4];
    bool zerstoerer1player1[3];
    bool zerstoerer2player1[3];
    bool zerstoerer3player1[3];
    bool uboot1player1[2];
    bool uboot2player1[2];
    bool uboot3player1[2];
    bool uboot4player1[2];
    bool hitsplayer1;

    //Ships player 2
    bool schlachtschiffplayer2[5];
    bool kreuzer1player2[4];
    bool kreuzer2player2[4];
    bool zerstoerer1player2[3];
    bool zerstoerer2player2[3];
    bool zerstoerer3player2[3];
    bool uboot1player2[2];
    bool uboot2player2[2];
    bool uboot3player2[2];
    bool uboot4player2[2];
    bool hitsplayer1;

    //if ship is hit it is 1 otherwise it is 0
    //Board is -1 if no ship is on the space

    //Pre Loop ------------------------------------------
    printf("");
    printf("");

    genBoard(board1, board2);

    //Player1
    showBoard(board1);
    showBoard(board1);

    //Clear screen


    //Switch Player
   

    //Player2
    showBoard(board1);
    showBoard(board1);


    //Game Loop -----------------------------------------
    while(gameoverBool){

    }

    return 0;
}