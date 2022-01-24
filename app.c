#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "board.h"
#include "gameloop.h"

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
    int hitsplayer1  = 0;
    int shipFields1;

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
    int hitsplayer2 = 0;
    int shipFields2;

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
    printf("\n Enter dr%ccken um zu \"%s\" zu wechseln ", 129, player2);
    getchar();

    //Clear screen
    system("cls");

    //Player2
    // showBoard(board2);

    // Schiffe Platzieren
    uiPlaceShips(board2, schlachtschiffplayer2, sizeof(schlachtschiffplayer2)-1, "Schlachtschiff", player2);

    // uiPlaceShips(board2, kreuzer1player2, sizeof(kreuzer1player2)-1, "Erster Kreuzer", player2);
    // uiPlaceShips(board2, kreuzer2player2, sizeof(kreuzer2player2)-1, "Zweiter Kreuzer", player2);

    // uiPlaceShips(board2, zerstoerer1player2, sizeof(zerstoerer1player2)-1, "Erster Zerstoerer", player2);
    // uiPlaceShips(board2, zerstoerer2player2, sizeof(zerstoerer2player2)-1, "Zweiter Zerstoerer", player2);
    // uiPlaceShips(board2, zerstoerer3player2, sizeof(zerstoerer3player2)-1, "Dritter Zerstoerer", player2);

    // uiPlaceShips(board2, uboot1player2, sizeof(uboot1player2)-1, "Erstes U-Boot", player2);
    // uiPlaceShips(board2, uboot2player2, sizeof(uboot2player2)-1, "Zweites U-Boot", player2);
    // uiPlaceShips(board2, uboot3player2, sizeof(uboot3player2)-1, "Drittes U-Boot", player2);
    // uiPlaceShips(board2, uboot4player2, sizeof(uboot4player2)-1, "Viertes U-Boot", player2);

    shipFields2 = countShipFields(board2);
    
    // nach dem Platzieren
    showBoard(board2, player2);
    printf("\n Enter dr%ccken um zu \"%s\" zu wechseln ", 129, player1);
    getchar();
    fflush(stdin);

    //Clear screen
    system("cls");


    //Game Loop -----------------------------------------
    currentPlayer = 1;
    while (gameoverBool) {
        if (currentPlayer == 1) {
            do {
                // printf("\n\n----- DEBUGGING ------- hitsplayer1 vor function pass: %d\n\n", hitsplayer1);
                hitBool = shoot(board1, board2, &hitsplayer1, shipFields2, player2, player1); // spieler 1 schießt auf board2 -> enemy board Eingabeparam
                // printf("\n\n----- DEBUGGING ------- hits nach function pass: %d\n\n", hitsplayer1);
                    if(checkWin(&hitsplayer1, shipFields2) == true) {
                        printf("-----   %s hat gewonnen!   -----\n", player1);
                        showBoard(board1, player1);
                        printf("\n\n");
                        showBoard(board2, player2);
                        getchar();
                        gameoverBool = false;
                        system("cls");
                    }
            } while (hitBool);

            if(!(gameoverBool)) {
                break;
            }
            
            currentPlayer = 2;
            printf("\n\"%s\" ist dran...\n[press enter]\n", player2);
            getchar();
            //Clear screen
            system("cls");
        } else if (currentPlayer == 2) {
            do {
                // printf("\n\n----- DEBUGGING ------- hitsplayer2 vor function pass: %d\n\n", hitsplayer2);
                hitBool = shoot(board2, board1, &hitsplayer2, shipFields1, player1, player2); // spieler 2 schießt auf board1
                // printf("\n\n----- DEBUGGING ------- hitsplayer2 nach function pass: %d\n\n", hitsplayer2);
                    if (checkWin(&hitsplayer2, shipFields1) == true) {
                        printf("-----   %s hat gewonnen!    -----\n", player2);
                        showBoard(board2, player2);
                        printf("\n\n");
                        showBoard(board1, player1);
                        getchar();
                        gameoverBool = false;
                        break;
                    }
                } while (hitBool);
            currentPlayer = 1;
            printf("\n\n\"%s\" ist dran...\n\n[press enter]\n", player1);
            getchar();
            //Clear screen
            system("cls");
        } else {
            printf("ERROR player identifier mismatch\n");
        }
    }
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