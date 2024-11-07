/*
============================================================================
 FILE        : barroEl_LE7_13.c
 AUTHOR      : Ellaine Joyce A. Barro
 DESCRIPTION : Given 5 strings, it displays the longest string
 COPYRIGHT   : created
 REVISION HISTORY
 Date:               By: 	                    Description:
 11/07/24	         Ellaine Joyce A. Barro     Made the entire program
============================================================================
*/

#include <stdio.h>
#include <string.h>

int findMaxLength(char str[], char longestStr[], int currentMaxLength);
void printLongestStr(char longestStr[], int maxLength);

/*
============================================================================
 FUNCTION    : main
 DESCRIPTION : Displays the longest string and its number of characters
 ARGUMENTS   : void
 RETURNS     : int - Successful Program Execution
===========================================================================
*/
int main() {
    char str[100];
    char longestStr[100];
    int maxLength = 0;
    int i;

    for (i = 1; i <= 5; i++) {
        printf("Enter String %d: ", i);
        gets(str);

        maxLength = findMaxLength(str, longestStr, maxLength);
    }

    printLongestStr(longestStr, maxLength);

    return 0;
}

/*
============================================================================
 FUNCTION    : findMaxLength
 DESCRIPTION : Finds the string with the maxiumum number of characters
 ARGUMENTS   : char str[] - string entered by the user
               char longestStr[100] - longest string
               int currentMaxLength - the number of characters of the longest string
 RETURNS     : int currentMaxLength - the string and the number of its characters
===========================================================================
*/
int findMaxLength(char str[], char longestStr[], int currentMaxLength) {
    if(strlen(str) > currentMaxLength) {
        strcpy(longestStr, str);
        return strlen(str);
    }
    return currentMaxLength;
}

void printLongestStr(char longestStr[], int maxLength) {
    printf("The longest string is %s with %d characters.\n", longestStr, maxLength);
}