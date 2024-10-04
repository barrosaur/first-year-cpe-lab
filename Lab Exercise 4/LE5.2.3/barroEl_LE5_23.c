/*
============================================================================
 FILE        : barroEl_LE5_23.c
 AUTHOR      : Ellaine Joyce A. Barro
 DESCRIPTION : Fibonacci Series
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
 DESCRIPTION : Given the limit, display the fibonacci series
 ARGUMENTS   : none
 RETURNS     : int
 		       Successful code execution with no errors
===========================================================================
*/

int main() {
    //INITIALIZE variables
    int firstNum = 1, secondNum = 1, nextNum, i;
    int limit;
    char charInputCheck;

    //GET limit
    printf("Enter limit: ");

    while(scanf("%d", &limit) != 1 || limit < 1 ) {
        while((charInputCheck = getchar()) != '\n');
        printf("Invalid Input! Please enter a number greater than 0: ");
    }

    printf("========================================================================\n");

    printf("FIBONACCI SEQUENCE\n");

    //if limit is 1 then it should just return 1
    if(limit == 1) {
        printf("%d\n", firstNum);
        return 0;
    }

    //if the limit is not 1, then display the first and second number which is 1
    printf("%d %d ", firstNum, secondNum);

    //start indexing at 3 (1, 1, ...)
    for(i = 3; i<= limit; i++) {
        //COMPUTE nextNum to be the sum of firstNum and secondNum
        nextNum = firstNum + secondNum;
        //DISPLAY the next number
        printf("%d ", nextNum);
        //UPDATE firstNum and secondNum for the next iteration
        firstNum = secondNum;
        secondNum = nextNum;
    }

    printf("\n");

    return 0;
}