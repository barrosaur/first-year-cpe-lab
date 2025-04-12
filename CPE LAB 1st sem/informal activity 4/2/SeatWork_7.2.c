/*
============================================================================
 FILE        : SeatWork_7.2.c
 AUTHOR      : Ellaine Joyce A. Barro
 DESCRIPTION : It displays a string backwards
 COPYRIGHT   : created
 REVISION HISTORY
 Date:               By: 	                    Description:
 11/07/24	         Ellaine Joyce A. Barro     Made the entire program
============================================================================
*/
#include <stdio.h>
#include <string.h>

void reverseString(char str[]);

/*
============================================================================
 FUNCTION    : main
 DESCRIPTION : Gets user input
 ARGUMENTS   : void
 RETURNS     : int - Successful Program Execution
===========================================================================
*/
int main() {
    char string[50];

    printf("Enter a string: ");
    gets(string);

    reverseString(string);

    return 0;
}

/*
============================================================================
 FUNCTION    : reverseString
 DESCRIPTION : Reverses the string entered by the user
 ARGUMENTS   : char str[] - String to reverse 
 RETURNS     : void - returns nothing
===========================================================================
*/
void reverseString(char str[]) {
    int length = strlen(str);

    for(int i = length - 1; i >= 0; i--) {
        printf("%c ", str[i]);
    }

    return;
}