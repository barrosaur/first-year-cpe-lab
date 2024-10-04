/*
============================================================================
 FILE        : barroEl_LE5_22.c
 AUTHOR      : Ellaine Joyce A. Barro
 DESCRIPTION : Triangle Number
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
 DESCRIPTION : Displays triangle of numbers from 1 to num
 ARGUMENTS   : none
 RETURNS     : int
 		       Successful code execution with no errors
===========================================================================
*/

int main() {
    int i, j;
    int num;

    //GET num
    printf("Enter num: ");
    scanf("%d", &num);

    //for every row
    for(i = 1; i <= num; i++) {

        //the spaces before numbers
        for(j = i; j < num; j++) {
            printf("  ");
        }

        //increase num --> 1 then 2 then 3 
        for(j = 1; j <= i; j++) {
            printf("%d ", j);
        }

        //decreasing nums on the sides 
        for(j = i - 1; j >= 1; j--) {
            printf("%d ", j);
        }

        //next line
        printf("\n");

    }

    return 0;
}