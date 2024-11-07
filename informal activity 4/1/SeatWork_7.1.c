/*
============================================================================
 FILE        : SeatWork_7.1.c
 AUTHOR      : Ellaine Joyce A. Barro
 DESCRIPTION : It displays the count for a positive number, negative number, and zero
 COPYRIGHT   : created
 REVISION HISTORY
 Date:               By: 	                    Description:
 11/07/24	         Ellaine Joyce A. Barro     Made the entire program
============================================================================
*/
#include <stdio.h>

int checkNum(int num);  

/*
============================================================================
 FUNCTION    : main
 DESCRIPTION : Displays the number of negative numbers, positive numbers, and zero
 ARGUMENTS   : void
 RETURNS     : int - Successful Program Execution
===========================================================================
*/
int main() {
    int i, num[10];
    int positiveCount = 0, negativeCount = 0, zeroCount = 0;

    for (i = 0; i < 10; i++) { 
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num[i]);

        int result = checkNum(num[i]);

        if (result == 1) {
            zeroCount++;
        } else if (result == 2) {
            positiveCount++;
        } else {
            negativeCount++;
        }
    }

    printf("\n============================================================\n");

    printf("Positive number count : %d\n", positiveCount);
    printf("Negative number count : %d\n", negativeCount);
    printf("Zero count            : %d\n", zeroCount);
    return 0;
}

/*
============================================================================
 FUNCTION    : checkNum
 DESCRIPTION : checks whether the numbers entered by a user is positive, negative, or zero
 ARGUMENTS   : int num - numbers to check if positive, negative, or zero
 RETURNS     : int flag - it returns if a number is positive, negative, or zero
===========================================================================
*/
int checkNum(int num) {
    int flag;

    if (num == 0) {
        flag = 1;  
    } else if (num > 0) {
        flag = 2;  
    } else {
        flag = 3;  
    }

    return flag;
}