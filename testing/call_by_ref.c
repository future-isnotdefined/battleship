#include <stdio.h>

void swap(int *x, int *y);
void hittin(int *hits);

int main (void) {

   /* local variable definition */
   int a = 100;
   int b = 200;

   int hits = 0;
 
   printf("Before swap, value of a : %d\n", a );
   printf("Before swap, value of b : %d\n", b );
   printf("Hits before function: %d\n", hits);
 
   /* calling a function to swap the values */
   swap(&a, &b);
   hittin(&hits);
 
   printf("After swap, value of a : %d\n", a );
   printf("After swap, value of b : %d\n", b );
   printf("Hits after function 1: %d\n", hits);

   hittin(&hits);

   printf("Hits after function 2: %d\n", hits);
 
   return 0;
}
void swap(int *x, int *y) {

   int temp;

   temp = *x; /* save the value of x */
   *x = *y;    /* put y into x */
   *y = temp; /* put temp into y */
  
   return;
}
void hittin(int *hits) {
    *hits += 1;
    printf("Hits in function (pointer): %d\n", *hits);
}