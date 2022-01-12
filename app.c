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
    int pos1Y;
    int pos1X;
    int pos2Y;
    int pos2X;
    bool gameoverBool = true;
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
    bool hitsplayer2;

    //if ship is hit it is 1 otherwise it is 0
    //Board is -1 if no ship is on the space

    //Pre Loop ------------------------------------------
    printf("Name Spieler 1: ");
    scanf(" %[^\n]", player1);
    printf("\nName Spieler 2: ");
    scanf(" %[^\n]", player2);

    genBoard(board1, board2);

    //Player1
    showBoard(board1);

    // Schiffe Platzieren
    printf("Schlachtschiff platzieren: \n");
    printf("Startkoordinaten eingeben (Buchstabe, Zahl)\n");
    scanf(" %c %d", &pos1Y, &pos1X);
    // pos1Y = pos1Y - 65;
    // pos1X = pos1X - 1;
    printf("\npos1Y: %d pos1X: %d\n", pos1Y, pos1X);
    printf("Endkoordinaten eingeben (Buchstabe, Zahl)");
    scanf("%d %d", &pos2Y, &pos2X);
    pos2Y = pos2Y - 65;
    pos2X = pos2X - 1;
    placeShip(board1, schlachtschiffplayer1, sizeof(schlachtschiffplayer1), pos1Y, pos1X, pos2Y, pos2X);

    // nach dem Platzieren
    showBoard(board1);

    //Clear screen


    //Switch Player
   

    //Player2
    showBoard(board2);

    // Schiffe Platzieren

    // nach dem Platzieren
    // showBoard(board2);


    //Game Loop -----------------------------------------
    while(gameoverBool){

    }

    return 0;
}