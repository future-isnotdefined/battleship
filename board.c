//Includes
#include <stdio.h>
#include <stdbool.h>


//Functions
void genBoard(int board1[][10], int board2[][10]) {
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

bool placeShip(int board[][10], bool ship[], int size, int pos1Y, int pos1X, int pos2Y, int pos2X){

    //printf("\npos1Y: %d  pos1X: %d  pos2Y: %d  pos2X: %d  size: %d\n\n", pos1Y, pos1X, pos2Y, pos2X, size);

    //Check if coords are in range
    if (pos1Y < 0 || pos1Y > 9 || pos1X < 0 || pos1X > 9 || pos2Y < 0 || pos2Y > 9 || pos2X < 0 || pos2X > 9) { //If coordinate is out of range
        printf("ERROR out of range\n");
        return false;
    }

    //Check if the orientation is either vertically or horizontally or wrong
    if (pos1Y != pos2Y){
        if (pos1X != pos2X){
            printf("ERROR can't place ships that way\n");
            return false;
        }
    }

    //If ship is beign set horizontally
    if (pos1Y == pos2Y) {
        //Check which is bigger
        if (pos1X > pos2X){
            // check size
            if (pos1X - pos2X != size) {
                printf("ERROR ship size mismatch\n");
                return false;
            }
            // check occupation
            for (int i = pos2X; i <= pos1X; i++) {
                if (board[pos1Y][i] != -1) {
                    printf("ERROR space already occupied\n");
                    return false;
                }
                //Insert loop to assign the ship
            }
            for (int i = pos2X, j = 0; i <= pos1X; i++, j++) {
                ship[j] = false;
                board[pos1Y][i] = ship[j];
            }
            return true;
        //Case pos 2 is bigger
        } else {
            // check size
            if (pos2X - pos1X != size) {
                printf("ERROR ship size mismatch\n");
                return false;
            }
            // check occupation
            for (int i = pos1X; i <= pos2X; i++) {
                if (board[pos1Y][i] != -1) {
                    printf("ERROR space already occupied\n");
                    return false;
                }
                //Insert loop to assign the ship
            }
            for (int i = pos1X, j = 0; i <= pos2X; i++, j++) {
                ship[j] = false;
                board[pos1Y][i] = ship[j];
            }
            return true;
        }
    }


    //If ship is beign set vertically
    if (pos1X == pos2X) {
        //Check which is bigger
        if (pos1Y > pos2Y){
            // check size
            if (pos1Y - pos2Y != size) {
                printf("ERROR ship size mismatch\n");
                return false;
            }
            // check occupation
            for (int i = pos2Y; i <= pos1Y; i++) {
                if (board[i][pos1X] != -1) {
                    printf("ERROR space already occupied\n");
                    return false;
                }
                //Insert loop to assign the ship
            }
            for (int i = pos2Y, j = 0; i <= pos1Y; i++, j++) {
                ship[j] = false;
                board[i][pos1X] = ship[j];
            }
            return true;
        //Case pos 2 is bigger
        } else {
            // check size
            if (pos2Y - pos1Y != size) {
                printf("ERROR ship size mismatch\n");
                return false;
            }
            // check occupation
            for (int i = pos1Y; i <= pos2Y; i++) {
                if (board[i][pos1X] != -1) {
                    printf("ERROR space already occupied\n");
                    return false;
                }
                //Insert loop to assign the ship
            }
            for (int i = pos1Y, j = 0; i <= pos2Y; i++, j++) {
                ship[j] = false;
                board[i][pos1X] = ship[j];
            }
            return true;
        }

    }

}

void showBoard(int board[][10]){
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

void uiPlaceShips(int board[][10], bool ship[], int size, char shipName[]) {
    bool falsePlacement = false;
    char pos1Y;
    int pos1X;
    char pos2Y;
    int pos2X;

    while (!(falsePlacement)) {
        showBoard(board);
        // Schiffe Platzieren
        printf("%s platzieren: \n", shipName);
        printf("Startkoordinaten eingeben (Buchstabe, Zahl)\n");
        scanf(" %c %d", &pos1Y, &pos1X);
        pos1Y = pos1Y - 65;
        pos1X = pos1X - 1;
        //printf("\npos1Y: %d pos1X: %d\n", pos1Y, pos1X); TEST
        printf("Endkoordinaten eingeben (Buchstabe, Zahl)\n");
        scanf(" %c %d", &pos2Y, &pos2X);
        pos2Y = pos2Y - 65;
        pos2X = pos2X - 1;
        falsePlacement = placeShip(board, ship, size, pos1Y, pos1X, pos2Y, pos2X); // -1 for index matching for arrays
    }

}