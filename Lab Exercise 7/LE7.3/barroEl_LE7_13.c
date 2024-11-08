/*
============================================================================
 FILE        : barroEl_LE7_13.c
 AUTHOR      : Ellaine Joyce A. Barro
 DESCRIPTION : Determines the longest of the 5 strings given by the user
 COPYRIGHT   : created
 REVISION HISTORY
 Date:               By: 	                    Description:
 11/08/24	         Ellaine Joyce A. Barro     Made the entire program
============================================================================
*/
#include <stdio.h>
#include <string.h>

int checkAndUpdateLongest(char currentStr[], char longestStr[], int maxLength);

/*
============================================================================
 FUNCTION    : main
 DESCRIPTION : Prompts user for 5 strings and displays output
 ARGUMENTS   : void
 RETURNS     : int - Successful Program Execution
===========================================================================
*/
int main() {
    char string[5][100];
    char longestStr[100] = "";
    int maxLength = 0, i;

    printf("Enter 5 strings.\n");

    for(i = 0; i < 5; i++) {
        printf("Enter String %d: ", i+1);
        gets(string[i]);

        maxLength = checkAndUpdateLongest(string[i], longestStr, maxLength);
    }

    printf("=======================================================================\n");
    printf("The longest string is \"%s\" with %d characters.\n", longestStr, maxLength);

    return 0;
}

/*
============================================================================
 FUNCTION    : checkAndUpdateLongest
 DESCRIPTION : Determines and updates the longest string and its length
 ARGUMENTS   : char currentStr[]   - current string iteration of the 5 strings
               char longestStr[]   - longest string
               int maxLength       - length of the longest string
 RETURNS     : int maxLength       - number of characters in the longest string
===========================================================================
*/
int checkAndUpdateLongest(char currentStr[], char longestStr[], int maxLength) {
    int length = strlen(currentStr);
    if(length > maxLength) {
        maxLength = length;
        strcpy(longestStr, currentStr);
    }

    return maxLength;
}