#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/* fix again; and tree height calculations */

int main(void) {
    INPUT input;
    NODE *root = NULL;
    char choice;

    do {
        input = inputModule();
        for (int i = 0; i < input.size; i++) {
            root = insert(root, input.arr[i]);
        }

        int totalHeight = calculateTreeHeight(root);
        int leftHeight = calculateLeftSubtreeHeight(root);
        int rightHeight = calculateRightSubtreeHeight(root);
        
        printf("\n");
        printf("\tMax No. of Levels: %d\n", totalHeight);
        printf("\tHeight of Left Subtree: %d\n", leftHeight + 1);
        printf("\tHeight of Right Subtree: %d\n", rightHeight + 1);
        printf("\t");
        breadthFirstTraversal(root);

        printf("Again [Y/N]? ");
        scanf(" %c", &choice);

        while(getchar() != '\n');

        free(input.arr);
        free(root);
        root = NULL;

    } while (choice == 'y' || choice == 'Y');

    printf("Exiting program...\n\n");
    return 0;
}