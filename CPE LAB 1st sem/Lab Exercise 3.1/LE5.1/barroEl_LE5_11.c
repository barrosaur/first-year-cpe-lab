/*
============================================================================
 FILE        : barroEl_LE5_11.c
 AUTHOR      : Ellaine Joyce Barro
 DESCRIPTION : This program gets the average of even numbers and product of odd numbers
 COPYRIGHT   : created
 REVISION HISTORY
 Date:              By: 	                    Description:
 10/01/24	        Ellaine Joyce Barro         Made the entire program
 10/03/24           Ellaine Joyce Barro         Documentation
============================================================================
*/

#include <stdio.h>

/*
============================================================================
 FUNCTION    : main
 DESCRIPTION : Computes the average of Even Numbers and the product of odd numbers
 ARGUMENTS   : None
 RETURNS     : int
               Program successful execution without errors
============================================================================
*/

int main() {
    int num, i;
    int evenCount = 0, sumEven = 0;
    int productOdd = 1, oddCount = 0;
    float averageEven;
    int inputStatus;

    // Loop to get 10 valid integers
    for (i = 1; i <= 10; i++) {
        // Input validation loop
        do {
            printf("Enter integer %d: ", i);
            inputStatus = scanf("%d", &num);

            // If input is not valid, clear the input buffer
            if (inputStatus != 1) {
                printf("Invalid input. Please enter an integer.\n");
                while (getchar() != '\n');  // Clear the input buffer
            }

        } while (inputStatus != 1);

        // Check if the number is even or odd
        if (num % 2 == 0) {
            evenCount++;
            sumEven += num;
        } else {
            oddCount++;
            productOdd *= num;
        }
    }

    printf("======================================================\n");

    // Calculate and print the average of even numbers
    if (evenCount > 0) {
        averageEven = (float)sumEven / evenCount;
        printf("Average of even numbers: %.2f\n", averageEven);
    } else {
        printf("There are no even numbers.\n");
    }

    // Print the product of odd numbers
    if (oddCount > 0) {
        printf("Product of odd numbers: %d\n", productOdd);
    } else {
        printf("There are no odd numbers.\n");
    }

    return 0;
}