/*
============================================================================
 FILE        : barroEl_LE8_13.c
 AUTHOR      : Ellaine Joyce Barro
 DESCRIPTION : Finds the maximum number inside an array
 COPYRIGHT   : created
 REVISION HISTORY
 Date:               By: 	                    Description:
 11/26/24	         Ellaine Joyce A. Barro     Made the entire program.
============================================================================
*/
#include <stdio.h>

void clearInputBuffer(int input);
int findMaxNum(int *arr, int n);

/*
============================================================================
 FUNCTION    : main
 DESCRIPTION : Gets the number of entries, integer values of each index of array, displays the maximum number number
 ARGUMENTS   : None 
 RETURNS     : int - successful program execution
===========================================================================
*/
int main() {
    int numOfEntries, result;
    int i;
    char c;

    while(1) {
        printf("Enter number of entries: ");
        if((scanf("%d%c", &numOfEntries, &c)) == 2 && c == '\n') {
            break;
        } else {
            printf("Invalid input. Please enter an integer.\n");
            clearInputBuffer(numOfEntries);
            printf("\n");
        }
    }

    int arr[numOfEntries];

    for(i = 0; i < numOfEntries; i++) {
        while(1) {
            printf("Enter number %d: ", i+1);
            if((scanf("%d%c", &arr[i], &c)) == 2 && c == '\n') {
                break;
            } else {
                printf("Invalid input. Please enter an integer.\n");
                clearInputBuffer(arr[i]);
                printf("\n");
            }
        }
    }

    result = findMaxNum(arr, numOfEntries);
    printf("\n");
    printf("Maximum Number: %d", result);

    return 0;
}

/*
============================================================================
 FUNCTION    : findMaxNum
 DESCRIPTION : finds the maximum number of an array
 ARGUMENTS   : int *arr - the array of elements being passed on
               int n    - array size
 RETURNS     : int max  - the maximum number of an array
===========================================================================
*/
int findMaxNum(int *arr, int n) {
    int max = arr[0]; // Initialize max to the first element
    int i;

    for (i = 1; i < n; i++) {
        if (arr[i] > max) { // Direct array indexing
            max = arr[i];
        }
    }
    return max;
}

void clearInputBuffer(int input) {
    while((input = getchar()) != '\n');
}