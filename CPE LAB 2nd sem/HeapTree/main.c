#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void displayMenu();

int main()
{
    int choice;
    char ch;
    NODE *minRoot = NULL;
    NODE *maxRoot = NULL;

    INPUT input = inputModule();
    inputHandle(input.arr, input.size, &minRoot, &maxRoot);

    free(input.arr);

    while(1) {
        displayMenu();
        printf("Enter choice: ");
        if((scanf("%d%c", &choice, &ch)) == 2 && ch == '\n') {

            switch(choice) {
            case 1:
                appendNodeModule(&minRoot, &maxRoot);
                break;
            case 2:
                deleteNodeModule(&minRoot, &maxRoot);
                break;
            case 3:
                printf("Exiting...\n\n");
                freeTree(minRoot);
                freeTree(maxRoot);

                return 0;
            default:
                printf("invalid option!\n\n");
            }
        } else {
            printf("ERROR: choice is of type int!\n\n");
            clearInputBuffer();
        }
    }

    return 0;
}

void displayMenu() {
    printf("=== MAIN MENU ===\n");
    printf("[1] - Add node\n");
    printf("[2] - Delete node\n");
    printf("[3] - Exit\n");
}
