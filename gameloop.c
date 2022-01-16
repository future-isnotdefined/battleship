//Includes
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "board.h"


//Functions

int checkHit(int board[][10], int posY, int posX){
// 1 = Feld beschossen
// 0 = Feld SChiff
// -1 = Feld leer
if(board[posY][posX] == 0 ){ // Schiff getroffen
    return true;
}
if(board[posY][posX] == 1 || -2){  //bereits getroffen
    printf("Feld bereits beschossen\n");
    return -1;
}
if(board[posY][posX] == -1){ // garnichts getroffen
    return false;
}

} 

bool shoot(int board[][10], int * hits, char enemyName[], char yourName[]){ // gegnerisches Board und Trefferanzahl aktueller Spieler
    int checkHitInt;
    int posX;
    int posY;

    showEnemyBoard(board, enemyName);
   
    do {
        printf("Koordinaten f%cr Schuss angeben, Kapit%cn \"%s\"!\n", 129, 132, yourName);
        scanf(" %c %d", &posY, &posX);
        getchar();
        posY = posY - 65;
        posX = posX - 1;

        checkHitInt = checkHit(board, posY, posX);
        
    } while(checkHitInt == -1);

    if (checkHitInt == true) {
        printf("Schiff getroffen!\n");
        board[posY][posX] = 1;
        * hits++;
        return true; //ist true damit man nochmal schießen kann
    } else if(checkHitInt == false) {
        printf("Vorbei geschossen!\n");
        board[posY][posX] = -2; 
        return false; // nicht nochmal schießen bei 0 && -1
    }

return false;
}

/*
benutzerinput X/Y -> Funktion 

Prüfung treffer ( Check hit) 
wenn ja, dann benutzer mitteilen treffer mit printf

gegnerisches beschossenes feld anzeigen, (Schiff versenkt printf)



*/

bool checkWin(int hits){
    if (hits == 30){
        return true;
    } else {
        return false;
    }
}