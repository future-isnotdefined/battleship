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
    // show empty board
    // showBoard(board1);

    //Player1
    uiPlaceShips(board1, schlachtschiffplayer1, sizeof(schlachtschiffplayer1)-1, "Schlachtschiff");

    uiPlaceShips(board1, kreuzer1player1, sizeof(kreuzer1player1)-1, "Erster Kreuzer");
    uiPlaceShips(board1, kreuzer2player1, sizeof(kreuzer2player1)-1, "Zweiter Kreuzer");

    uiPlaceShips(board1, zerstoerer1player1, sizeof(zerstoerer1player1)-1, "Erster Zerstoerer");
    uiPlaceShips(board1, zerstoerer2player1, sizeof(zerstoerer2player1)-1, "Zweiter Zerstoerer");
    uiPlaceShips(board1, zerstoerer3player1, sizeof(zerstoerer3player1)-1, "Dritter Zerstoerer");

    uiPlaceShips(board1, uboot1player1, sizeof(uboot1player1)-1, "Erstes U-Boot");
    uiPlaceShips(board1, uboot2player1, sizeof(uboot2player1)-1, "Zweites U-Boot");
    uiPlaceShips(board1, uboot3player1, sizeof(uboot3player1)-1, "Drittes U-Boot");
    uiPlaceShips(board1, uboot4player1, sizeof(uboot4player1)-1, "Viertes U-Boot");


    // nach dem Platzieren
    showBoard(board1);

    //Clear screen


    //Switch Player
   

    //Player2
    showBoard(board2);

    // Schiffe Platzieren
    uiPlaceShips(board1, schlachtschiffplayer2, sizeof(schlachtschiffplayer2)-1, "Schlachtschiff");
    
    uiPlaceShips(board1, kreuzer1player2, sizeof(kreuzer1player2)-1, "Erster Kreuzer");
    uiPlaceShips(board1, kreuzer2player2, sizeof(kreuzer2player2)-1, "Zweiter Kreuzer");

    uiPlaceShips(board1, zerstoerer1player2, sizeof(zerstoerer1player2)-1, "Erster Zerstoerer");
    uiPlaceShips(board1, zerstoerer2player2, sizeof(zerstoerer2player2)-1, "Zweiter Zerstoerer");
    uiPlaceShips(board1, zerstoerer3player2, sizeof(zerstoerer3player2)-1, "Dritter Zerstoerer");

    uiPlaceShips(board1, uboot1player2, sizeof(uboot1player2)-1, "Erstes U-Boot");
    uiPlaceShips(board1, uboot2player2, sizeof(uboot2player2)-1, "Zweites U-Boot");
    uiPlaceShips(board1, uboot3player2, sizeof(uboot3player2)-1, "Drittes U-Boot");
    uiPlaceShips(board1, uboot4player2, sizeof(uboot4player2)-1, "Viertes U-Boot");

    // nach dem Platzieren
    showBoard(board2);


    //Game Loop -----------------------------------------
    while(gameoverBool){

    }

    return 0;
}