//Includes
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "board.h"


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

bool shoot(int ownboard[][10], int board[][10], int *hits, int shipFields, char enemyName[], char yourName[]){ // gegnerisches Board und Trefferanzahl aktueller Spieler
    int checkHitInt = -1;
    int posX;
    char posY; //Changed to char because of int convertion

    showEnemyBoard(board, enemyName);
   
    do {
        printf("Koordinaten f%cr Schuss angeben, Kapit%cn \"%s\"!\n", 129, 132, yourName);
        printf("(Press $0 for showing your own board)\n");
        scanf(" %c %d", &posY, &posX);
        if (posY == '$' && posX != 42){
            showBoard(ownboard, yourName);
        } else if (posY == '$' && posX == 42){
            showBoard(board, enemyName);
        } else {
        getchar();
            posY = posY - 65;
            posX = posX - 1;
            checkHitInt = checkHit(board, posY, posX);
            // printf("\n\n----- DEBUGGING ------- hitValue: %d\tposValue: %d\n\n", checkHitInt, board[posY][posX]);
        }
        
    } while(checkHitInt == -1);

    if (checkHitInt == true) {
        printf("Schiff getroffen!\n");
        board[posY][posX] = 1;
        *hits += 1;

        // dreckige lösung: alle schiff strukturen durchlaufen (optimal: watch for change: alles 1? danach zustand speichern).
        // problem: ALLE schiff strukturen müssen accessible in funktion sein
            // idee: alle schiffe (von einem spieler) in einen array packen und dann leichter übergeben
        // wenn update = schiff struktur voll getroffen (alle felder 1)

        // --- bis hier: bereits umgesetzt in watchdog.c -> testing könnt ihr euch rauskopieren ---
        // aber "watch for change" fehlt noch.
        // sollte möglich sein über: "alten" zustand speichern, alle arrays durchlaufen, neuen zustand mit altem vergleichen (reminder: pi und maschinengenauigkeit),
        // bei änderungen nur die differenz ausgeben (nur das neu versenkte schiff)...

        //     => print "shipName" versenkt! (nur einmal bei change)
            // => board Variablen (bei change) updaten (board[schiffelder] = 2), um versenkt zu zeigen
        
        if (checkWin(hits, shipFields) == true){
            return false; //So that the function does not return true and the hitBool of the app main function does not repeat
        }

        // printf("\n\nhits (pointer): %d\n\n", *hits);
        // printf("\n\nhits (value): %d\n\n", hits);

        return true; // ist true damit man nochmal schießen kann
    } else if(checkHitInt == false) {
            printf("Vorbei geschossen!\n");
            board[posY][posX] = -2;
            showEnemyBoard(board, enemyName);
            // printf("\n\n----- DEBUGGING ------- hier muesste rausgesprungen werden (checkHitInt: %d). \n\n", checkHitInt);
            return false; // nicht nochmal schießen bei 0 && -1
        } else {
            return false; 
       }
}

/*
benutzerinput X/Y -> Funktion 

Prüfung treffer ( Check hit) 
wenn ja, dann benutzer mitteilen treffer mit printf

gegnerisches beschossenes feld anzeigen, (Schiff versenkt printf)



*/