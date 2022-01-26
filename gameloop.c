//Includes
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "netcode.h"


//Functions

int receiveHit(char * ownAddress, int port, char opponentAddress[], int ownBoard[][10], int *hits, int shipFields, char buffer[], int bufferSize, int receiveBufferSize, char receiveBuffer[]){
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
                ownBoard[posY][posX] = 1;
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
                ownBoard[posY][posX] = -2;
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
    if (hitVal == 2){
        return 2;
    } else {
        return 1;
    }
}

int shoot(char buffer[], int sizeofBuffer, char receieveBuffer[], int sizeofReceieveBuffer, char * ownAddress, int port, char opponentAddress[], int enemyboard[][10], int ownboard[][10], int *hits, int shipFields, char yourName[], char enemyPlayer[]){ // gegnerisches Board und Trefferanzahl aktueller Spieler
    int checkHitInt = -1;
    int posX;
    char posY; //Changed to char because of int convertion

    do {
        printf("Koordinaten f%cr Schuss angeben, Kapit%cn \"%s\"!\n", 129, 132, yourName);
        printf("(Press $0 for showing your own board)\n");
        scanf(" %c %d", &posY, &posX);
        if (posY == '$'){
            showBoard(ownboard, yourName);
        } else {
            posY = posY - 65;
            posX = posX - 1;
            sprintf(buffer, "%d %d", posY, posX);
            sending(port, opponentAddress, buffer, sizeofBuffer);
            receive(port, ownAddress, receieveBuffer, sizeofReceieveBuffer);
            sscanf(receieveBuffer, "%d", &checkHitInt);
            if (checkHitInt == -1){
                printf("Kommander das ist nicht zulässig!\n");
            }
        }
    } while(checkHitInt == -1);

    if (checkHitInt != false) {
        printf("Schiff getroffen!\n");
        enemyboard[posY][posX] = 1;
        
        if (checkHitInt == 2){ //Receive 2 for win!
            return 2; //So that the function does not return true and the hitBool of the app main function does not repeat
        }

        // printf("\n\nhits (pointer): %d\n\n", *hits);
        // printf("\n\nhits (value): %d\n\n", hits);

        return 1; // ist true damit man nochmal schießen kann
    
    } else if(checkHitInt == 0) {
        printf("Vorbei geschossen!\n");
        enemyboard[posY][posX] = -2;
        showEnemyBoard(enemyboard, enemyPlayer);
        // printf("\n\n----- DEBUGGING ------- hier muesste rausgesprungen werden (checkHitInt: %d). \n\n", checkHitInt);
        return 0; // nicht nochmal schießen bei 0 && -1
    } else {
        return 0; 
    }
}

/*
benutzerinput X/Y -> Funktion 

Prüfung treffer ( Check hit) 
wenn ja, dann benutzer mitteilen treffer mit printf

gegnerisches beschossenes feld anzeigen, (Schiff versenkt printf)



*/