/*
============================================================================
 FILE        : barroEl_LE6_12.c
 AUTHOR      : Ellaine Joyce A. Barro
             : Mark Steven Tsai V. Go
 DESCRIPTION : Determines if the inputted character of the user is a consonant or a vowel or not
 COPYRIGHT   : created
 REVISION HISTORY
 Date:               By: 	                        Description:
 10/29/24	         Ellaine Joyce A. Barro         Made the entire program
                     Mark Steven Tsai V. Go     
============================================================================
*/

#include <stdio.h>
#include <stdbool.h>

bool isLetter (char ch);
bool isVowel (char ch);

 /*
============================================================================
 FUNCTION    : main
 DESCRIPTION : Executes the program
 ARGUMENTS   : None
 RETURNS     : int - successful program execution
===========================================================================
*/
int main() {
    char ch;
    bool isCharVowel, isCharLetter;

    printf("Enter a letter: ");
    scanf("%c", &ch);
    
    isCharVowel = isVowel(ch);
    isCharLetter = isLetter(ch);

    if (isCharLetter) {
        if (isCharVowel) {
            printf("VOWEL!");
        } else {
            printf("CONSONANT!");
        }
    } else {
        printf("INVALID INPUT!");
    }

    return 0;
}

/*
============================================================================
 FUNCTION    : isLetter
 DESCRIPTION : Checks if the inputted character is a valid letter
 ARGUMENTS   : char ch - this is the character inputted by the user
 RETURNS     : bool - it returns whether the inputted character is valid
===========================================================================
*/

bool isLetter(char ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

/*
============================================================================
 FUNCTION    : isVowel
 DESCRIPTION : Checks if the inputted valid character is a vowel
 ARGUMENTS   : char ch - this is the character inputted by the user
 RETURNS     : bool - it returns whether the valid inputted character is a vowel
===========================================================================
*/
bool isVowel(char ch) {
    return (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U');
}