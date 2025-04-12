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
============================================================================
*/

int main() {
    //INITIALIZE variables
    unsigned long long firstNum = 1, secondNum = 1, nextNum, i;
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

    if (limit == 1) {
        // If limit is 1, only print the first number
        printf("%d\n", firstNum);
    } else {
        // If limit is greater than 2, print the first two numbers
        printf("%d %d ", firstNum, secondNum);

        // Continue the Fibonacci sequence from the 3rd number onward
        for (i = 3; i <= limit; i++) {
            // Compute the next number in the sequence
            nextNum = firstNum + secondNum;
            // Display the next number
            printf("%llu ", nextNum);
            // Update firstNum and secondNum for the next iteration
            firstNum = secondNum;
            secondNum = nextNum;
        }
        printf("\n");
    }


    return 0;
}