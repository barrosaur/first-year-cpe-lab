/*
============================================================================
 FILE        : barroEl_LE7_12.c
 AUTHOR      : Ellaine Joyce A. Barro
 DESCRIPTION : Prompts user for a string and counts the consonants and vowels in the string
 COPYRIGHT   : created
 REVISION HISTORY
 Date:               By: 	                    Description:
 11/08/24	         Ellaine Joyce A. Barro     Made the entire program
============================================================================
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int checkChar(char ch);

/*
============================================================================
 FUNCTION    : main
 DESCRIPTION : Displays the number of consonants and vowels in the inputted string by the user
 ARGUMENTS   : void
 RETURNS     : int - Successful Program Execution
===========================================================================
*/
int main() {
    char str[100];
    int i, length, result;
    int vowelCount = 0, consonantCount = 0;

    printf("Enter a string: ");
    gets(str);

    length = strlen(str);

    for(i = 0; i < length; i++) {
        result = checkChar(str[i]);

        if(result == 1) {
            vowelCount++;
        } else if (result == 2) {
            consonantCount++;
        }
    }

    printf("\n==================================================================\n");

    printf("Consonant Count   : %d\n", consonantCount);
    printf("Vowel Count       : %d\n", vowelCount);

    return 0;
}

/*
============================================================================
 FUNCTION    : checkChar
 DESCRIPTION : Checks if characters in a string inputted by the user are vowels, consonants, or neither
 ARGUMENTS   : char ch   - character in the string inputted by the user
 RETURNS     : int flag  - 0, 1, 2 representing neither, vowel, or consonant respectively
===========================================================================
*/
int checkChar(char ch) {
    int flag;
    bool isVowel = (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U');
    bool isConsonant = ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));

    if (isVowel) {
        flag = 1;
    } else if(isConsonant) {
        flag = 2;
    } else {
        flag = 0;
    }

    return flag;
}