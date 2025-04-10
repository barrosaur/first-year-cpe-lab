#include <stdio.h>
#include <stdbool.h>
#include "tree.h"

int main(void) {
    int choice;
    char ch;
    NODE *root = NULL;

    // get input first
    INPUT input = inputModule();

    // do the initial tree
    inputHandle(input.arr, input.size, &root);

    while(1) {
        displayMenu();
        printf("Enter choice: ");
        if((scanf("%d%c", &choice, &ch)) == 2 && ch == '\n') {

            switch(choice) {
                case 1:
                    addNodeModule(&root);
                    break;
                case 2:
                    deleteNodeModule(&root);
                    break;
                case 3:
                    searchNodeModule(&root);
                    break;
                case 4:
                    printf("Exiting...\n\n");
                    return 0;
                default:
                    printf("ERROR: invalid choice!\n\n");
            }

        } else {
            printf("ERROR: choice is of type int!\n\n");
            clearInputBuffer();
        }
    }

    freeTree(root);
    return 0;
}