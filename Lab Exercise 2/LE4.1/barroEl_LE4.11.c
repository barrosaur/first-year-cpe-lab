/*
============================================================================
 FILE        : barroEl_LE4.11.c
 AUTHOR      : Ellaine Joyce Barro
 DESCRIPTION : This is a program where it checks whether user input is a consonant, vowel, or invalid
 COPYRIGHT   : created
 REVISION HISTORY
 Date:              By: 	                    Description:
 09/22/24	        Ellaine Joyce Barro         Made the entire program
============================================================================
*/

#include <stdio.h>

 /*
============================================================================
 FUNCTION    : main
 DESCRIPTION : Checks whether user input is a consonant, vowel, or invalid
 ARGUMENTS   : None
 RETURNS     : int
 		       Program successful execution without errors
===========================================================================
*/

int main() {

    char letter;

    //GET letter 
    printf("Enter letter: ");
    scanf("%c", &letter);

    //CHECK IF letter matches these conditions
    if (letter == 'A' || letter == 'a' ||
        letter == 'E' || letter == 'e' ||
        letter == 'I' || letter == 'i' ||
        letter == 'O' || letter == 'o' ||
        letter == 'U' || letter == 'u'
        ) {
        //IF letter is vowel
        //  DISPLAY "VOWEL!"
        printf("VOWEL!\n");

      //CHECK IF letter matches these condition
    } else if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <='Z')) {
        //IF match
        //  DISPLAY "CONSONANT!"
        printf("CONSONANT!\n");
    } else {
        //ELSE DISPLAY "INVALID INPUT"
        printf("INVALID INPUT!");
    }

    return 0;
}