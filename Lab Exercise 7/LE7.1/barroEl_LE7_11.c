/*
============================================================================
 FILE        : barroEl_LE7_11.c
 AUTHOR      : Ellaine Joyce A. Barro
 DESCRIPTION : Given an array of numbers, it displays the largest and smallest number
 COPYRIGHT   : created
 REVISION HISTORY
 Date:               By: 	                    Description:
 11/07/24	         Ellaine Joyce A. Barro     Made the entire program
============================================================================
*/
#include <stdio.h>

void displayNumbersEntered(int nums[]);
int findLargestNum(int nums[]);
int findSmallestNum(int nums[]);

/*
============================================================================
 FUNCTION    : main
 DESCRIPTION : Displays the numbers entered by the user, and the largest and smallest number
 ARGUMENTS   : void
 RETURNS     : int - Successful Program Execution
===========================================================================
*/
int main() {
    int nums[10];
    int i, largestNum = 0, smallestNum = 0;
    int validInput;

    for(i = 0; i < 10; i++) {
        do {
            printf("Enter number %d: ", i + 1);
            validInput = scanf("%d", &nums[i]);

            if(validInput != 1) {
                printf("Enter an integer.\n");
                while(getchar() != '\n');
            }
        } while(validInput != 1);
    }

    printf("\n================================================================\n");
    displayNumbersEntered(nums);

    largestNum = findLargestNum(nums);
    smallestNum = findSmallestNum(nums);

    printf("The largest number is   : %d\n", largestNum);
    printf("The smallest number is  : %d\n", smallestNum);

    return 0;
}

/*
============================================================================
 FUNCTION    : displayNumbersEntered
 DESCRIPTION : Displays the numbers entered by the user
 ARGUMENTS   : int nums[] - the array of numbers entered by the user
 RETURNS     : void
===========================================================================
*/
void displayNumbersEntered(int nums[]) {
    int i;
    printf("Numbers entered         : ");
    for(i = 0; i < 10; i++) {
        printf("%d ", nums[i]);
    }

    printf("\n");

    return;
}

/*
============================================================================
 FUNCTION    : findLargestNum
 DESCRIPTION : Finds the largest 
 ARGUMENTS   : void
 RETURNS     : int - Successful Program Execution
===========================================================================
*/

int findLargestNum(int nums[]) {
    int i;
    int largest = nums[0];

    for(i = 0; i < 10; i++) {
        if(nums[i] > largest) {
            largest = nums[i];
        }
    }

    return largest;
}

int findSmallestNum(int nums[]) {
    int i;
    int smallest = nums[0];

    for(i = 0; i < 10; i++) {
        if(nums[i] < smallest) {
            smallest = nums[i];
        }
    }

    return smallest;
}