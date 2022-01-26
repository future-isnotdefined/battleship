#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "board.h"
#include "gameloop.h"
#include "netcode.h"

void game (char player1[], char player2[], int *abortion) {
    //Definition of Variables ---------------------------
    //[y][x]
    int board1[10][10];
    int board2[10][10];
    bool gameoverBool = true;
    int currentPlayer;
    bool hitBool;

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
    bool shipsP1[10] = {schlachtschiffplayer1, kreuzer1player1, kreuzer2player1, zerstoerer1player1, zerstoerer2player1, zerstoerer3player1, uboot1player1, uboot2player1, uboot3player1, uboot4player1};
    // struct alarm... ^^
    int hitsplayer1  = 0;
    int shipFields1;
    int port = 402;
    char ownAddress[16];
    char opponentAddress[16];
    int socket;

    //if ship is hit it is 1 otherwise it is 0
    //Board is -1 if no ship is on the space

    genBoard(board1, board2);

    //Player1
    uiPlaceShips(board1, schlachtschiffplayer1, sizeof(schlachtschiffplayer1)-1, "Schlachtschiff", player1);

    // uiPlaceShips(board1, kreuzer1player1, sizeof(kreuzer1player1)-1, "Erster Kreuzer", player1);
    // uiPlaceShips(board1, kreuzer2player1, sizeof(kreuzer2player1)-1, "Zweiter Kreuzer", player1);

    // uiPlaceShips(board1, zerstoerer1player1, sizeof(zerstoerer1player1)-1, "Erster Zerstoerer", player1);
    // uiPlaceShips(board1, zerstoerer2player1, sizeof(zerstoerer2player1)-1, "Zweiter Zerstoerer", player1);
    // uiPlaceShips(board1, zerstoerer3player1, sizeof(zerstoerer3player1)-1, "Dritter Zerstoerer", player1);

    // uiPlaceShips(board1, uboot1player1, sizeof(uboot1player1)-1, "Erstes U-Boot", player1);
    // uiPlaceShips(board1, uboot2player1, sizeof(uboot2player1)-1, "Zweites U-Boot", player1);
    // uiPlaceShips(board1, uboot3player1, sizeof(uboot3player1)-1, "Drittes U-Boot", player1);
    // uiPlaceShips(board1, uboot4player1, sizeof(uboot4player1)-1, "Viertes U-Boot", player1);

    shipFields1 = countShipFields(board1);

    // nach dem Platzieren
    showBoard(board1, player1);

    printf("Eigene IP Adresse eingeben\n");
    scanf("%s", ownAddress);
    getchar();

    socket = initializePorts(port, ownAddress);

    printf("Gegnerische IP Adresse eingeben\n");
    scanf("%s", opponentAddress);
    getchar();
    //Give another name to other player
    //Game Loop -----------------------------------------
    while (gameoverBool) {
        // printf("\n\n----- DEBUGGING ------- hitsplayer1 vor function pass: %d\n\n", hitsplayer1);
        hitBool = shoot(socket, port, opponentAddress, board2, board1, &hitsplayer1, shipFields1, player1); // spieler 1 schießt auf board2 -> enemy board Eingabeparam
        // printf("\n\n----- DEBUGGING ------- hits nach function pass: %d\n\n", hitsplayer1);
            //if(checkWin(&hitsplayer1) == true) {
                //printf("-----   %s hat gewonnen!   -----\n", player1);
                showBoard(board1, player1);
                printf("\n\n");
                showBoard(board2, player2);
                getchar();
                gameoverBool = false;
                system("cls");
            //}
    }
    close(socket);
    printf("[-1] Spiel beenden  | [andere Taste] Erneut spielen\n");
    scanf(" %d", abortion);
    getchar();
    system("cls");
    splashScreen("title.txt"); // end screen oder (viel sinnvoller) erneut spielen direkt möglich machen
    getchar();
    getchar();
    system("cls");
}


int main (void) {

    //Definition of Variables ---------------------------
    char player1[30];
    char player2[30];

    int abortion = 0;
    //if ship is hit it is 1 otherwise it is 0
    //Board is -1 if no ship is on the space

    splashScreen("title.txt");
    getchar();
    system("cls");

    //Pre Loop ------------------------------------------
    printf("Name Spieler 1: ");
    scanf(" %[^\n]", player1);
    getchar();
    printf("\nName Spieler 2: ");
    scanf(" %[^\n]", player2);
    getchar();

    while (abortion != -1) {
        game(player1, player2, &abortion);
    }
    
    return 0;
}