/*
============================================================================
 FILE        : barroEl_LE8_12.c
 AUTHOR      : Ellaine Joyce Barro
 DESCRIPTION : Searches for an element inside an array of elements
 COPYRIGHT   : created
 REVISION HISTORY
 Date:               By: 	                    Description:
 11/26/24	         Ellaine Joyce A. Barro     Made the entire program.
============================================================================
*/
#include <stdio.h>
int searchElement(int *arr, int size, int numSearch);
void clearInputBuffer(int input);
/*
============================================================================
 FUNCTION    : main
 DESCRIPTION : Gets the number of entries, inputs the number of each element, and displays results
 ARGUMENTS   : None 
 RETURNS     : int - successful program execution
===========================================================================
*/
int main() {
    int numOfEntries, searchNum, result;
    int i;
    char c;
    while (1) {
        printf("Enter number of entries: ");
        if((scanf("%d%c", &numOfEntries, &c)) == 2 && c == '\n') {
            break;
        } else {
            printf("Invalid input. Please enter an integer.\n");
            clearInputBuffer(numOfEntries);
        }
    }
    int arr[numOfEntries];
    for(i = 0; i < numOfEntries; i++) {
        while(1) {
            printf("Enter number %d: ", i + 1);
            if((scanf("%d%c", &arr[i], &c)) == 2 && c == '\n') {
                break;
            } else {
                printf("Invalid input. Please enter an integer.\n");
                clearInputBuffer(arr[i]);
                printf("\n");
            }
        }
    }
    printf("\n");
    while(1) {
        printf("Search data: ");
        if((scanf("%d%c", &searchNum, &c)) == 2 && c == '\n') {
            break;
        } else {
            printf("Invalid input. Please enter an integer.\n");
            clearInputBuffer(searchNum);
            printf("\n");
        }
    }
    result = searchElement(arr, numOfEntries, searchNum);
    if(result == -1) {
        printf("NOT FOUND\n");
    } else {
        printf("FOUND in Index %d\n", result);
    }
    return 0;
}
/*
============================================================================
 FUNCTION    : searchElement
 DESCRIPTION : Given an array pointer, size, and the number searched for, return the index of the element
 ARGUMENTS   : int *arr       - the array of numbers entered by the user
               int size       - the size of the array
               int numSearch  - the number/element being searched
 RETURNS     : int i or -1    - returns the index of a found element or -1 if not 
===========================================================================
*/
int searchElement(int *arr, int size, int numSearch) {
    int i;
    for(i = 0; i < size; i++) {
        if(*(arr + i) == numSearch) {
            return i; //return index if found
        } 
    }
    return -1; //not found
}
void clearInputBuffer(int input) {
    while((input = getchar()) != '\n');
}