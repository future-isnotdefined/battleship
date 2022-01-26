//Includes
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "netcode.h"


//Functions

int checkHit(int board[][10], int posY, int posX){
    // 1 = Feld mit Schiff bereits beschossen
    // -2 = Feld leer bereits beschossen
    // 0 = Feld mit Schiff
    // -1 = Feld leer
    int posValue = board[posY][posX];

    switch(posValue) {
        case 0 : // getroffen
            return true;
            break;
        case 1 : // getroffenes feld doppelt beschossen
            printf("Feld bereits beschossen\n");
            return -1;
            break;
        case -2 : // leeres feld doppelt beschossen
            printf("Feld bereits beschossen\n");
            return -1;
            break;
        case -1 : // vorbei
            return false;
            break;
        default :
            printf("ERROR value not handled");
    }
}

bool checkWin(int *hits, int shipFields){
    if (*hits == shipFields){
        return true;
    } else {
        return false;
    }
}

bool shoot(char * ownAddress, int port, char opponentAddress[], int enemyboard[][10], int ownboard[][10], int *hits, int shipFields,  char yourName[]){ // gegnerisches Board und Trefferanzahl aktueller Spieler
    int checkHitInt = -1;
    int posX;
    char posY; //Changed to char because of int convertion
    char buffer[100];
    char receieveBuffer[100];
    *receieveBuffer = 0;

    //showEnemyBoard(board, enemyName);
   
    printf("Koordinaten f%cr Schuss angeben, Kapit%cn \"%s\"!\n", 129, 132, yourName);
    printf("(Press $0 for showing your own board)\n");
    scanf(" %c %d", &posY, &posX);
    if (posY == '$' && posX != 42){
        showBoard(ownboard, yourName);
    } else if (posY == '$' && posX == 42){
        //showBoard(enemyboard, enemyName);
    } else {
        getchar();
        posY = posY - 65;
        posX = posX - 1;
        sprintf(buffer, "%d %d", posY, posX);
        sending(port, opponentAddress, buffer, sizeof(buffer));
        //checkHitInt = checkHit(board, posY, posX);
        testreceive(port, ownAddress, receieveBuffer, sizeof(buffer));
        getchar();
        
    }
    
}

/*
benutzerinput X/Y -> Funktion 

Prüfung treffer ( Check hit) 
wenn ja, dann benutzer mitteilen treffer mit printf

gegnerisches beschossenes feld anzeigen, (Schiff versenkt printf)



*/