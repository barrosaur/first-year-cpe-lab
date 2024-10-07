/*
============================================================================
 FILE        : barroEl_LE5_21.c
 AUTHOR      : Ellaine Joyce A. Barro
 DESCRIPTION : Multiplication table
 COPYRIGHT   : created
 REVISION HISTORY
 Date:               By: 	                        Description:
 10/04/24	         Ellaine Joyce A. Barro         Made the entire program
============================================================================
*/

#include <stdio.h>

 /*
============================================================================
 FUNCTION    : main
 DESCRIPTION : Displays multiplication from rows and column input
 ARGUMENTS   : none
 RETURNS     : int
 		       Successful code execution with no errors
===========================================================================
*/

int main () {

    int i, j;
    int rows = 0, columns = 0;
    int validInput, multiply;

        while (rows <= 0) {
        
        //GET rows
        printf("Enter the number of rows: ");
        validInput = scanf("%d", &rows);

        if (validInput != 1) {
            while (getchar() != '\n'); //discards invalid inputs like letters
            printf("Invalid input. Must be a positive integer.\n");
            rows = 0; // reset rows to loop again
        } else if (rows <= 0) {
            printf("Invalid input. Must be a positive integer.\n");
        }
    }

    while (columns <= 0) {
        //GET columns
        printf("Enter the number of columns: ");
        validInput = scanf("%d", &columns);

        if (validInput != 1) {
            while (getchar() != '\n'); // discard invalid input
            printf("Invalid input. Must be a positive integer.\n");
            columns = 0; // reset columns to loop again
        } else if (columns <= 0) {
            printf("Invalid input. Must be a positive integer.\n");
        }
    }

    printf("=======================================================\n");

    for(i = 1; i <= rows; i++) {
        for(j = 1; j <= columns; j++) {
            multiply = i*j;
            printf("%d\t ", multiply);
        }
        printf("\n");
    }

    return 0;
}