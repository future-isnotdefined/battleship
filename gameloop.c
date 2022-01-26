//Includes
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "netcode.h"


//Functions

void receiveHit(char * ownAddress, int port, char opponentAddress[], int ownBoard[][10], int *hits, int shipFields, char buffer[], int bufferSize, int receiveBufferSize, char receiveBuffer[]){
    // 1 = Feld mit Schiff bereits beschossen
    // -2 = Feld leer bereits beschossen
    // 0 = Feld mit Schiff
    // -1 = Feld leer

    int posY;
    int posX;
    int hitVal;

    do {
        receive(port, ownAddress, receiveBuffer, receiveBufferSize);

        sscanf(receiveBuffer, "%d %d", &posY, &posX);

        int posValue = ownBoard[posY][posX];

        switch(posValue) {
            case 0 : // getroffen
                hitVal = 1;
                *hits += 1;
                break;
            case 1 : // getroffenes feld doppelt beschossen
                // printf("Feld bereits beschossen\n");
                hitVal = -1;
                break;
            case -2 : // leeres feld doppelt beschossen
                // printf("Feld bereits beschossen\n");
                hitVal = -1;
                break;
            case -1 : // vorbei
                hitVal = 0;
                break;
            default :
                printf("ERROR VERKACKT PROGRAMM KAPUTT. CONTACT DEVS...");
        }

        if (*hits == shipFields){
            hitVal = 2;
        }

        sprintf(buffer, "%d", hitVal);
        sending(port, opponentAddress, buffer, bufferSize);

    } while (hitVal == 1 || hitVal == -1);

}

bool shoot(char * ownAddress, int port, char opponentAddress[], int enemyboard[][10], int ownboard[][10], int *hits, int shipFields,  char yourName[]){ // gegnerisches Board und Trefferanzahl aktueller Spieler
    int checkHitInt = -1;
    int posX;
    char posY; //Changed to char because of int convertion
    char buffer[100];
    char receiveBuffer[100];

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
        receive(port, ownAddress, receiveBuffer, sizeof(buffer));
        getchar();
        
    }
    
}

/*
benutzerinput X/Y -> Funktion 

Prüfung treffer ( Check hit) 
wenn ja, dann benutzer mitteilen treffer mit printf

gegnerisches beschossenes feld anzeigen, (Schiff versenkt printf)



*/