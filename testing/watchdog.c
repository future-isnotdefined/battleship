#include <stdio.h>
#include <stdbool.h>

int main (void) {
    // bool ship[5] = {true, true, true, true, true};
    
    bool schlachtschiffplayer1[5] = {false, false, false, false, false};
    bool kreuzer1player1[4] = {false, false, false, false};
    bool kreuzer2player1[4] = {false, false, false, false};
    bool zerstoerer1player1[3] = {false, false, false};
    bool zerstoerer2player1[3] = {true, true, true};
    bool zerstoerer3player1[3] = {false, false, false};
    bool uboot1player1[2] = {false, false};
    bool uboot2player1[2] = {false, false};
    bool uboot3player1[2] = {false, false};
    bool uboot4player1[2] = {false, false};
    
    bool shipsP1[10] = {schlachtschiffplayer1, kreuzer1player1, kreuzer2player1, zerstoerer1player1, zerstoerer2player1, zerstoerer3player1, uboot1player1, uboot2player1, uboot3player1, uboot4player1};

    int arrLen;
    int hitFields[10];
    bool destroyed[10];

    int sizeFields = sizeof(hitFields) / sizeof(hitFields[0]);
    int sizeDestro = sizeof(destroyed) / sizeof(destroyed[0]);

    for (int i = 0; i < sizeFields; i++) {
        hitFields[i] = 0;
    }

    for (int i = 0; i < sizeDestro; i++) {
        destroyed[i] = false;
    }

    arrLen = sizeof shipsP1 / sizeof shipsP1[0];
    // printf("\nArrLen: %d\n", arrLen);

    for (int i = 0; i < arrLen; i++) {

        for (int j = 0; j < sizeof(schlachtschiffplayer1); j++) {
            if (schlachtschiffplayer1[j] == true) {
            hitFields[i]++;
            printf("\nHits (i: %d, j1: %d): %d", i, j, hitFields[i]);
            }
            if (hitFields[i] == sizeof(schlachtschiffplayer1)) {
                destroyed[i] = true;
            }
        }

        i++;
        printf("\ni first change: %d", i);

        for (int j = 0; j < sizeof(kreuzer1player1); j++) {
            if (kreuzer1player1[j] == true) {
            hitFields[i] += 1;
            printf("\nHits (i: %d, j2: %d): %d", i, j, hitFields[i]);
            }
            if (hitFields[i] == sizeof(kreuzer1player1)) {
                destroyed[i] = true;
            }
        }

        i++;
        printf("\ni 2nd change: %d", i);

        for (int j = 0; j < sizeof(kreuzer2player1); j++) {
            if (kreuzer2player1[j] == true) {
            hitFields[i] += 1;
            printf("\nHits (i: %d, j3: %d): %d", i, j, hitFields[i]);
            }
            if (hitFields[i] == sizeof(kreuzer2player1)) {
                destroyed[i] = true;
            }
        }

        i++;
        printf("\ni 3rd change: %d", i);

        for (int j = 0; j < sizeof(zerstoerer1player1); j++) {
            if (zerstoerer1player1[j] == true) {
            hitFields[i]++;
            printf("\nHits (i: %d, j4: %d): %d", i, j, hitFields[i]);
            }
            if (hitFields[i] == sizeof(zerstoerer1player1)) {
                destroyed[i] = true;
            }
        }

        i++;

        for (int j = 0; j < sizeof(zerstoerer2player1); j++) {
            if (zerstoerer2player1[j] == true) {
            hitFields[i]++;
            printf("\nHits (i: %d, j5: %d): %d", i, j, hitFields[i]);
            }
            if (hitFields[i] == sizeof(zerstoerer2player1)) {
                destroyed[i] = true;
            }
        }

        i++;

        for (int j = 0; j < sizeof(zerstoerer3player1); j++) {
            if (zerstoerer3player1[j] == true) {
            hitFields[i]++;
            printf("\nHits (i: %d, j6: %d): %d", i, j, hitFields);
            }
            if (hitFields[i] == sizeof(zerstoerer3player1)) {
                destroyed[i] = true;
            }
        }

        i++;

        for (int j = 0; j < sizeof(uboot1player1); j++) {
            if (uboot1player1[j] == true) {
            hitFields[i]++;
            printf("\nHits (i: %d, j7: %d): %d", i, j, hitFields);
            }
            if (hitFields[i] == sizeof(uboot1player1)) {
                destroyed[i] = true;
            }
        }

        i++;

        for (int j = 0; j < sizeof(uboot2player1); j++) {
            if (uboot2player1[j] == true) {
            hitFields[i]++;
            printf("\nHits (i: %d, j8: %d): %d", i, j, hitFields);
            }
            if (hitFields[i] == sizeof(uboot2player1)) {
                destroyed[i] = true;
            }
        }

        i++;

        for (int j = 0; j < sizeof(uboot3player1); j++) {
            if (uboot3player1[j] == true) {
            hitFields[i]++;
            printf("\nHits (i: %d, j9: %d): %d", i, j, hitFields);
            }
            if (hitFields[i] == sizeof(uboot3player1)) {
                destroyed[i] = true;
            }
        }
        
        i++;
        
        for (int j = 0; j < sizeof(uboot4player1); j++) {
            if (uboot4player1[j] == true) {
            hitFields[i]++;
            printf("\nHits (i: %d, j10: %d): %d", i, j, hitFields);
            }
            if (hitFields[i] == sizeof(uboot4player1)) {
                destroyed[i] = true;
            }
        }

        i++;

        
        // if (hitFields == arrLen) {
        //     return true;
        // }
    }

    printf("\n-----------------------------------------\n");
    for (int i = 0; i < arrLen; i++) {
        printf("\nHits (Array Key: %d): %d; Destroyed: %d", i, hitFields[i], destroyed[i]);
    }
    
    return 0;
}