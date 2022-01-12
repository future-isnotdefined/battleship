//Includes
#include <stdio.h>
#include <stdbool.h>


//Functions
void genBoard(int board1[10][10], int board2[10][10]) {
    for (int y = 0; y < 10; y++){
        for (int x = 0; x < 10; x++)
        {
            board1[y][x] = -1;
            board2[y][x] = -1;
        }
    }
}

/* schiffe in struct initialisieren.

struct beinhaltet:

- Spieler
- (deutscher) Ausgabename vom Schiff
- Anzahl
- Größe

*/

bool placeShip(int board[10][10], int ship[], int size, int pos1Y, int pos1X, int pos2Y, int pos2X){

    board[pos1Y-1][pos1X-1] = ship[0];

    //Check if coords are in range
    if (pos1Y < 0 || pos1Y > 9 || pos1X < 0 || pos1X > 9 || pos2Y < 0 || pos2Y > 9 || pos2X < 0 || pos2X > 9) { //If coordinate is out of range
        printf("ERROR out of range");
        return false;
    }

    //Check if the orientation is either vertically or horizontally or wrong
    if (pos1Y != pos2Y){
        if (pos1X != pos2X){
            printf("ERROR can't place ships that way");
            return false;
        }
    }

    //If ship is beign set horizontally
    if (pos1Y == pos2Y) {
        //Check which is bigger
        if (pos1X > pos2X){
            for (int i = pos2X; i <= pos1X; i++) {
                if (board[pos1Y-1][i-1] != -1) {
                    printf("ERROR space already occupied");
                    return false;
                }
                //Insert loop to assign the ship
                for (int i = pos2X, j = 0; i <= pos1X; i++, j++) {
                    ship[j] = false;
                    board[pos1Y-1][i-1] = ship[j];
                }
            }
        //Case pos 2 is bigger
        } else {
            for (int i = pos1X; i <= pos2X; i++) {
                if (board[pos1Y-1][i-1] != -1) {
                    printf("ERROR space already occupied");
                    return false;
                }
                //Insert loop to assign the ship
                for (int i = pos1X, j = 0; i <= pos2X; i++, j++) {
                    ship[j] = false;
                    board[pos1Y-1][i-1] = ship[j];
                }
            }
        }
    }


    //If ship is beign set vertically
    if (pos1X == pos2X) {
        //Check which is bigger
        if (pos1Y > pos2Y){
            for (int i = pos2Y; i <= pos1Y; i++) {
                if (board[i-1][pos1X-1] != -1) {
                    printf("ERROR space already occupied");
                    return false;
                }
                //Insert loop to assign the ship
                for (int i = pos2Y, j = 0; i <= pos1Y; i++, j++) {
                    ship[j] = false;
                    board[i-1][pos1X-1] = ship[j];
                }
            }
        //Case pos 2 is bigger
        } else {
            for (int i = pos1Y; i <= pos2Y; i++) {
                if (board[i-1][pos1X-1] != -1) {
                    printf("ERROR space already occupied");
                    return false;
                }
                //Insert loop to assign the ship
                for (int i = pos1Y, j = 0; i <= pos2Y; i++, j++) {
                    ship[j] = false;
                    board[i-1][pos1X-1] = ship[j];
                }
            }
        }

    }

}

void showBoard(int board[10][10]){
    int charsize = 65; //65 is A 97 is a
    //Print the top row
    printf("+");
    for (int i = 1; i < 11; i++){
        printf("  %d",i);
    }
    printf(" +");
    printf("\n");

    //Print every row with the field names
    for (int y = 0; y < 10; y++){
        printf("%c", y + charsize); //alphabet before
        for (int x = 0; x < 10; x++)
        {
            if (board[y][x] == -1) {
                printf("  .");
            } else if (board[y][x] == 0) {
                printf("  O");
            } else {
                printf("  X");
            }
        }
        printf("  %c", y + charsize); //alphabet after
        printf("\n");
    }

    //Print the last row
    printf("+");
    for (int i = 1; i < 11; i++){
        printf("  %d",i);
    }
    printf(" +");
    printf("\n");
}