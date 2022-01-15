//Includes
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


//Functions

int checkHit(int board[][10], int posY, int posX){
// 1 = Feld beschossen
// 0 = Feld SChiff
// -1 = Feld leer
if(board[posY][posX] == 0 ){ // Schiff getroffen
    return true;
}
if(board[posY][posX] == 1||-2){  //bereits getroffen
    printf("Feld bereits beschossen\n");
    return -1;
}
if(board[posY][posX] == -1){ // garnichts getroffen
    return false;
}

} 

bool shoot(int board[][10], int * hits){
    int checkHitInt;
    int posX;
    int posY;
   
    do{
        printf("Koordinaten f%cr Schuss angeben Kapit%cn!\n",192,227);
        scanf(" %c %d", &posY, &posX);
        getchar();
        posY = posY - 65;
        posX = posX - 1;

        checkHitInt = checkHit(board, posY, posX);
        
    }while(checkHitInt == -1);

    if(checkHitInt == true){
        printf("Schiff getroffen!\n");
        board[posY][posX] = 1;
        * hits++;
        return true; //ist true damit man nochmal schießen kann
    }else if(checkHitInt == false){
        printf("nicht getroffen\n");
        board[posY][posX] = -2; 
        return false; // nicht nochaml schießen bei 0 && -1
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
        return false;
    } else {
        return true;
    }
}