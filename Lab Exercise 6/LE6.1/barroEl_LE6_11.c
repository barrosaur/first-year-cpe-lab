/*
============================================================================
 FILE        : barroEl_LE6_11.c
 AUTHOR      : Ellaine Joyce A. Barro
             : Mark Steven Tsai V. Go
 DESCRIPTION : Adds the last two integers of a given number
 COPYRIGHT   : created
 REVISION HISTORY
 Date:               By: 	                        Description:
 10/29/24	         Ellaine Joyce A. Barro         Made the entire program
                     Mark Steven Tsai V. Go     
============================================================================
*/

#include <stdio.h>

int extractFirstLSD (int num);
int extractSecondLSD (int num);
int sumDigits (int x, int y);

 /*
============================================================================
 FUNCTION    : main
 DESCRIPTION : Executes the program
 ARGUMENTS   : None
 RETURNS     : int - successful program execution
===========================================================================
*/
int main() {
    int num;
    int firstLastInteger, secondLastInteger, sum;

    do {
        printf("Enter a number: ");
        if (scanf("%d", &num) != 1 || num <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
            while (getchar() != '\n');  // Clear invalid input
            num = -1;  // Reset `num` to ensure the loop continues
        }
    } while (num <= 0);

    firstLastInteger = extractFirstLSD(num);
    secondLastInteger = extractSecondLSD(num);
    sum = sumDigits(firstLastInteger, secondLastInteger);

    printf("Sum           : %d + %d = %d\n", firstLastInteger, secondLastInteger, sum);
    printf("==============================================================\n");

    return 0;
}

 /*
============================================================================
 FUNCTION    : extractFirstLSD
 DESCRIPTION : Given a number, it extracts the first last digit of the number
 ARGUMENTS   : int num - this is the number inputted by the user
 RETURNS     : int - it returns the first last digit of the number
===========================================================================
*/
int extractFirstLSD(int num) {
    return num % 10;
}

 /*
============================================================================
 FUNCTION    : extractSecondLSD
 DESCRIPTION : Given a number, it extracts the second last digit of the number
 ARGUMENTS   : int num - this is the number inputted by the user
 RETURNS     : int - it returns the second last digit of the number
===========================================================================
*/

int extractSecondLSD(int num) {
    return ((num % 100) - (num % 10)) / 10;
}

 /*
============================================================================
 FUNCTION    : sumDigits
 DESCRIPTION : Adds the first and second last digit of a number
 ARGUMENTS   : int x - represents the first last digit of the number inputted by the user
             : int y - represents the second last digit of the number inputted by the user
 RETURNS     : int - sum of the first and second last digit of the number inputted by the user
===========================================================================
*/
int sumDigits (int x, int y) {
    return x + y;
}